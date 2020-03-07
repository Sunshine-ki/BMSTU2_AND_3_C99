#include <stdio.h>

#include "headers/test_snprintf.h"

int main(void)
{
    int count_error = 0;

    count_error += t_my_str_len_null();
    count_error += t_my_str_len_correct();
    count_error += t_my_int_len_one();
    count_error += t_my_int_len_correct();
    count_error += t_my_int_len_long();
    count_error += t_my_int_len_negative();
    count_error += t_my_snprintf_null();
    count_error += t_my_snprintf_int();
    count_error += t_snprintf_long_int();
    count_error += t_snprintf_ll_int();
    count_error += t_snprintf_specifier();
    count_error += t_snprintf_str();
    count_error += t_snprintf_count_after_lli();
    count_error += t_snprintf_count_after_int_s();
    count_error += t_snprintf_after_negative_int();
    count_error += t_snprintf_after_negative_lli();
    count_error += t_snprintf_after_string();
    count_error += t_snprintf_after_int();
    count_error += t_snprintf_after_long_int();
    count_error += t_snprintf_after_llint();
    
    printf("Error: %d\n", count_error);
    return 0;
}