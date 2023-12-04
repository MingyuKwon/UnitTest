#include "TestCase.h"  // 테스트할 케이스들이 정의된 헤더 파일

int main(void)
{
    printf("\n");
    int number_failed;

//=========================== 이동 모터 시험 ==================================
    // Suite *tls = TurnLeftScenario();
    // Suite *trs = TurnRighftScenario();
    // Suite *mfs = MoveForwardScenario();

    // Suite *etls = ErrorTurnLeftScenario();
    // Suite *etrs = ErrorTurnRighftScenario();
    // Suite *emfs = ErrorMoveForwardScenario();


    // Suite *pus = powerUpCleanerScenario();
    // Suite *pos = powerOffCleanerScenario();
    // Suite *ptus = powerUpTurboCleanerScenario();

    // Suite *epus = ErrorpowerUpCleanerScenarios();
    // Suite *epos = ErrorpowerOffCleanerScenario();
    // Suite *eptus = ErrorpowerUpTurboCleanerScenario();


    // Suite *ns = normalScenario();
    // Suite *mes = MotorErrorScenario();


    // SRunner *moveMotorTestRunner = srunner_create(tls);
    // srunner_add_suite(moveMotorTestRunner,trs);
    // srunner_add_suite(moveMotorTestRunner,mfs);
    // srunner_add_suite(moveMotorTestRunner,etls);
    // srunner_add_suite(moveMotorTestRunner,etrs);
    // srunner_add_suite(moveMotorTestRunner,emfs);
    // srunner_add_suite(moveMotorTestRunner,ns);
    // srunner_add_suite(moveMotorTestRunner,mes);

    // srunner_add_suite(moveMotorTestRunner,pus);
    // srunner_add_suite(moveMotorTestRunner,pos);
    // srunner_add_suite(moveMotorTestRunner,ptus);
    // srunner_add_suite(moveMotorTestRunner,epus);
    // srunner_add_suite(moveMotorTestRunner,epos);
    // srunner_add_suite(moveMotorTestRunner,eptus);

    // srunner_run_all(moveMotorTestRunner, CK_NORMAL);
    // number_failed = srunner_ntests_failed(moveMotorTestRunner);
    // srunner_free(moveMotorTestRunner);
//=========================== 이동 모터 시험 ==================================

    Suite *dds = detDustScenario();
    Suite *dos = detObstacleScenario();

    SRunner *SensorTestRunner = srunner_create(dds);
    srunner_add_suite(SensorTestRunner,dos);

    srunner_run_all(SensorTestRunner, CK_NORMAL);
    number_failed = srunner_ntests_failed(SensorTestRunner);
    srunner_free(SensorTestRunner);

    return (number_failed == 0) ? 0 : 1;
}
