#include "example.h"  // 테스트할 함수들이 정의된 헤더 파일

// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ 회전, 전진 작업 케이스↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
START_TEST(turnRight_test) // 우회전 작업이 성공적으로 진행 되는지 체크
{
    ck_assert_int_eq(turnRight(), 0);  
}
END_TEST

START_TEST(turnLeft_test)  // 좌회전 작업이 성공적으로 진행 되는지 체크
{ 
    ck_assert_int_eq(turnLeft(), 0); 
}
END_TEST

START_TEST(moveForward_test)  // 전진 작업이 성공적으로 진행 되는지 체크
{ 
    ck_assert_int_eq(moveForward(), 0); 
}
END_TEST

// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ 회전, 전진 작업 에러 케이스 ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

START_TEST(ErrorturnRight_test) // 우회전 작업에서 에러가 잘 나는지 확인
{
    m.isMotorError = true;
    ck_assert_int_eq(turnRight(), 1);  
}
END_TEST

START_TEST(ErrorturnLeft_test)  // 좌회전 작업이 에러가 잘 나는지 확인
{ 
    m.isMotorError = true;
    ck_assert_int_eq(turnLeft(), 1); 
}
END_TEST

START_TEST(ErrormoveForward_test)  // 전진 작업이 에러가 잘 나는지 확인
{ 
    m.isMotorError = true;
    ck_assert_int_eq(moveForward(), 1); 
}
END_TEST

// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 회전, 전진 작업 에러 케이스 ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 회전, 전진 작업 ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑



START_TEST(NormalMortor_test) // 이동 모터가 정상일 때 잘 움직이는지 확인
{
    m.isMotorError = false; // 모터 정상!!
    ck_assert_int_eq(moveForward(), 0); // 직진
    ck_assert_int_eq(turnRight(), 0);  // 오른쪽으로 돌았다가
    ck_assert_int_eq(moveForward(), 0); // 직진
    ck_assert_int_eq(turnLeft(), 0); // 왼쪽으로 돌았다가
    ck_assert_int_eq(moveForward(), 0); // 직진
}
END_TEST

START_TEST(ErrorMotor_test) // 이동 모터가 고장 났을 때 어떻게 움직이는지 확인
{
    m.isMotorError = true; // 모터 고장!!
    ck_assert_int_eq(moveForward(), 1); // 직진
    ck_assert_int_eq(turnRight(), 1);  // 오른쪽으로 돌았다가
    ck_assert_int_eq(moveForward(), 1); // 직진
    ck_assert_int_eq(turnLeft(), 1); // 왼쪽으로 돌았다가
    ck_assert_int_eq(moveForward(), 1); // 직진
}
END_TEST