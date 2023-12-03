#include <check.h>
#include <stdio.h>
#include "example.h"  // 테스트할 함수들이 정의된 헤더 파일

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

START_TEST(ErrorturnRight_test) // 우회전 작업이 성공적으로 진행 되는지 체크
{
    m.isMotorError = true;
    ck_assert_int_eq(turnRight(), 0);  
}
END_TEST

START_TEST(ErrorturnLeft_test)  // 좌회전 작업이 성공적으로 진행 되는지 체크
{ 
    m.isMotorError = true;
    ck_assert_int_eq(turnLeft(), 0); 
}
END_TEST

START_TEST(ErrormoveForward_test)  // 전진 작업이 성공적으로 진행 되는지 체크
{ 
    m.isMotorError = true;
    ck_assert_int_eq(moveForward(), 0); 
}
END_TEST




Suite *normalScenario(void)
{
    Suite *s = suite_create("\nNoramlExample");
    TCase *tc_core = tcase_create("Core");

    // 두 테스트 케이스를 테스트 케이스 그룹에 추가
    tcase_add_test(tc_core, turnRight_test);
    tcase_add_test(tc_core, turnLeft_test);
    tcase_add_test(tc_core, moveForward_test);

    // 테스트 케이스 그룹을 스위트에 추가
    suite_add_tcase(s, tc_core);

    return s;
}

Suite *MotorErrorScenario(void)
{
    Suite *s = suite_create("\nErrorExample");
    TCase *tc_core = tcase_create("Core");


    // 두 테스트 케이스를 테스트 케이스 그룹에 추가
    tcase_add_test(tc_core, ErrorturnRight_test);
    tcase_add_test(tc_core, ErrorturnLeft_test);
    tcase_add_test(tc_core, ErrormoveForward_test);

    // 테스트 케이스 그룹을 스위트에 추가
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *ns = normalScenario();
    Suite *mes = MotorErrorScenario();

    SRunner *sr = srunner_create(ns);
    srunner_add_suite(sr,mes);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}