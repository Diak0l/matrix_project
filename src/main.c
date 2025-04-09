/* src/main.c */
#include <stdio.h>
#include "matrix/matrix.h"
#include "output/output.h"


int main() {
    // Демонстрация работы библиотеки
    Matrix* A = load_matrix_from_file("mat1.txt");
    Matrix* B = load_matrix_from_file("mat2.txt");
    Matrix* C = load_matrix_from_file("mat3.txt");
    Matrix* D = load_matrix_from_file("mat4.txt");


    // Matrix* A = create_matrix(3, 3);
    // Matrix* B = create_matrix(3, 3);
    // Matrix* C = create_matrix(3, 3);
    // Matrix* D = create_matrix(3, 3);


    // // Загрузить матрицы из файлов
    // load_matrix_from_file(A, "mat1.txt");
    // load_matrix_from_file(B, "mat2.txt");
    // load_matrix_from_file(C, "mat3.txt");
    // load_matrix_from_file(D, "mat4.txt");

    // Вывод матриц в консоль
    print_matrix_to_console(A);
    print_matrix_to_console(B);
    print_matrix_to_console(C);
    print_matrix_to_console(D);

    Matrix* transposedB = transpose_matrix(B);
    print_matrix_to_console(transposedB);
    Matrix* multiBtC = multiply_matrices(transposedB, C);
    print_matrix_to_console(multiBtC);
    Matrix* subAmultiBtC = subtract_matrices(A, multiBtC);
    print_matrix_to_console(subAmultiBtC);
    Matrix* sumsubAmultiBtCD = add_matrices(subAmultiBtC, D);
    print_matrix_to_console(sumsubAmultiBtCD);

    // Освобождение памяти
    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(C);
    destroy_matrix(D);
    destroy_matrix(transposedB);
    destroy_matrix(multiBtC);
    destroy_matrix(subAmultiBtC);
    destroy_matrix(sumsubAmultiBtCD);
    return 0;
}