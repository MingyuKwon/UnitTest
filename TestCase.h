#include "example.h"  // 테스트할 함수들이 정의된 헤더 파일
#include <check.h>


// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ 회전, 전진 작업 케이스↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
START_TEST(turnRight_test) // 우회전 작업이 성공적으로 진행 되는지 체크
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓우회전 작업이 정상적인지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상인 상황===\n");
    m.isMotorError = false;
    ck_assert_int_eq(turnRight(), 0); 
    printf("===모터 고장인 상황===\n");
    m.isMotorError = true;
    ck_assert_int_eq(turnRight(), 1); 
    
}
END_TEST

START_TEST(turnLeft_test)  // 좌회전 작업이 성공적으로 진행 되는지 체크
{ 
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓좌회전 작업이 정상적인지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상인 상황===\n");
    m.isMotorError = false;
    ck_assert_int_eq(turnLeft(), 0); 
    printf("===모터 고장인 상황===\n");
    m.isMotorError = true;
    ck_assert_int_eq(turnLeft(), 1); 
}
END_TEST

START_TEST(moveForward_test)  // 전진 작업이 성공적으로 진행 되는지 체크
{ 
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓전진 작업이 정상적인지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상인 상황===\n");
    m.isMotorError = false;
    ck_assert_int_eq(moveForward(), 0); 
    printf("===모터 고장인 상황===\n");
    m.isMotorError = true;
    ck_assert_int_eq(moveForward(), 1); 
}
END_TEST
// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 회전, 전진 작업 ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ 먼지 흡입 케이스↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
START_TEST(powerUpCleanerTest) // 먼지 흡입이 정상적을 되는지 확인
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓먼지 흡입이 정상적을 되는지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상인 상황===\n");
    m.isMotorError = false;
    ck_assert_int_eq(powerUpCleaner(), 0);  
    printf("===모터 고장인 상황===\n");
    m.isMotorError = true;
    ck_assert_int_eq(powerUpCleaner(), 1);  
}
END_TEST

START_TEST(powerOffCleanerTest)  // 먼지 흡입이 정상적으로 꺼지는지 확인
{ 
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓먼지 흡입이 정상적으로 꺼지는지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상인 상황===\n");
    m.isMotorError = false;
    ck_assert_int_eq(powerOffCleaner(), 0); 
    printf("===모터 고장인 상황===\n");
    m.isMotorError = true;
    ck_assert_int_eq(powerOffCleaner(), 0); 
}
END_TEST

START_TEST(powerUpTurboCleanerTest)  // 먼지 흡입을 터보로 잘 할 수 있는지 확인
{ 
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓먼지 흡입을 터보로 잘 할 수 있는지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상인 상황===\n");
    m.isMotorError = false;
    ck_assert_int_eq(powerUpTurboCleaner(), 0); 
    printf("===모터 고장인 상황===\n");
    m.isMotorError = true;
    ck_assert_int_eq(powerUpTurboCleaner(), 1); 
}
END_TEST

// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 먼지 흡입 케이스 ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

START_TEST(MoveRotateTest1) // 이동 모터가 정상일 때 잘 움직이는지 확인
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓장애물 없을 때 이동, 회전 관련 모터 정상 작동 시나리오 1↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상===\n");
    m.isMotorError = false; // 모터 정상!!
    printf("=1. 직진=\n");
    ck_assert_int_eq(moveForward(), 0); // 직진
    printf("=2. 우회전=\n");
    ck_assert_int_eq(turnRight(), 0);  // 오른쪽으로 돌았다가
    printf("=3. 직진=\n");
    ck_assert_int_eq(moveForward(), 0); // 직진
    printf("=4. 좌회전=\n");
    ck_assert_int_eq(turnLeft(), 0); // 왼쪽으로 돌았다가
    printf("=5. 직전=\n");
    ck_assert_int_eq(moveForward(), 0); // 직진
}
END_TEST

START_TEST(MoveRotateTest2) // 이동 모터가 고장 났을 때 어떻게 움직이는지 확인
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓이동, 회전 관련 모터 에러 작동 시나리오 1↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상===\n");
    m.isMotorError = false; // 모터 정상!!
    printf("=1. 직진=\n");
    ck_assert_int_eq(moveForward(), 0); // 직진
    printf("=2. 우회전=\n");
    ck_assert_int_eq(turnRight(), 0);  // 오른쪽으로 돌았다가
    printf("===모터 고장 !!!===\n");
    m.isMotorError = true;
    printf("=3. 직진=\n");
    ck_assert_int_eq(moveForward(), 1); // 직진
    printf("=4. 좌회전=\n");
    ck_assert_int_eq(turnLeft(), 1); // 왼쪽으로 돌았다가
    printf("=5. 직전=\n");
    ck_assert_int_eq(moveForward(), 1); // 직진
}
END_TEST

