/* src/matrix/matrix.h */
#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

typedef struct {
    size_t rows;
    size_t cols;
    double** data;
} Matrix;

Matrix* subtract_matrices(const Matrix* A, const Matrix* B);

Matrix* create_matrix(size_t rows, size_t cols);
void destroy_matrix(Matrix* matrix);

Matrix* load_matrix_from_file(const char* filename);
// void load_matrix_from_file(Matrix* matrix, const char* filename);
void save_matrix_to_file(const char* filename, const Matrix* matrix);

void print_matrix(const Matrix* matrix);

Matrix* copy_matrix(const Matrix* src);

Matrix* add_matrices(const Matrix* A, const Matrix* B);
Matrix* multiply_matrices(const Matrix* A, const Matrix* B);

Matrix* transpose_matrix(const Matrix* matrix);

double determinant(const Matrix* matrix);
Matrix* minor_matrix(const Matrix* matrix, size_t exclude_row, size_t exclude_col);

#endif /* MATRIX_H */