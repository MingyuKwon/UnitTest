#include "TestCase.h"  // 테스트할 케이스들이 정의된 헤더 파일

int main(void)
{
    printf("\n");
    int number_failed;

//=========================== 이동 모터 시험 ==================================
    // Suite *tls = TurnLeftScenario();
    Suite *lrfs = LeftRightForwardScenario();
    Suite *putos = powerUpTurboOffCleanerScenario();

    Suite *mrs = MoveRotateScenario();
    Suite *mres = MoveRotateErrorScenario();
    Suite *mros = MoveRotateObstacleScenario();

    SRunner *moveMotorTestRunner = srunner_create(lrfs);
    srunner_add_suite(moveMotorTestRunner,putos);

    srunner_add_suite(moveMotorTestRunner,mrs);
    srunner_add_suite(moveMotorTestRunner,mres);
    srunner_add_suite(moveMotorTestRunner,mros);

    srunner_run_all(moveMotorTestRunner, CK_NORMAL);
    number_failed = srunner_ntests_failed(moveMotorTestRunner);
    srunner_free(moveMotorTestRunner);


    printf("\n\n\n");
//===========================  센서 감지 시험 ==================================

    Suite *dds = detDustScenario();
    Suite *dos = detObstacleScenario();

    SRunner *SensorTestRunner = srunner_create(dds);
    srunner_add_suite(SensorTestRunner,dos);

    srunner_run_all(SensorTestRunner, CK_NORMAL);
    number_failed = srunner_ntests_failed(SensorTestRunner);
    srunner_free(SensorTestRunner);

    printf("\n\n\n");
//=========================== 센서 감지 + 이동 합체 시험 ===============================
    Suite *meos = MoveEvadingObstacleScenario();

    SRunner * MoveEvadingObstacleTestRunner = srunner_create(meos);

    srunner_run_all(MoveEvadingObstacleTestRunner, CK_NORMAL);
    number_failed = srunner_ntests_failed(MoveEvadingObstacleTestRunner);
    srunner_free(MoveEvadingObstacleTestRunner);

    return (number_failed == 0) ? 0 : 1;
}