START_TEST(MoveRotateObstacleTest1) // 이동 모터가 정상일 때 잘 움직이는지 확인
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓전방에 장애물 있을 때 이동, 회전 관련 모터 정상 작동 시나리오 1↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===모터 정상===\n");
    m.isMotorError = false; // 모터 정상!!
    printf("=1. 직진=\n");
    ck_assert_int_eq(moveForward(), 0); // 직진
    printf("=2. 우회전=\n");
    ck_assert_int_eq(turnRight(), 0);  // 오른쪽으로 
    printf("===전방 쟁애물 감지!!!===\n");
    s.fSensor = 1;
    printf("=3. 직진=\n");
    ck_assert_int_eq(moveForward(), 0); // 직진
    printf("=4. 좌회전=\n");
    ck_assert_int_eq(turnLeft(), 0); // 왼쪽으로 돌았다가
    printf("===좌회전 후에 장애물 없어짐!!!===\n");
    s.fSensor = 0;
    printf("=5. 직전=\n");
    ck_assert_int_eq(moveForward(), 0); // 직진
}
END_TEST

// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ 센서 감지 케이스↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
START_TEST(detDustTest)  // 먼지 탐지가 정상적인지 확인
{ 
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓먼지 탐지가 정상적인지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("===먼지 전방에 있는 상황===\n");
    s.dustSensor = 1;
    ck_assert_int_eq(detDust(&(c.dustExistence)), 1); 
    printf("===먼지 전방에 없는 상황===\n");
    s.dustSensor = 0;
    ck_assert_int_eq(detDust(&(c.dustExistence)), 0); 
    printf("===먼지 샌서 오류 상황===\n");
    s.dustSensor = 2;
    ck_assert_int_eq(detDust(&(c.dustExistence)), 2); 
}
END_TEST

START_TEST(rightSensorTest)  // 우측 장애물 탐지가 정상적인지 확인
{ 
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓우측 장애물 탐지가 정상적인지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 0;

    printf("===우측에 장애물 있는 상황===\n");
    s.rSensor = 1;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 
    printf("===우측에 장애물 없는 상황===\n");
    s.rSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 
    printf("===우측 장애물 센서 고장 상황===\n");
    s.rSensor = 2;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1); 
}
END_TEST

START_TEST(leftSensorTest)  // 좌측 장애물 탐지가 정상적인지 확인
{ 
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓좌측 장애물 탐지가 정상적인지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");

    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 0;

    printf("===좌측에 장애물 있는 상황===\n");
    s.lSensor = 1;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 
    printf("===좌측에 장애물 없는 상황===\n");
    s.lSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 
    printf("===좌측 장애물 센서 고장 상황===\n");
    s.lSensor = 2;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1); 
}
END_TEST

START_TEST(forwardSensorTest)  // 전방 장애물 탐지가 정상적인지 확인
{ 
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓전방 장애물 탐지가 정상적인지 확인↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 0;

    printf("===전방에 장애물 있는 상황===\n");
    s.fSensor = 1;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 
    printf("===전방에 장애물 없는 상황===\n");
    s.fSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 
    printf("===전방 장애물 센서 고장 상황===\n");
    s.fSensor = 2;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1); 
}
END_TEST

START_TEST(NormaldetObstacleTest) // 센서 탐지가 정상적인지 확인
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓장애물 센서가 정상인 경우의 테스트들↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");

    printf("===전방, 우측, 좌측에 장애물 없는 상황===\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0);

    printf("===전방, 좌측에 장애물 없고 우측에 장애물 있는 상황===\n");
    s.rSensor = 1;
    s.fSensor = 0;
    s.lSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0);

    printf("===우측, 좌측에 장애물 없고 전방에 장애물 있는 상황===\n");
    s.rSensor = 0;
    s.fSensor = 1;
    s.lSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0);

    printf("===우측, 전방에 장애물 없고 좌측에 장애물 있는 상황===\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 1;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 

    printf("===전방에 장애물 없고 우측, 좌측에 장애물 있는 상황===\n");
    s.rSensor = 1;
    s.fSensor = 0;
    s.lSensor = 1;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0);

    printf("===우측에 장애물 없고 전방, 좌측에 장애물 있는 상황===\n");
    s.rSensor = 0;
    s.fSensor = 1;
    s.lSensor = 1;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0);

    printf("===좌측에 장애물 없고 우측, 전방에 장애물 있는 상황===\n");
    s.rSensor = 1;
    s.fSensor = 1;
    s.lSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 

    printf("=== 우측, 좌측, 전방에 장애물 있는 상황===\n");
    s.rSensor = 1;
    s.fSensor = 1;
    s.lSensor = 1;
    ck_assert_int_eq(detObstacle(c.obstLocation), 0); 
}
END_TEST

