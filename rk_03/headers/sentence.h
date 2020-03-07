#ifndef __SENTENCE_H__

#define __SENTENCE_H__

#include "const.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

word_s *creat_sentence();

void print_struct(word_s *s, int n);

int input_sentence(word_s **sp, FILE *f);

void add_words(word_s *s, char word[MAX_LEN_WORD], int n, int j);

#endif