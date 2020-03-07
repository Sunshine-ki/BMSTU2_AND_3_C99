#ifndef MATRIX_REDUCTION_H

#define MATRIX_REDUCTION_H

#include "constants.h"

void minimum_element_in_the_matrix(const matrix_t matrix, const int row, const int col, int index[2]);

void swap_row(matrix_t const matrix, const int row, const int col, const int index);

void swap_col(matrix_t const matrix, const int row, const int col, const int index);

int del_matrix_row_col(matrix_t *const matrix, int *const row, int *const col);

#endif