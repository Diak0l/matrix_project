/* src/matrix/matrix.c */
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

Matrix* subtract_matrices(const Matrix* A, const Matrix* B) {
    // Проверка размеров матриц
    if (A->rows != B->rows || A->cols != B->cols) {
        fprintf(stderr, "Размеры матриц не совпадают!\n");
        return NULL;
    }

    // Создание новой матрицы для результата
    Matrix* result = create_matrix(A->rows, A->cols);
    if (!result) {
        return NULL;
    }

    // Вычитание элементов матриц
    for (size_t i = 0; i < A->rows; ++i) {
        for (size_t j = 0; j < A->cols; ++j) {
            result->data[i][j] = A->data[i][j] - B->data[i][j];
        }
    }

    return result;
}

Matrix* create_matrix(size_t rows, size_t cols) {
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    if (!matrix) return NULL;
    
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double**) malloc(rows * sizeof(double*));
    if (!matrix->data) {
        free(matrix);
        return NULL;
    }
    
    for (size_t i = 0; i < rows; ++i) {
        matrix->data[i] = (double*) calloc(cols, sizeof(double));
        if (!matrix->data[i]) {
            for (size_t j = 0; j < i; ++j)
                free(matrix->data[j]);
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void destroy_matrix(Matrix* matrix) {
    if (!matrix) return;
    for (size_t i = 0; i < matrix->rows; ++i)
        free(matrix->data[i]);
    free(matrix->data);
    free(matrix);
}


Matrix* load_matrix_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла");
        return NULL;
    }

    size_t rows, cols;
    if (fscanf(file, "%zu %zu", &rows, &cols) != 2) {
        fprintf(stderr, "Не удалось прочитать размер матрицы.\n");
        fclose(file);
        return NULL;
    }

    Matrix* matrix = create_matrix(rows, cols);
    if (!matrix) {
        fclose(file);
        return NULL;
    }

    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            if (fscanf(file, "%lf", &matrix->data[i][j]) != 1) {
                fprintf(stderr, "Ошибка чтения элемента матрицы.\n");
                destroy_matrix(matrix); // Освобождаем память в случае ошибки
                fclose(file);
                return NULL;
            }

    fclose(file);
    return matrix; // Возвращаем загруженную матрицу
}

// void load_matrix_from_file(Matrix* matrix, const char* filename) {
//     FILE* file = fopen(filename, "r");
//     if (!file) {
//         perror("Ошибка открытия файла");
//         return;
//     }

//     size_t rows, cols;
//     if (fscanf(file, "%zu %zu", &rows, &cols) != 2) {
//         fprintf(stderr, "Не удалось прочитать размер матрицы.\n");
//         fclose(file);
//         return;
//     }

//     if (matrix->rows != rows || matrix->cols != cols) {
//         fprintf(stderr, "Размер матрицы не совпадает с размером файла.\n");
//         fclose(file);
//         return;
//     }

//     for (size_t i = 0; i < rows; ++i)
//         for (size_t j = 0; j < cols; ++j)
//             if (fscanf(file, "%lf", &matrix->data[i][j]) != 1) { // Чтение каждого элемента
//                 fprintf(stderr, "Ошибка чтения элемента матрицы.\n");
//                 fclose(file);
//                 return;
//             }

//     fclose(file);
// }

void save_matrix_to_file(const char* filename, const Matrix* matrix) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    fprintf(file, "%zu %zu\n", matrix->rows, matrix->cols);
    for (size_t i = 0; i < matrix->rows; ++i) {
        for (size_t j = 0; j < matrix->cols; ++j)
            fprintf(file, "%.15f\t", matrix->data[i][j]); // Используем \t для разделения
        fprintf(file, "\n"); // Переход на новую строку после каждой строки матрицы
    }

    fclose(file);
}


// void load_matrix_from_file(Matrix* matrix, const char* filename) {
//     FILE* file = fopen(filename, "r");
//     if (!file) {
//         perror("Ошибка открытия файла");
//         return;
//     }

//     size_t rows, cols;
//     if (fscanf(file, "%zu %zu", &rows, &cols) != 2) {
//         fprintf(stderr, "Не удалось прочитать размер матрицы.\n");
//         fclose(file);
//         return;
//     }

//     if (matrix->rows != rows || matrix->cols != cols) {
//         fprintf(stderr, "Размер матрицы не совпадает с размером файла.\n");
//         fclose(file);
//         return;
//     }

//     for (size_t i = 0; i < rows; ++i)
//         for (size_t j = 0; j < cols; ++j)
//             if (fscanf(file, "%lf", &matrix->data[i][j]) != 1) {
//                 fprintf(stderr, "Ошибка чтения элемента матрицы.\n");
//                 fclose(file);
//                 return;
//             }

//     fclose(file);
    
// }

