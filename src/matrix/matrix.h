#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

/**
 * @struct Matrix
 * @brief Структура для представления матрицы.
 *
 * Содержит количество строк, столбцов и указатель на данные матрицы.
 */
typedef struct {
    size_t rows; /**< Количество строк */
    size_t cols; /**< Количество столбцов */
    double** data; /**< Указатель на данные матрицы */
} Matrix;

/**
 * @brief Вычитает одну матрицу из другой.
 *
 * @param A Указатель на первую матрицу.
 * @param B Указатель на вторую матрицу.
 * @return Указатель на новую матрицу, содержащую результат вычитания, или NULL в случае ошибки.
 */
Matrix* subtract_matrices(const Matrix* A, const Matrix* B);

/**
 * @brief Создает новую матрицу заданного размера.
 *
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Указатель на созданную матрицу или NULL в случае ошибки.
 */
Matrix* create_matrix(size_t rows, size_t cols);

/**
 * @brief Освобождает память, занятую матрицей.
 *
 * @param matrix Указатель на матрицу.
 */
void destroy_matrix(Matrix* matrix);

/**
 * @brief Загружает матрицу из файла.
 *
 * @param filename Имя файла для загрузки.
 * @return Указатель на загруженную матрицу или NULL в случае ошибки.
 */
Matrix* load_matrix_from_file(const char* filename);

/**
 * @brief Сохраняет матрицу в файл.
 *
 * @param filename Имя файла для сохранения.
 * @param matrix Указатель на матрицу для сохранения.
 */
void save_matrix_to_file(const char* filename, const Matrix* matrix);

/**
 * @brief Выводит матрицу в консоль.
 *
 * @param matrix Указатель на матрицу для вывода.
 */
void print_matrix(const Matrix* matrix);

/**
 * @brief Копирует одну матрицу в другую.
 *
 * @param src Указатель на исходную матрицу.
 * @return Указатель на новую матрицу, содержащую копию, или NULL в случае ошибки.
 */
Matrix* copy_matrix(const Matrix* src);

/**
 * @brief Складывает две матрицы.
 *
 * @param A Указатель на первую матрицу.
 * @param B Указатель на вторую матрицу.
 * @return Указатель на новую матрицу, содержащую результат сложения, или NULL в случае ошибки.
 */
Matrix* add_matrices(const Matrix* A, const Matrix* B);

/**
 * @brief Умножает две матрицы.
 *
 * @param A Указатель на первую матрицу.
 * @param B Указатель на вторую матрицу.
 * @return Указатель на новую матрицу, содержащую результат умножения, или NULL в случае ошибки.
 */
Matrix* multiply_matrices(const Matrix* A, const Matrix* B);

/**
 * @brief Транспонирует матрицу.
 *
 * @param matrix Указатель на матрицу для транспонирования.
 * @return Указатель на новую транспонированную матрицу или NULL в случае ошибки.
 */
Matrix* transpose_matrix(const Matrix* matrix);

/**
 * @brief Вычисляет детерминант квадратной матрицы.
 *
 * @param matrix Указатель на матрицу.
 * @return Детерминант матрицы или NAN в случае ошибки.
 */
double determinant(const Matrix* matrix);

/**
 * @brief Создает минор матрицы, исключая указанную строку и столбец.
 *
 * @param matrix Указатель на исходную матрицу.
 * @param exclude_row Строка для исключения.
 * @param exclude_col Столбец для исключения.
 * @return Указатель на новую матрицу-минор или NULL в случае ошибки.
 */
Matrix* minor_matrix(const Matrix* matrix, size_t exclude_row, size_t exclude_col);

#endif /* MATRIX_H */