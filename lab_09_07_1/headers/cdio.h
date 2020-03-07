#ifndef CDIO_H

#define CDIO_H

#include "constants.h"

short int construct(matrix_t *const matrix, const int row, const int col);

short int input_matrix(const matrix_t matrix, const int row, const int col);

short int print_matrix(const matrix_t matrix, const int row, const int col);

short int destruct(const matrix_t matrix, const int row, const int col);

void destruct_arr(lli *arr);

#endif