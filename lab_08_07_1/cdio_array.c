#include "headers/cdio_array.h"
#include "headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

int construct(double **const arr, const int len)
{   
    if (len < 0)
    {
        printf("Ошибка!");
        return ERROR_INPUT;
    }   
    *arr = (double*) malloc(len * sizeof(double));

    if (*arr == NULL)
    {
        printf("Ошибка!");
        return ERROR_INPUT;
    }
    return OK;
}

void destruct(double *arr)
{
    if (arr)
    {
        free(arr);
        arr = NULL;
    }
}

int input_array(double *const arr, const int len)
{
    int rc = 0;

    printf("Заполните массив элементами:\n");
    for (double *p = arr; p < arr + len; p++)
    {
        rc = scanf("%lf", p);
        if (rc != ONE)
        {
            printf("Ошибка ввода массива!");
            return ERROR_INPUT;
        }
    }

    return OK;
}

void print_array(double *const arr, const int len)
{
    printf("\nМассив:\n");
    for (double *p = arr; p < arr + len; p++)
        printf("%.6lf ", *p);
    puts("");
}