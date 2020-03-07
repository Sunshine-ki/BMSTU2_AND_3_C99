#include "../headers/change_array.h"
#include "../headers/test_change_array.h"
#include "../headers/cdio_array.h"
#include "../headers/constants.h"
#include <stdio.h>

int array_cmp(double *arr_1, double *arr_2, int n_1, int n_2);

int tests_change_correct_data()
{
    double arr_1[] = { 1, 2, 3, 4, 5, 6 };
    double arr_1_res[] = { 1, 2, 3, 4, 4, 5 };

    swap(arr_1, 3, 6);

    if (array_cmp(arr_1, arr_1_res, 6, 6) != TRUE)
    {
        printf("Ошибка на корректных данных");
        return ERROR_TEST;
    }
    return OK;
}

int tests_change_identical()
{
    double arr_2[] = { 1, 1, 1 };
    double arr_2_res[] = { 1, 1, 1 };

    swap(arr_2, 0, 3);

    if (array_cmp(arr_2, arr_2_res, 3, 3) != TRUE)
    {
        printf("Ошибка на одинаковых данных!");
        return ERROR_TEST;
    }
    return OK;
}

int tests_change_array()
{
    double arr_4[] = { 0, 2, 3, 0, 0 };
    double arr_4_res[] = { 2, 3, 0, 0, 0 };

    swap_array(arr_4, 5, 0);
    if (array_cmp(arr_4, arr_4_res, 5, 5) != TRUE)
    {
        printf("Ошибка на тесте, где должен удалиться \
        первый элемент, схожий с последним");
        return ERROR_TEST;
    }
    swap_array(arr_4, 5, 1);
    return OK;
}

int tests_change_negative_elem()
{
    double arr_4[] = { 0, 2, 3, 0, 0 };
    // double arr_5_res[] = {2, 3, 0, 0, 0};
    swap_array(arr_4, 5, 1);
    insert_array(arr_4, 5, 0, -1);
    double arr_5_res[] = { -1, -1, 2, 3, -1 };
    if (array_cmp(arr_4, arr_5_res, 5, 5) != TRUE)
    {
        printf("Ошибка на тесте с отрицательными элементами");
        return ERROR_TEST;
    }

    return OK;
}

// Сравнивает два массива.
// На выходе:
// 0 - массивы различны.
// 1 - массивы равны.
int array_cmp(double *arr_1, double *arr_2, int n_1, int n_2)
{
    if (n_1 != n_2)
        return FALSE;
    for (int i = 0; i < n_1; i++)
    {
        if (arr_1[i] - arr_2[i] > EPS)
        {
            // printf("\n%lf %lf", arr_1[i], arr_2[i]);
            return FALSE;
        }
    }
    return TRUE;
}