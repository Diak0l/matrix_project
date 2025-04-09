#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "matrix.h"
#include "output.h"
#include <stdio.h>


void test_integration() {
    // Создаем матрицы A и B
    Matrix* A = create_matrix(2, 3);
    Matrix* B = create_matrix(3, 2);
    Matrix* E = create_matrix(2, 2); // Ожидаемая матрица

    // Задаем значения для матриц A и B
    A->data[0][0] = 1; A->data[0][1] = 2; A->data[0][2] = 3;
    A->data[1][0] = 4; A->data[1][1] = 5; A->data[1][2] = 6;

    B->data[0][0] = 7; B->data[0][1] = 8;
    B->data[1][0] = 9; B->data[1][1] = 10;
    B->data[2][0] = 11; B->data[2][1] = 12;

    // Ожидаемое значение для матрицы E
    E->data[0][0] = 58;  // 1*7 + 2*9 + 3*11
    E->data[0][1] = 64;  // 1*8 + 2*10 + 3*12
    E->data[1][0] = 139; // 4*7 + 5*9 + 6*11
    E->data[1][1] = 154; // 4*8 + 5*10 + 6*12

    // Умножаем матрицы
    Matrix* F = multiply_matrices(A, B);

    // Проверяем результаты
    CU_ASSERT_EQUAL(F->data[0][0], E->data[0][0]);
    CU_ASSERT_EQUAL(F->data[0][1], E->data[0][1]);
    CU_ASSERT_EQUAL(F->data[1][0], E->data[1][0]);
    CU_ASSERT_EQUAL(F->data[1][1], E->data[1][1]);

    // Очищаем память
    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(E);
    destroy_matrix(F);
}

// Не забудьте зарегистрировать тест в вашем тестовом наборе
void register_tests() {
    CU_pSuite pSuite = CU_add_suite("Matrix Suite", 0, 0);
    CU_add_test(pSuite, "Интеграционный тест", test_integration);
}

