#ifndef FUNC_MULTIPLICATION_H

#define FUNC_MULTIPLICATION_H

#include "constants.h"

void multiplication_matrix(matrix_t const matrix_a, matrix_t const matrix_b, matrix_t const matrix_res, const int n);

void identity_matrix(matrix_t const matrix_a, const int n);

void copy_matrix(matrix_t const matrix_res, matrix_t const matrix, const int n);

int func_multiplication(matrix_t const matrix_a, matrix_t const matrix_b, matrix_t const matrix_res, const int n, const int pow_1, const int pow_2);

#endif