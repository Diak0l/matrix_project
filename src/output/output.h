#ifndef OUTPUT_H
#define OUTPUT_H

#include "../matrix/matrix.h"

/**
 * @brief Выводит матрицу в консоль.
 *
 * @param matrix Указатель на матрицу для вывода.
 */
void print_matrix_to_console(const Matrix* matrix);

/**
 * @brief Записывает матрицу в файл.
 *
 * @param matrix Указатель на матрицу для записи.
 * @param filename Имя файла для записи.
 */
void write_matrix_to_file(const Matrix* matrix, const char* filename);

#endif /* OUTPUT_H */