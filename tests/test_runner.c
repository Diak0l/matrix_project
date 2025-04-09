#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>

void test_create_matrix(void);
void test_add_matrices(void);
void test_subtract_matrices(void);
void test_determinant(void);
void test_print_matrix(void);
void test_save_load_matrix(void);
void test_integration(void);

int main() {
    printf("Запуск тестов...\n");

    CU_initialize_registry();

    CU_pSuite matrix_suite = CU_add_suite("Тесты матриц", 0, 0);
    CU_add_test(matrix_suite, "Создание матрицы", test_create_matrix);
    CU_add_test(matrix_suite, "Сложение матриц", test_add_matrices);
    CU_add_test(matrix_suite, "Вычитание матриц", test_subtract_matrices);
    CU_add_test(matrix_suite, "Определитель", test_determinant);

    CU_pSuite output_suite = CU_add_suite("Тесты вывода", 0, 0);
    CU_add_test(output_suite, "Печать матрицы", test_print_matrix);
    CU_add_test(output_suite, "Сохранение и загрузка матрицы", test_save_load_matrix);

    CU_pSuite main_suite = CU_add_suite("Основные тесты", 0, 0);
    CU_add_test(main_suite, "Интеграционный тест", test_integration);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    printf("Тесты завершены.\n");

    return 0;
}