// void save_matrix_to_file(const char* filename, const Matrix* matrix) {
//     FILE* file = fopen(filename, "w");
//     if (!file) {
//         perror("Ошибка открытия файла");
//         return;
//     }

//     fprintf(file, "%zu %zu\n", matrix->rows, matrix->cols);
//     for (size_t i = 0; i < matrix->rows; ++i) {
//         for (size_t j = 0; j < matrix->cols; ++j)
//             fprintf(file, "%.17g ", matrix->data[i][j]);
//         fprintf(file, "\n");
//     }

//     fclose(file);
// }

void print_matrix(const Matrix* matrix) {
    if (!matrix) return;
    for (size_t i = 0; i < matrix->rows; ++i) {
        for (size_t j = 0; j < matrix->cols; ++j)
            printf("%.17g ", matrix->data[i][j]);
        printf("\n");
    }
}

Matrix* copy_matrix(const Matrix* src) {
    if (!src) return NULL;
    Matrix* dest = create_matrix(src->rows, src->cols);
    if (!dest) return NULL;

    memcpy(dest->data, src->data, src->rows * src->cols * sizeof(double));
    return dest;
}

Matrix* add_matrices(const Matrix* A, const Matrix* B) {
    if (!A || !B || A->rows != B->rows || A->cols != B->cols) {
        fprintf(stderr, "Матрицы должны иметь одинаковые размеры.\n");
        return NULL;
    }

    Matrix* result = create_matrix(A->rows, A->cols);
    if (!result) return NULL;

    for (size_t i = 0; i < A->rows; ++i)
        for (size_t j = 0; j < A->cols; ++j)
            result->data[i][j] = A->data[i][j] + B->data[i][j];

    return result;
}


Matrix* multiply_matrices(const Matrix* A, const Matrix* B) {
    if (!A || !B || A->cols != B->rows) {
        fprintf(stderr, "Матрицы несовместимы для умножения.\n");
        return NULL;
    }

    Matrix* result = create_matrix(A->rows, B->cols);
    if (!result) return NULL;

    // Инициализация элементов результирующей матрицы
    for (size_t i = 0; i < A->rows; ++i)
        for (size_t j = 0; j < B->cols; ++j)
            result->data[i][j] = 0; // Обнуляем элемент

    for (size_t i = 0; i < A->rows; ++i)
        for (size_t j = 0; j < B->cols; ++j)
            for (size_t k = 0; k < A->cols; ++k)
                result->data[i][j] += A->data[i][k] * B->data[k][j];

    return result;
}

// Matrix* multiply_matrices(const Matrix* A, const Matrix* B) {
//     if (!A || !B || A->cols != B->rows) {
//         fprintf(stderr, "Матрицы несовместимы для умножения.\n");
//         return NULL;
//     }

//     Matrix* result = create_matrix(A->rows, B->cols);
//     if (!result) return NULL;

//     for (size_t i = 0; i < A->rows; ++i)
//         for (size_t j = 0; j < B->cols; ++j)
//             for (size_t k = 0; k < A->cols; ++k)
//                 result->data[i][j] += A->data[i][k] * B->data[k][j];

//     return result;
// }

Matrix* transpose_matrix(const Matrix* matrix) {
    if (!matrix) return NULL;
    Matrix* transposed = create_matrix(matrix->cols, matrix->rows);
    if (!transposed) return NULL;

    for (size_t i = 0; i < matrix->rows; ++i)
        for (size_t j = 0; j < matrix->cols; ++j)
            transposed->data[j][i] = matrix->data[i][j];

    return transposed;
}

double determinant(const Matrix* matrix) {
    if (!matrix || matrix->rows != matrix->cols) {
        fprintf(stderr, "Детерминант возможен только для квадратной матрицы.\n");
        return NAN;
    }

    if (matrix->rows == 1) return matrix->data[0][0]; // Базовый случай
    if (matrix->rows == 2) return matrix->data[0][0]*matrix->data[1][1] - matrix->data[0][1]*matrix->data[1][0];

    double det = 0.0;
    for (size_t i = 0; i < matrix->cols; ++i) {
        // Вычисляем минор для текущей строки
        Matrix* minor = minor_matrix(matrix, 0, i);
        double cofactor = pow(-1, i) * matrix->data[0][i] * determinant(minor);
        det += cofactor;
        destroy_matrix(minor);
    }
    return det;
}

Matrix* minor_matrix(const Matrix* matrix, size_t exclude_row, size_t exclude_col) {
    Matrix* minor = create_matrix(matrix->rows - 1, matrix->cols - 1);
    size_t row = 0, col = 0;
    for (size_t i = 0; i < matrix->rows; ++i) {
        if (i == exclude_row) continue;
        col = 0;
        for (size_t j = 0; j < matrix->cols; ++j) {
            if (j == exclude_col) continue;
            minor->data[row][col++] = matrix->data[i][j];
        }
        row++;
    }
    return minor;
}