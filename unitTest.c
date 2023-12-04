#include "TestCase.h"  // 테스트할 케이스들이 정의된 헤더 파일

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


    Suite *pus = powerUpCleanerScenario();
    Suite *pos = powerOffCleanerScenario();
    Suite *ptus = powerUpTurboCleanerScenario();

    Suite *epus = ErrorpowerUpCleanerScenarios();
    Suite *epos = ErrorpowerOffCleanerScenario();
    Suite *eptus = ErrorpowerUpTurboCleanerScenario();


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


    srunner_add_suite(sr,pus);
    srunner_add_suite(sr,pos);
    srunner_add_suite(sr,ptus);
    srunner_add_suite(sr,epus);
    srunner_add_suite(sr,epos);
    srunner_add_suite(sr,eptus);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}