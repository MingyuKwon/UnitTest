#include <check.h>
#include <stdio.h>
#include "TestCase.h"  // 테스트할 케이스들이 정의된 헤더 파일

Suite *TurnLeftScenario(void)
{
    Suite *s = suite_create("\nTurnLeftScenario");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, turnLeft_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *TurnRighftScenario(void)
{
    Suite *s = suite_create("\nTurnRighftScenario");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, turnRight_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *MoveForwardScenario(void)
{
    Suite *s = suite_create("\nMoveForwardScenario");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, moveForward_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorMoveForwardScenario(void)
{
    Suite *s = suite_create("\nErrormoveForward_test");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrormoveForward_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorTurnLeftScenario(void)
{
    Suite *s = suite_create("\nErrorturnLeft_test");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorturnLeft_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *ErrorTurnRighftScenario(void)
{
    Suite *s = suite_create("\nErrorturnRight_test");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorturnRight_test);
    suite_add_tcase(s, tc_core);
    return s;
}


Suite *normalScenario(void)
{
    Suite *s = suite_create("\nNoramlExample");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, NormalMortor_test);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite *MotorErrorScenario(void)
{
    Suite *s = suite_create("\nErrorExample");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ErrorMotor_test);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    printf("\n");

    int number_failed;

    Suite *tls = TurnLeftScenario();
    Suite *trs = TurnRighftScenario();
    Suite *mfs = MoveForwardScenario();

    Suite *etls = ErrorTurnLeftScenario();
    Suite *etrs = ErrorTurnRighftScenario();
    Suite *emfs = ErrorMoveForwardScenario();

    Suite *ns = normalScenario();
    Suite *mes = MotorErrorScenario();

    SRunner *sr = srunner_create(tls);
    srunner_add_suite(sr,trs);
    srunner_add_suite(sr,mfs);
    srunner_add_suite(sr,etls);
    srunner_add_suite(sr,etrs);
    srunner_add_suite(sr,emfs);
    srunner_add_suite(sr,ns);
    srunner_add_suite(sr,mes);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}