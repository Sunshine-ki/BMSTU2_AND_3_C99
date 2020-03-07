#include <stdio.h>
#include <string.h>

#include "headers/my_snprintf.h"
#include "headers/test_snprintf.h"

#define ERROR_TEST 1
#define OK 0
#define LEN 50

int t_my_str_len_null()
{
    if (my_str_len(NULL) != 0)
    {
        printf("t_my_str_len_null()");
        return ERROR_TEST;
    }

    return OK;
}

int t_my_str_len_correct()
{
    if (my_str_len("NULL") != 4)
    {
        printf("t_my_str_len_correct()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_my_int_len_one()
{
    // printf("%d", my_int_len(0));
    if (my_int_len(1) != 1)
    {
        printf("t_my_int_len_one()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_my_int_len_negative()
{
    // printf("%d", my_int_len(0));
    if (my_int_len(-9999) != 4)
    {
        printf("t_my_int_len_negative()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_my_int_len_long()
{
    if (my_int_len(1111111111111111111) != 19)
    {
        printf("t_my_int_len_long()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_my_int_len_correct()
{
    // printf("%d", my_int_len(0));
    if (my_int_len(430) != 3)
    {
        printf("t_my_int_len_correct()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_my_snprintf_null()
{
    if (snprintf(NULL, 0, "12345") != my_snprintf(NULL, 0, "12345"))
    {
        printf("t_my_snprintf_null()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_my_snprintf_int()
{
    char buf[LEN];
    char my_buf[LEN];

    if (snprintf(buf, 50, "12345 %d", 5) != my_snprintf(my_buf, 50, "12345 %d", 5))
    {
        printf("t_my_snprintf_int() (return)\n");
        return ERROR_TEST;
    }
    if (strcmp(buf, my_buf))
    {
        printf("t_my_snprintf_int() (buffer)\n");
        return ERROR_TEST;
    }
    return OK;
}

int t_snprintf_long_int()
{
    char buf[LEN];
    char my_buf[LEN];

    if (snprintf(buf, 50, "12345 %ld", 555555555555555) != my_snprintf(my_buf, 50, "12345 %ld", 555555555555555))
    {
        printf("t_snprintf_long_int() (return)\n");
        return ERROR_TEST;
    }

    if (strcmp(buf, my_buf))
    {
        printf("t_snprintf_long_int() (buffer)\n");
        return ERROR_TEST;
    }
    return OK;
}

int t_snprintf_ll_int()
{
    char buf[LEN];
    char my_buf[LEN];

    if (snprintf(buf, 50, "12345 %ld", 9223372036854775807) != my_snprintf(my_buf, 50, "12345 %lld", 9223372036854775807))
    {
        printf("t_snprintf_ll_int() (return)\n");
        return ERROR_TEST;
    }

    if (strcmp(buf, my_buf))
    {
        printf("t_snprintf_ll_int() (buffer)\n");
        return ERROR_TEST;
    }
    return OK;
}

int t_snprintf_specifier()
{
    char buf[LEN];
    char my_buf[LEN];

    if (snprintf(buf, 50, "%d %d %s", 123, 123, "BMSTU") != my_snprintf(my_buf, 50, "%d %d %s", 123, 123, "BMSTU"))
    {
        printf("t_snprintf_specifier() (return)\n");
        return ERROR_TEST;
    }

    if (strcmp(buf, my_buf))
    {
        printf("t_snprintf_specifier() (buffer)\n");
        return ERROR_TEST;
    }
    return OK;
}

int t_snprintf_str()
{
    char buf[LEN];
    char my_buf[LEN];

    if (snprintf(buf, 50, "%s%s%s", "aaa", "123", "BMSTU") != my_snprintf(my_buf, 50, "%s%s%s", "aaa", "123", "BMSTU"))
    {
        printf("t_snprintf() (return)\n");
        return ERROR_TEST;
    }

    if (strcmp(buf, my_buf))
    {
        printf("t_snprintf() (buffer)\n");
        return ERROR_TEST;
    }
    return OK;
}

int t_snprintf_count_after()
{
    char buf[LEN];
    char my_buf[LEN];

    if (snprintf(buf, 31, "1 %d %ld %s A", 3, 123123123123, "BMSTU") != my_snprintf(my_buf, 31, "1 %d %ld %s A", 3, 123123123123, "BMSTU"))
    {
        printf("t_snprintf_count_after() (return)\n");
        return ERROR_TEST;
    }

    if (strcmp(buf, my_buf))
    {
        printf("t_snprintf_count_after() (buffer)\n");
        return ERROR_TEST;
    }
    return OK;
}

int t_snprintf_count_after_lli()
{
    char buf[LEN];
    char my_buf[LEN];
    long long a = 1111111111111111111;

    if (snprintf(buf, 18, "01%lld%lld%s%lldAA", a, a, "SSSS", a) != my_snprintf(my_buf, 18, "01%lld%lld%s%lldAA", a, a, "SSSS", a))
    {
        printf("t_snprintf_count_after_lli() (return)\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_snprintf_count_after_int_s()
{
    char buf[LEN];
    char my_buf[LEN];

    if (snprintf(buf, 18, "00%d00%d00", 123, 321) != my_snprintf(my_buf, 18, "00%d00%d00", 123, 321))
    {
        printf("t_snprintf_count_after_int_s() (return)\n");
        return ERROR_TEST;
    }

    if (strcmp(buf, my_buf))
    {
        printf("t_snprintf_count_after_int_s() (buffer)\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_snprintf_after_negative_int()
{
    char buf[LEN];
    char my_buf[LEN];

    if (snprintf(buf, 28, "00%d00%d00", -123, -321) != my_snprintf(my_buf, 28, "00%d00%d00", -123, -321))
    {
        printf("t_snprintf_after_negative_int() (return)\n");
        return ERROR_TEST;
    }

    if (strcmp(buf, my_buf))
    {
        printf("t_snprintf_after_negative_int() (buffer)\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_snprintf_after_negative_lli()
{
    char buf[LEN];
    char my_buf[LEN];
    long long a = -1111111111111111111;

    if (snprintf(buf, 50, "01%lld%lld", a, -a) != my_snprintf(my_buf, 50, "01%lld%lld", a, -a))
    {
        printf("t_snprintf_after_negative_lli() (return)\n");
        return ERROR_TEST;
    }

    if (strcmp(buf, my_buf))
    {
        printf("t_snprintf_after_negative_lli() (buffer)\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_snprintf_after_string()
{
    if (snprintf(NULL, 0, "12345%s", "aaa") != my_snprintf(NULL, 0, "12345%s", "aaa"))
    {
        printf("t_snprintf_after_string()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_snprintf_after_int()
{
    if (snprintf(NULL, 0, "12345%d %d", 111, -111) != my_snprintf(NULL, 0, "12345%d %d", 111, -111))
    {
        printf("t_snprintf_after_int()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_snprintf_after_long_int()
{
    long int a = 111111;

    if (snprintf(NULL, 0, "12345%ld %ld", a, -a) != my_snprintf(NULL, 0, "12345%ld %ld", a, -a))
    {
        printf("t_snprintf_after_long_int()\n");
        return ERROR_TEST;
    }

    return OK;
}

int t_snprintf_after_llint()
{
    long long int a = 111111;

    if (snprintf(NULL, 0, "12345%lld %lld", a, -a) != my_snprintf(NULL, 0, "12345%lld %lld", a, -a))
    {
        printf("t_snprintf_after_llint()\n");
        return ERROR_TEST;
    }

    return OK;
}