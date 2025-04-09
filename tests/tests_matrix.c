#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "matrix.h"
#include <stdio.h>

void test_create_matrix(void) {
    printf("Тест: Создание матрицы ... ");
    Matrix* matrix = create_matrix(3, 3);
    CU_ASSERT_PTR_NOT_NULL(matrix);
    CU_ASSERT_EQUAL(matrix->rows, 3);
    CU_ASSERT_EQUAL(matrix->cols, 3);
    destroy_matrix(matrix);
    printf("пройден\n");
}

void test_add_matrices(void) {
    printf("Тест: Сложение матриц ... ");
    Matrix* A = create_matrix(2, 2);
    Matrix* B = create_matrix(2, 2);
    A->data[0][0] = 1; A->data[0][1] = 2;
    A->data[1][0] = 3; A->data[1][1] = 4;
    B->data[0][0] = 5; B->data[0][1] = 6;
    B->data[1][0] = 7; B->data[1][1] = 8;

    Matrix* result = add_matrices(A, B);
    CU_ASSERT_PTR_NOT_NULL(result);
    CU_ASSERT_EQUAL(result->data[0][0], 6);
    CU_ASSERT_EQUAL(result->data[0][1], 8);
    CU_ASSERT_EQUAL(result->data[1][0], 10);
    CU_ASSERT_EQUAL(result->data[1][1], 12);

    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(result);
    printf("пройден\n");
}

void test_subtract_matrices(void) {
    printf("Тест: Вычитание матриц ... ");
    Matrix* A = create_matrix(2, 2);
    Matrix* B = create_matrix(2, 2);
    A->data[0][0] = 5; A->data[0][1] = 6;
    A->data[1][0] = 7; A->data[1][1] = 8;
    B->data[0][0] = 1; B->data[0][1] = 2;
    B->data[1][0] = 3; B->data[1][1] = 4;

    Matrix* result = subtract_matrices(A, B);
    CU_ASSERT_PTR_NOT_NULL(result);
    CU_ASSERT_EQUAL(result->data[0][0], 4);
    CU_ASSERT_EQUAL(result->data[0][1], 4);
    CU_ASSERT_EQUAL(result->data[1][0], 4);
    CU_ASSERT_EQUAL(result->data[1][1], 4);

    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(result);
    printf("пройден\n");
}

void test_determinant(void) {
    printf("Тест: Определитель матрицы ... ");
    Matrix* matrix = create_matrix(2, 2);
    matrix->data[0][0] = 1; matrix->data[0][1] = 2;
    matrix->data[1][0] = 3; matrix->data[1][1] = 4;

    double det = determinant(matrix);
    CU_ASSERT_DOUBLE_EQUAL(det, -2, 1e-6);

    destroy_matrix(matrix);
    printf("пройден\n");
}
