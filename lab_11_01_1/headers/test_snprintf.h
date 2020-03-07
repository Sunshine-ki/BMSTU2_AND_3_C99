#ifndef _TEST_SNPRINTF_H_

#define _TEST_SNPRINTF_H_

int t_my_str_len_null();

int t_my_str_len_correct();

int t_my_int_len_one();

int t_my_int_len_correct();

int t_my_int_len_correct();

int t_my_int_len_long();

int t_my_int_len_negative();

int t_reverse_correct();

int t_reverse_negative();

int t_reverse_long();

int t_reverse_null();

int t_my_snprintf_null();

int t_my_snprintf_int();

int t_snprintf_long_int();

int t_snprintf_ll_int();

int t_snprintf_specifier();

int t_snprintf_str();

int t_snprintf_count_after_lli();

int t_snprintf_count_after_int_s();

int t_snprintf_after_negative_int();

int t_snprintf_after_negative_lli();

int t_snprintf_after_string();

int t_snprintf_after_int();

int t_snprintf_after_long_int();

int t_snprintf_after_llint();

#endif