START_TEST(ErrordetObstacleTest) // 센서 탐지가 정상적인지 확인
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓장애물 센서가 고장난 경우의 테스트들↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");

    printf("===전방, 좌측 센서 정상이고 우측센서가 오류난 상황===\n");
    s.rSensor = 2;
    s.fSensor = 0;
    s.lSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1);

    printf("===우측, 좌측 센서 정상이고 전방센서가 오류난 상황===\n");
    s.rSensor = 0;
    s.fSensor = 2;
    s.lSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1);

    printf("===우측, 전방 센서 정상이고 좌측센서가 오류난 상황===\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 2;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1); 

    printf("===전방 센서 정상이고 우측, 좌측센서가 오류난 상황===\n");
    s.rSensor = 2;
    s.fSensor = 0;
    s.lSensor = 2;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1);

    printf("===우측 센서 정상이고 전방, 좌측센서가 오류난 상황===\n");
    s.rSensor = 0;
    s.fSensor = 2;
    s.lSensor = 2;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1);

    printf("===좌측 센서 정상이고 우측, 전방센서가 오류난 상황===\n");
    s.rSensor = 2;
    s.fSensor = 2;
    s.lSensor = 0;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1); 

    printf("=== 우측, 좌측, 전방센서가 오류난 상황===\n");
    s.rSensor = 2;
    s.fSensor = 2;
    s.lSensor = 2;
    ck_assert_int_eq(detObstacle(c.obstLocation), 1); 
}
END_TEST


START_TEST(checkDustMotorTest) // 먼지 감지하고 흡입 모터를 조절하는 테스트
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓먼지 감지하고 흡입 모터를 조절하는 테스트↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");

    printf("===먼지 존재하는 상황===\n");
    s.dustSensor = 1;
    ck_assert_int_eq(checkDustAndMotor(), 0);
    printf("===먼지 없는 상황===\n");
    s.dustSensor = 0;
    ck_assert_int_eq(checkDustAndMotor(), 0);
    printf("===먼지 센서 고장난 상황===\n");
    s.dustSensor = 2;
    ck_assert_int_eq(checkDustAndMotor(), 1);
}
END_TEST

START_TEST(MoveEvadingObstacleTest) // 장애물 회피 Use Case 테스트
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓장애물 감지와, 움직임의 방향을 정하고 움직이는 것이 동시에 일어 나는↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");

    printf("===우측에 장애물 존재하는 상황===\n");
    s.rSensor = 1;
    s.fSensor = 0;
    s.lSensor = 0;
    ck_assert_int_eq(MoveEvadingObstacle(), 0);

    printf("===좌측에 장애물 존재하는 상황===\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 1;
    ck_assert_int_eq(MoveEvadingObstacle(), 0);

    printf("===전방에 장애물 존재하는 상황===\n");
    s.rSensor = 0;
    s.fSensor = 1;
    s.lSensor = 0;
    ck_assert_int_eq(MoveEvadingObstacle(), 0);

    printf("===전방 우측에 장애물 존재하는 상황===\n");
    s.rSensor = 1;
    s.fSensor = 1;
    s.lSensor = 0;
    ck_assert_int_eq(MoveEvadingObstacle(), 0);

    printf("===전방 좌측에 장애물 존재하는 상황===\n");
    s.rSensor = 0;
    s.fSensor = 1;
    s.lSensor = 1;
    ck_assert_int_eq(MoveEvadingObstacle(), 0);

    printf("===우측, 좌측에 장애물 존재하는 상황===\n");
    s.rSensor = 1;
    s.fSensor = 0;
    s.lSensor = 1;
    ck_assert_int_eq(MoveEvadingObstacle(), 0);

    printf("===우측, 좌측, 전방 모두에 장애물 존재하는 상황===\n");
    s.rSensor = 1;
    s.fSensor = 1;
    s.lSensor = 1;
    ck_assert_int_eq(MoveEvadingObstacle(), 0);


}
END_TEST

