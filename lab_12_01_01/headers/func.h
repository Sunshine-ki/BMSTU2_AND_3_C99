#ifndef FUNC_H

#define FUNC_H

#include "struct.h"

#define LEN_ANSWER 16
#define MODE_VAL 1
#define MODE_DDX 2
#define MODE_SUM 3
#define MODE_DVD 4
#define ERROR_BUFFER -2

int value(list *list_polynomial, int a);

void derivative(list *list_polynomial);

list *addition(list *list_polynomial_1, list *list_polynomial_2);

int separation(list *polynomial, list *polynomial_1, list *polynomial_2);

int mode_function(char answer[LEN_ANSWER]);

#endif