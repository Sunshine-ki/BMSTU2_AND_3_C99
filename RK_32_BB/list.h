#ifndef CDIO_H

#define CDIO_H

#include "struct.h"

void input_list(FILE *f,  node_s **list_p);

int push(node_s **stack_list, char word[MAX_LEN_WORD]);

void reverse(FILE *f, node_s *stack_list);

void destruct(node_s *stack_list);

#endif

