#ifndef __UNIQUE_WORDS__

#define __UNIQUE_WORDS__

#include "const.h"

char **create_unique_words();

char *lower_word(char *word);

void print_unique_words(word_s unique_words);

int func_unique(word_s unique_words, char *word_find);

void input_unique(word_s *unique_words_p, word_s *s, int n);

int comp1(const void *a, const void *b);

#endif
