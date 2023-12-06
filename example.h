#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct Motor {
	uint8_t moveForwardModule; //0일 때 정지, 그 외에엔 해당 속도로 이동 (단위: 1cm/s)
	bool rTurnModule; //true일 때 오른쪽으로 90도 회전
	bool lTurnModule; //true일 때 왼쪽으로 90도 회전
	int cleanerPowerUpModule; //1 때 Power Up, 2일때 터보 모드, 0일 때 Power Off
	bool isMotorError; // true이면 모터가 고장나서 조작이 안되는 상태, false 이면 정상
} m;

struct SensorInterface {
	int rSensor; //우측 장애물 센서  0 : 없음, 1 : 있음 , 2 : 에러
	int fSensor; //전방 장애물 센서  0 : 없음, 1 : 있음 , 2 : 에러
	int lSensor; //좌측 장애물 센서  0 : 없음, 1 : 있음 , 2 : 에러
	int dustSensor; //먼지 센서   0 : 없음, 1 : 있음 , 2 : 에러
} s; // 각 센서의 output wire와 연결

struct Checker {
	int obstLocation[3]; // left, front, right
	int dustExistence; // 먼지 여부
} c; //RVC가 작동하기 위해 센서값을 Checker에 저장


int MoveEvadingObstacle();

int detObstacle(int* arr);
int detDust(int* sensor);

int turnLeft();
int turnRight();
int moveForward();
int moveMotorStop();

int powerUpCleaner();
int powerOffCleaner(); 
int powerUpTurboCleaner();

int TestMain() {
	while (true) {
		if (m.moveForwardModule == 0) { // 전진 중이 아닐 경우
			if (!c.obstLocation[1]) { // 전방에 장애물이 없다면
				moveForward(); // 전진
			}
		}

		if (c.obstLocation[1] && !c.obstLocation[0]) { // 전방에 장애물이 있고 좌측에 장애물이 없을 때
			turnLeft();	// 좌회전 실행
		}
		else if (c.obstLocation[1] && c.obstLocation[0] && !c.obstLocation[2]) { // 전방, 좌측에 장애물이 있고 우측에 장애물이 없을 때
			turnRight(); // 우회전 실행
		}
		else if (c.obstLocation[1] && c.obstLocation[0] && c.obstLocation[2]) { // 전방, 좌측, 우측 모두 장애물이 있을 때
			turnLeft();
			turnLeft(); // 좌회전을 두 번 실행하여 180도 회전
		}


		if (!c.obstLocation[1]) { // 전방에 장애물이 없어 직진 중일 때
		
			if(m.isMotorError) // 만약 모터가 고장났다면
			{
				powerOffCleaner(); // 클리너 끄기
			}else // 모터가 정상이라면
			{
				if (c.dustExistence == 1) { // 만약 먼지가 있다면
					powerUpTurboCleaner(); // 클리너 터보
				}
				else if(c.dustExistence == 2) // 먼지 센서에 오류 생기면 
				{
					powerOffCleaner(); // 클리너 끄기
				}else{
					powerUpCleaner(); // 클리너 켜기
				}
			}
		}
	}

	powerOffCleaner(); 
	return 0;
}

void SetSensorForUnitTest(bool isTurnLeft)
{
	if(isTurnLeft)
	{
		s.rSensor = s.fSensor;
		s.fSensor = s.lSensor;
		s.lSensor = 0;

	}else
	{
		s.lSensor = s.fSensor ;
		s.fSensor = s.rSensor;
		s.rSensor = 0;
	}
}

int MoveEvadingObstacle()
{
	int detectArray[3];
	int returnValue = detObstacle(detectArray);

	if(returnValue == 2)
	{
		moveMotorStop();
		printf("장애물 감지 반환값 오류! 장애물 회피 동작 정지\n");
		return 1;
	}else 
	{
		int checkState = 0; // 작업이 정상적으로 이뤄 젔는지 확인
		if(detectArray[1] == 0) // 만약 전방에 장애물이 없는 경우
		{
			checkState += moveForward();
		}else if(detectArray[0] == 0) // 전방에 장애물 있고, 좌측에 장애물이 없는 경우
		{
			checkState += turnLeft();
			checkState += moveForward();
		}else if(detectArray[2] == 0) // 전방, 좌측에 장애물 있고, 우측에 장애물이 없는 경우
		{
			checkState += turnRight();
			checkState += moveForward();
		}else // 전방, 좌측, 우측 모두 장애물이 있는 경우
		{
			checkState += turnLeft();
			checkState += turnLeft();
			checkState += moveForward();
		}

		return checkState == 0 ? 0 : 1;
	}



	for(int i=0; i < 5; i++)  
	{
		if(m.isMotorError) 
		{
			moveMotorStop();
			printf("모터 고장! 직진 정지\n");
			return 1;
		}

		printf("---------직진 과정---------\n");

		int returnValue = detObstacle(detectArray);

		if(returnValue == 2)
		{
			moveMotorStop();
			printf("장애물 감지 반환값 오류! 직진 정지\n");
			return 1;
		}else if(detectArray[1] == 1)
		{
			moveMotorStop();
			printf("전방에 장애물 존재. 직진 정지\n");
			return 0;
		}

		printf("직진 하는 중....\n");
		printf("---------직진 과정---------\n");

	}
	printf("직진 마침\n");

	moveMotorStop(); // 모터 정지
	return 0;
}