START_TEST(MoveEvadingErrorObstacleTest) // 장애물 회피 Use Case 중간에 모터 고장나는 테스트
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓장애물 감지와, 움직임의 방향을 정하고 움직이는 것이 동시에 일어 나고, 모터 고장난 상황↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");

    m.isMotorError = true;
    printf("===우측에 장애물 존재하고 모터 고장난 상황===\n");
    s.rSensor = 1;
    s.fSensor = 0;
    s.lSensor = 0;
    ck_assert_int_eq(MoveEvadingObstacle(), 1);

    printf("===좌측에 장애물 존재하고 모터 고장난 상황===\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 1;
    ck_assert_int_eq(MoveEvadingObstacle(), 1);

    printf("===전방에 장애물 존재하고 모터 고장난 상황===\n");
    s.rSensor = 0;
    s.fSensor = 1;
    s.lSensor = 0;
    ck_assert_int_eq(MoveEvadingObstacle(), 1);

    printf("===전방 우측에 장애물 존재하고 모터 고장난 상황===\n");
    s.rSensor = 1;
    s.fSensor = 1;
    s.lSensor = 0;
    ck_assert_int_eq(MoveEvadingObstacle(), 1);

    printf("===전방 좌측에 장애물 존재하고 모터 고장난 상황===\n");
    s.rSensor = 0;
    s.fSensor = 1;
    s.lSensor = 1;
    ck_assert_int_eq(MoveEvadingObstacle(), 1);

    printf("===우측, 좌측에 장애물 존재하고 모터 고장난 상황===\n");
    s.rSensor = 1;
    s.fSensor = 0;
    s.lSensor = 1;
    ck_assert_int_eq(MoveEvadingObstacle(), 1);

    printf("===우측, 좌측, 전방 모두에 장애물 존재하고 모터 고장난 상황===\n");
    s.rSensor = 1;
    s.fSensor = 1;
    s.lSensor = 1;
    ck_assert_int_eq(MoveEvadingObstacle(), 1);


}
END_TEST




START_TEST(cleanRoomByRVCTest) // 방을 꼼꼼히 치우는 테스트 케이스1
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓방을 꼼꼼히 치우는 테스트 케이스1↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("=1. 우측 X , 전방 X , 좌측 X , 먼지 X =\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 0;
    s.dustSensor = 0;
    ck_assert_int_eq(CleanRoom(), 0);

    printf("=2. 우측 X , 전방 0 , 좌측 X , 먼지 X =\n");
    s.rSensor = 0;
    s.fSensor = 1;
    s.lSensor = 0;
    s.dustSensor = 0;
    ck_assert_int_eq(CleanRoom(), 0);

    printf("=3. 우측 X , 전방 0 , 좌측 0 , 먼지 0 =\n");
    s.rSensor = 0;
    s.fSensor = 1;
    s.lSensor = 1;
    s.dustSensor = 1;
    ck_assert_int_eq(CleanRoom(), 0);

    printf("=4. 우측 0 , 전방 X , 좌측 0 , 먼지 X =\n");
    s.rSensor = 1;
    s.fSensor = 0;
    s.lSensor = 1;
    s.dustSensor = 0;
    ck_assert_int_eq(CleanRoom(), 0);

    printf("=5. 우측 0 , 전방 0 , 좌측 0 , 먼지 0 =\n");
    s.rSensor = 1;
    s.fSensor = 1;
    s.lSensor = 1;
    s.dustSensor = 1;
    ck_assert_int_eq(CleanRoom(), 0);
}
END_TEST


