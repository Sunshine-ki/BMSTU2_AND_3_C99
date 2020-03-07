#ifndef MY_SNPRINTF_H

#define MY_SNPRINTF_H

#include <stdarg.h>

#define ERROR -1

#define INT 1
#define LONG_INT 2
#define LONG_LONG_INT 3

// #define INT_TO_CHAR(a) a + '0'

char int_to_char(long long int a);

int my_snprintf(char *buf, ...);

int my_str_len(char *str);

int my_int_len(long long int a);

// long long int reverse(long long int a);

void count_after(char *pointer_buf, int *i, va_list pointer);

// void write_int_in_buf(char *pointer_buf, int *i, va_list pointer, char *buf);

void write_str_in_buf(char *pointer_buf, int *i, va_list pointer, char *buf);

// void write_long_int_in_buf(char *pointer_buf, int *i, va_list pointer, char *buf);

// void write_l_l_int_in_buf(char *pointer_buf, int *i, va_list pointer, char *buf);

void write_int_all_in_buf(char *pointer_buf, int *i, va_list pointer, char *buf, int choice);

#endif