int detObstacle(int* arr) {
	arr[0] = s.lSensor; // 좌측 장애물 센서값
	if(arr[0] == 2) 
	{
		printf("좌측 센서 오류 감지\n");
	}else if(arr[0] == 1)
	{
		printf("좌측 센서 장애물 감지\n");
	}else
	{
		printf("좌측 장애물 없음\n");
	}

	arr[1] = s.fSensor; // 전방 장애물 센서값
	if(arr[1] == 2) 
	{
		printf("전방 센서 오류 감지\n");
	}else if(arr[1] == 1)
	{
		printf("전방 센서 장애물 감지\n");
	}else
	{
		printf("전방 장애물 없음\n");
	}

	arr[2] = s.rSensor; // 우측 장애물 센서값
	if(arr[2] == 2) 
	{
		printf("우측 센서 오류 감지\n");
	}else if(arr[2] == 1)
	{
		printf("우측 센서 장애물 감지\n");
	}else
	{
		printf("우측 장애물 없음\n");
	}

	if(arr[0] == 2 || arr[1] == 2 || arr[2] == 2) 
	{
		printf("센서 오류 감지, 오류 반환\n");
		return 1; // 센서 중 고장난게 있으면 에러 표시 띄움
	}
	
	return 0;
}

int detDust(int* sensor) {
	*sensor = s.dustSensor; // 먼지 감지 모듈 센서값

	if(s.dustSensor == 2) 
	{
		printf("먼지 탐지 센서 오류 감지 , 오류 반환\n");
		return 1;
	}else if(s.dustSensor == 1)
	{
		printf("먼지 탐지 센서 장애물 감지\n");
	}else
	{
		printf("먼지 탐지 장애물 없음\n");
	}

	return 0;

}

int turnLeft() {
	moveMotorStop(); // 모터 정지
	m.lTurnModule = true; // 좌회전 모듈 On

	// 좌회전 모듈은 90도 회전 시 자동으로 종료되는 모듈
	for(int i=0; i<3; i++)  
	{
		if(m.isMotorError) 
		{
			m.lTurnModule = false;
			printf("모터 고장! 좌회전 정지\n");
			return 1;
		}
		printf("좌회전 하는 중....\n");
	}

	printf("좌회전 마침\n");
	SetSensorForUnitTest(true);
	moveMotorStop(); // 모터 정지


	// 회전이 종료될 때까지 기다린 후 return (Checker 모드 돌입)
	m.lTurnModule = false;
	return 0;
}

int turnRight() {
	moveMotorStop(); // 모터 정지

	m.rTurnModule = true; // 좌회전 모듈 On

	// 우회전 모듈은 90도 회전 시 자동으로 종료되는 모듈
	for(int i=0; i<3; i++)  
	{
		if(m.isMotorError) 
		{
			m.rTurnModule = false;
			printf("모터 고장! 우회전 정지\n");
			return 1;
		}
		printf("우회전 하는 중....\n");
	}
	printf("우회전 마침\n");
	SetSensorForUnitTest(false);
	moveMotorStop(); // 모터 정지


	// 회전이 종료될 때까지 기다린 후 return (Checker 모드 돌입)
	m.rTurnModule = false;
	return 0;
}

int moveForward() {
	m.lTurnModule = false; // 좌회전 모듈 종료
	m.rTurnModule = false; // 우회전 모듈 종료

	int detectArray[3];
	m.moveForwardModule = 30; // 30cm/s (0.3m/s)로 이동

	for(int i=0; i < 5; i++)  
	{
		if(m.isMotorError) 
		{
			moveMotorStop();
			printf("모터 고장! 직진 정지\n");
			return 1;
		}

		int returnValue = detObstacle(detectArray);

		if(returnValue == 2)
		{
			moveMotorStop();
			printf("장애물 감지 반환값 오류! 직진 정지\n");
			return 1;
		}else if(detectArray[1] == 1)
		{
			moveMotorStop();
			printf("전방에 장애물 존재. 직진 정지\n");
			return 0;
		}

		printf("직진 하는 중....\n");
	}
	printf("직진 마침\n");

	moveMotorStop(); // 모터 정지
	return 0;
}


int moveMotorStop() {
	m.moveForwardModule = 0; // 모터 정지
	printf("정지 상태 돌입\n");
	return 0;
}


int powerUpCleaner() {
	if(m.isMotorError) 
	{
		printf(" 모터 고장! 먼지 흡입 종료\n");
		powerOffCleaner();
		return 1;
	}

	m.cleanerPowerUpModule = 1; // 클리너 모듈 On
	printf(" 청소기 모터 On\n");
	return 0;

}

int powerUpTurboCleaner() {
	if(m.isMotorError) 
	{
		printf(" 모터 고장! 먼지 흡입 종료\n");
		powerOffCleaner();
		return 1;
	}

	m.cleanerPowerUpModule = 2; // 클리너 모듈 터보로 변경
	printf(" 청소기 모터 터보 모드\n");
	return 0;
}

int powerOffCleaner() {
	m.cleanerPowerUpModule = 0; // 클리너 모듈 Off
	printf(" 청소기 모터 Off\n");
	return 0;
}
