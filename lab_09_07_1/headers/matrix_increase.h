#ifndef MATRIX_INCREASE_H

#define MATRIX_INCREASE_H

#include "constants.h"

int extend_matrix(matrix_t *const matrix, const int n, const int n_new);

void creature_matrix_row_col(matrix_t const matrix, int *const row, int *const col, int row_new);

#endif