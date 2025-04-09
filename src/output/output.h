/* src/output/output.h */
#ifndef OUTPUT_H
#define OUTPUT_H

#include "../matrix/matrix.h"

void print_matrix_to_console(const Matrix* matrix);
void write_matrix_to_file(const Matrix* matrix, const char* filename);

#endif /* OUTPUT_H */