#include <check.h>
#include <stdio.h>
#include "example.h"  // 테스트할 함수들이 정의된 헤더 파일

int function1(int x, int y)
{
    return x + y;
}

int function2(int x, int y)
{
    return x * y;
}

START_TEST(test_function1)
{
    ck_assert_int_eq(function1(1, 2), 3);  // 첫 번째 함수의 결과가 3과 같은지 검증
}
END_TEST

// 두 번째 테스트 케이스
START_TEST(test_function2)
{
    ck_assert_int_eq(function2(3, 4), 7);  // 두 번째 함수의 결과가 7과 같은지 검증
}
END_TEST

Suite *example_suite(void)
{
    Suite *s = suite_create("Example");
    TCase *tc_core = tcase_create("Core");

    // 두 테스트 케이스를 테스트 케이스 그룹에 추가
    tcase_add_test(tc_core, test_function1);
    tcase_add_test(tc_core, test_function2);

    // 테스트 케이스 그룹을 스위트에 추가
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s = example_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    // printf("%d", number_failed);

    return (number_failed == 0) ? 0 : 1;
}