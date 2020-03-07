#include "../headers/computational.h"
#include "../headers/test_computational.h"
#include "../headers/constants.h"
#include <stdio.h>

int tests_comput_correct()
{
    double arr_1[] = { 1, 2, 3, 4, 5, 6 };

    if (function_1(arr_1, 6) - 4.188859 > EPS)
    {
        printf("Ошибка на тесте 1");
        return ERROR_TEST;
    }

    return OK;
}

int tests_comput_null_data()
{
    double arr_2[] = { 0, 0, 0, 0 };

    if (function_1(arr_2, 4) > EPS)
    {
        printf("Ошибка на тесте 2");
        return ERROR_TEST;
    }

    return OK;
}

int tests_comput_negative_data()
{
    double arr_3[] = { -1, -2, -3, -4, -5, -6 };

    if (function_1(arr_3, 6) - 4.188859 > EPS)
    {
        printf("Ошибка на тесте 3");
        return ERROR_TEST;
    }

    return OK;
}

int tests_comput_negativ_positiv()
{
    double arr_4[] = { -1, 2, -3, 4, -5, 6 };

    if (function_1(arr_4, 6) - 4.188859 > EPS)
    {
        printf("Ошибка на тесте 4");
        return ERROR_TEST;
    }

    return OK;
}

int test_min_element_correct()
{
    double arr_1[] = { 1, 2, 3, 4, 5, 6 };

    if (min_element_in_array(arr_1, 6) - 1 > EPS)
    {
        printf("Ошибка на тесте 5");
        return ERROR_TEST;
    }

    return OK;
}

int test_min_element_negative()
{
    double arr_3[] = { -1, -2, -3, -4, -5, -6 };

    if (min_element_in_array(arr_3, 6) + 6 > EPS)
    {
        printf("Ошибка на тесте 6");
        return ERROR_TEST;
    }

    return OK;
}

int test_min_elem_negativ_positiv()
{
    double arr_4[] = { -1, 2, -3, 4, -5, 6 };

    if (min_element_in_array(arr_4, 6) + 5 > EPS)
    {
        printf("Ошибка на тесте 7");
        return ERROR_TEST;
    }

    return OK;
}

int test_min_element_null_data()
{
    double arr_2[] = { 0, 0, 0, 0 };

    if (min_element_in_array(arr_2, 4) > EPS)
    {
        printf("Ошибка на тесте 8");
        return ERROR_TEST;
    }

    return OK;
}