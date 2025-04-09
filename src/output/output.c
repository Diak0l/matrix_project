/* src/output/output.c */
#include "output.h"
#include <stdio.h>

void print_matrix_to_console(const Matrix* matrix) {
    if (!matrix) return;
    for (size_t i = 0; i < matrix->rows; ++i) {
        for (size_t j = 0; j < matrix->cols; ++j)
            printf("%.17g ", matrix->data[i][j]);
        printf("\n");
    }
    printf("\n");
}

void write_matrix_to_file(const Matrix* matrix, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    fprintf(file, "%zu %zu\n", matrix->rows, matrix->cols);
    for (size_t i = 0; i < matrix->rows; ++i) {
        for (size_t j = 0; j < matrix->cols; ++j)
            fprintf(file, "%.17g ", matrix->data[i][j]);
        fprintf(file, "\n");
    }

    fclose(file);
}