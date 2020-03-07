#ifndef __BINARY_MATRIX_H__

#define __BINARY_MATRIX_H__

#include "const.h"

#include <stdlib.h>
#include <stdio.h>

void input_binary_matrix(int **binary_matrix, word_s unique_words, word_s *s, int n);

void print_matrix(FILE *f, int **binary_matrix, int n, int m);

int **create_binary_matrix(int n);

#endif