START_TEST(cleanRoomErrorByRVCTest) // 방을 꼼꼼히 치우는 테스트 케이스2
{
    printf("\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓방을 꼼꼼히 치우는 테스트 케이스2 에러 포함↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
    printf("=1. 우측 X , 전방 X , 좌측 X , 먼지 X =\n");
    s.rSensor = 0;
    s.fSensor = 0;
    s.lSensor = 0;
    s.dustSensor = 0;
    ck_assert_int_eq(CleanRoom(), 0);

    printf("=2. 우측 Error , 전방 0 , 좌측 X , 먼지 X =\n");
    s.rSensor = 2;
    s.fSensor = 1;
    s.lSensor = 0;
    s.dustSensor = 0;
    ck_assert_int_eq(CleanRoom(), 1);

    printf("=3. 우측 Error , 전방 Error , 좌측 0 , 먼지 0 =\n");
    s.rSensor = 2;
    s.fSensor = 2;
    s.lSensor = 1;
    s.dustSensor = 1;
    ck_assert_int_eq(CleanRoom(), 1);

    printf("=4. 우측 0 , 전방 X , 좌측 0 , 먼지 Error =\n");
    s.rSensor = 1;
    s.fSensor = 0;
    s.lSensor = 1;
    s.dustSensor = 2;
    ck_assert_int_eq(CleanRoom(), 1);

    printf("=5. 우측 0 , 전방 Error , 좌측 0 , 먼지 Error =\n");
    s.rSensor = 1;
    s.fSensor = 2;
    s.lSensor = 1;
    s.dustSensor = 2;
    ck_assert_int_eq(CleanRoom(), 1);
}
END_TEST



// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 센서 감지 케이스 ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


//--------------------센서 시나리오-----------------------------
Suite *detDustScenario(void) // 먼지 감지를 제대로 하는지 검사하는 시나리오
{
    Suite *s = suite_create("\n--detDustScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, detDustTest);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *detObstacleScenario(void) // 장애물 감지를 제대로 하는지 검사하는 시나리오
{
    Suite *s = suite_create("\n--detObstacleScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, rightSensorTest);
    tcase_add_test(tc_core, leftSensorTest);
    tcase_add_test(tc_core, forwardSensorTest);
    tcase_add_test(tc_core, NormaldetObstacleTest);
    tcase_add_test(tc_core, ErrordetObstacleTest);
    suite_add_tcase(s, tc_core);
    return s;
}

//--------------------움직임 시나리오-----------------------------
Suite *LeftRightForwardScenario(void) // 전진, 우회전, 좌회전을 제대로 하는지 검사하는 시나리오
{
    Suite *s = suite_create("\n--LeftRightForwardScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, turnLeft_test);
    tcase_add_test(tc_core, turnRight_test);
    tcase_add_test(tc_core, moveForward_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *MoveRotateScenario(void) // 장애물 없을 때 전진, 우회전 , 좌회전등이 차례대로 명령되면 제대로 움직이는지 검사하는 시나리오
{
    Suite *s = suite_create("\n--MoveRotateScenario1--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, MoveRotateTest1);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *MoveRotateObstacleScenario(void) // 장애물 있을 떄 전진, 우회전 , 좌회전등이 차례대로 명령되면 제대로 움직이는지 검사하는 시나리오
{
    Suite *s = suite_create("\n--MoveRotateObstacleScenario1--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, MoveRotateObstacleTest1);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *MoveRotateErrorScenario(void) // 전진, 우회전 , 좌회전등이 차례대로 명령되다 모터가 고장날 때 검사하는 시나리오
{
    Suite *s = suite_create("\n--MoveRotateScenario2--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, MoveRotateTest2);
    suite_add_tcase(s, tc_core);
    return s;
}

//--------------------흡입 시나리오-----------------------------

Suite *powerUpTurboOffCleanerScenario(void) // 흡입, 터보 흡입, 흡입 중지를 제대로 하는지 검사하는 시나리오
{
    Suite *s = suite_create("\n--powerUpTurboOffCleanerScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, powerUpCleanerTest);
    tcase_add_test(tc_core, powerUpTurboCleanerTest);
    tcase_add_test(tc_core, powerOffCleanerTest);
    suite_add_tcase(s, tc_core);
    return s;
}

//--------------------종합 시나리오-----------------------------

Suite *CombineScenario(void) // 센서와 각종 모터의 종합이 잘 움직이는지 확인하는 시나리오
{
    Suite *s = suite_create("\n--CombineScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, checkDustMotorTest);
    tcase_add_test(tc_core, MoveEvadingObstacleTest);
    tcase_add_test(tc_core, MoveEvadingErrorObstacleTest);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *CleanRoomScenario(void) // 최종적으로 잘 움직이는지 확인하는 시나리오
{
    Suite *s = suite_create("\n--CleanRoomScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, cleanRoomByRVCTest);
    tcase_add_test(tc_core, cleanRoomErrorByRVCTest);
    suite_add_tcase(s, tc_core);
    return s;
}