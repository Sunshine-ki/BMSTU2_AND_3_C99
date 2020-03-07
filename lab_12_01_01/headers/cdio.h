#ifndef CDIO_H

#define CDIO_H

#include "struct.h"

list *construct(int num, int pow_num);

int input_polynomial(FILE *f, list **list_polynomial);

void output_polynomial(FILE *f, list *list_polynomial);

list *add_element(list *list_polynomial, int num, int pow_num);

void destruct(list *list_polynomial);

#endif