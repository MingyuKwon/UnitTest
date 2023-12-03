#include <stdbool.h>
#include <stdint.h>

struct Motor {
	uint8_t moveForwardModule; //0일 때 정지, 그 외에엔 해당 속도로 이동 (단위: 1cm/s)
	bool rTurnModule; //true일 때 오른쪽으로 90도 회전
	bool lTurnModule; //true일 때 왼쪽으로 90도 회전
	bool cleanerPowerUpModule; //true일 때 Power Up, false일 때 Power Off
} m;

struct SensorInterface {
	bool rSensor; //우측 장애물 센서
	bool fSensor; //전방 장애물 센서
	bool lSensor; //좌측 장애물 센서
	bool dustSensor; //먼지 센서
} s; // 각 센서의 output wire와 연결

struct Checker {
	bool obstLocation[3]; // left, front, right
	bool dustExistence; // 먼지 여부
} c; //RVC가 작동하기 위해 센서값을 Checker에 저장

bool* detObstacle(bool* arr);
bool detDust();
void turnLeft();
void turnRight();
void moveForward();
void updateSensorSignal();
void powerUpCleaner();
void powerOffCleaner();

int TestMain() {
	while (true) {
		updateSensorSignal(); // Checker 모드

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
		else if (!c.obstLocation[1]) { // 전방에 장애물이 없어 직진 중일 때
			if (c.dustExistence) { // 만약 먼지가 있다면
				powerUpCleaner(); // 클리너 On
			}
			else {
				powerOffCleaner(); // 클리너 Off
			}
		}
	}

	return 0;
}

bool* detObstacle(bool* arr) {
	arr[0] = s.lSensor; // 좌측 장애물 센서값
	arr[1] = s.fSensor; // 전방 장애물 센서값
	arr[2] = s.rSensor; // 우측 장애물 센서값
	return arr;
}

bool detDust() {
	return s.dustSensor; // 먼지 감지 모듈 센서값
}

void turnLeft() {
	m.moveForwardModule = 0; // 전진 종료
	m.lTurnModule = true; // 좌회전 모듈 On
	powerOffCleaner(); // 전진 중에만 먼지 청소를 할 수 있으므로, 클리너 Off
	while (true) {
		if (!m.lTurnModule) { // 좌회전 모듈은 90도 회전 시 자동으로 종료되는 모듈
			return; // 회전이 종료될 때까지 기다린 후 return (Checker 모드 돌입)
		}
	}
}

void turnRight() {
	m.moveForwardModule = 0; // 전진 종료
	m.rTurnModule = true; // 우회전 모듈 On
	powerOffCleaner(); // 전진 중에만 먼지 청소를 할 수 있으므로, 클리너 Off
	while (true) {
		if (!m.rTurnModule) { // 우회전 모듈은 90도 회전 시 자동으로 종료되는 모듈
			return; // 회전이 종료될 때까지 기다린 후 return (Checker 모드 돌입)
		}
	}
}

void moveForward() {
	m.moveForwardModule = 30; // 30cm/s (0.3m/s)로 이동
	m.lTurnModule = false; // 좌회전 모듈 종료
	m.rTurnModule = false; // 우회전 모듈 종료
}

void updateSensorSignal() {
	// 하드웨어로부터 센서값을 받아옵니다
	bool arr[3];
	*c.obstLocation = detObstacle(arr); // 장애물 센서값 받아오기
	c.dustExistence = detDust(); // 먼지 센서값 받아오기
}

void powerUpCleaner() {
	m.cleanerPowerUpModule = true; // 클리너 모듈 On
}
void powerOffCleaner() {
	m.cleanerPowerUpModule = false; // 클리너 모듈 Off
}