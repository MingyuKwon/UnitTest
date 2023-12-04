#include "example.h"  // 테스트할 함수들이 정의된 헤더 파일
#include <check.h>


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


// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ 먼지 흡입 케이스↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
START_TEST(powerUpCleanerTest) // 먼지 흡입이 정상적을 되는지 확인
{
    ck_assert_int_eq(powerUpCleaner(), 0);  
}
END_TEST

START_TEST(powerOffCleanerTest)  // 먼지 흡입이 정상적으로 꺼지는지 확인
{ 
    ck_assert_int_eq(powerOffCleaner(), 0); 
}
END_TEST

START_TEST(powerUpTurboCleanerTest)  // 먼지 흡입을 터보로 잘 할 수 있는지 확인
{ 
    ck_assert_int_eq(powerUpTurboCleaner(), 0); 
}
END_TEST

// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ 먼지 흡입 에러 케이스 ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

START_TEST(ErrorpowerUpCleanerTest) // 먼지 흡입이 모터가 고장나면 에러를 내는지 확인
{
    m.isMotorError = true;
    ck_assert_int_eq(powerUpCleaner(), 1);   
}
END_TEST

START_TEST(ErrorpowerOffCleanerTest)  // 먼지 흡입 정지가 모터가 고장나도 성공적으로 진행이 되는지 확인
{ 
    m.isMotorError = true;
    ck_assert_int_eq(powerOffCleaner(), 0); 
}
END_TEST

START_TEST(ErrorpowerUpTurboCleanerTest)  // 먼지 흡입 터보가 모터가 고장나면 에러를 내는지 확인
{ 
    m.isMotorError = true;
    ck_assert_int_eq(powerUpTurboCleaner(), 1);  
}
END_TEST

// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 먼지 흡입 작업 에러 케이스 ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑


// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 먼지 흡입 케이스 ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑




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

//------------------------------------------------------------

Suite *TurnLeftScenario(void)
{
    Suite *s = suite_create("\n--TurnLeftScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, turnLeft_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *TurnRighftScenario(void)
{
    Suite *s = suite_create("\n--TurnRighftScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, turnRight_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *MoveForwardScenario(void)
{
    Suite *s = suite_create("\n--MoveForwardScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, moveForward_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorMoveForwardScenario(void)
{
    Suite *s = suite_create("\n--ErrormoveForward_test--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrormoveForward_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorTurnLeftScenario(void)
{
    Suite *s = suite_create("\n--ErrorturnLeft_test--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorturnLeft_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorTurnRighftScenario(void)
{
    Suite *s = suite_create("\n--ErrorturnRight_test--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorturnRight_test);
    suite_add_tcase(s, tc_core);
    return s;
}

//------------------------------------------------------------


Suite *powerUpCleanerScenario(void)
{
    Suite *s = suite_create("\n--powerUpCleanerScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, powerUpCleanerTest);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *powerOffCleanerScenario(void)
{
    Suite *s = suite_create("\n--powerOffCleanerScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, powerOffCleanerTest);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *powerUpTurboCleanerScenario(void)
{
    Suite *s = suite_create("\n--powerUpTurboCleanerScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, powerUpTurboCleanerTest);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorpowerUpCleanerScenarios(void)
{
    Suite *s = suite_create("\n--ErrorpowerUpCleanerScenarios--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorpowerUpCleanerTest);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorpowerOffCleanerScenario(void)
{
    Suite *s = suite_create("\n--ErrorpowerOffCleanerScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorpowerOffCleanerTest);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorpowerUpTurboCleanerScenario(void)
{
    Suite *s = suite_create("\n--ErrorpowerUpTurboCleanerScenario--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorpowerUpTurboCleanerTest);
    suite_add_tcase(s, tc_core);
    return s;
}


//------------------------------------------------------------


Suite *normalScenario(void)
{
    Suite *s = suite_create("\n--NoramlExample--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, NormalMortor_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *MotorErrorScenario(void)
{
    Suite *s = suite_create("\n--ErrorExample--");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorMotor_test);
    suite_add_tcase(s, tc_core);
    return s;
}