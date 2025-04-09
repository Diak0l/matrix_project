#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "output.h"
#include "matrix.h"
#include <stdio.h>

void test_print_matrix(void) {
    printf("Тест: Печать матрицы ... ");
    Matrix* matrix = create_matrix(2, 2);
    matrix->data[0][0] = 1; matrix->data[0][1] = 2;
    matrix->data[1][0] = 3; matrix->data[1][1] = 4;

    print_matrix(matrix);

    destroy_matrix(matrix);
    printf("пройден\n");
}

void test_save_load_matrix(void) {
    printf("Тест: Сохранение и загрузка матрицы ... ");
    const char* filename = "test_matrix.txt";
    Matrix* matrix = create_matrix(2, 2);
    matrix->data[0][0] = 1; matrix->data[0][1] = 2;
    matrix->data[1][0] = 3; matrix->data[1][1] = 4;

    save_matrix_to_file(filename, matrix);

    Matrix* loaded_matrix = load_matrix_from_file(filename);

    CU_ASSERT_EQUAL(loaded_matrix->data[0][0], 1);
    CU_ASSERT_EQUAL(loaded_matrix->data[0][1], 2);
    CU_ASSERT_EQUAL(loaded_matrix->data[1][0], 3);
    CU_ASSERT_EQUAL(loaded_matrix->data[1][1], 4);

    destroy_matrix(matrix);
    destroy_matrix(loaded_matrix);
    remove(filename);
    printf("пройден\n");
}
