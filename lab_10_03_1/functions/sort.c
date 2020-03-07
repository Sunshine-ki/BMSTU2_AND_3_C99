#include <string.h>
#include <stdio.h>

#include "sort.h"

#define OK 0
#define TRUE 1
#define FALSE 0
#define EPS 1e-5
#define EQUAL 0
#define LESS -1
#define MAX_LEN_KEY 16
#define ERROR_INPUT -1

// void sort(experiment_t *array, int n, int (*compare)(experiment_t, experiment_t))
// {
//     experiment_t temp;

//     for (int i = 0; i < n; i++)
//         for (int j = n - 1; j > i; j--)
//             if (compare(array[j - 1], array[j]) == TRUE)
//             {
//                 temp = array[j - 1];
//                 array[j - 1] = array[j];
//                 array[j] = temp;
//             }
// }

void qs_sort(experiment_t *array, int first, int last, int (*compare)(experiment_t, experiment_t))
{
    if (first < last)
    {
        int left = first, right = last;
        experiment_t middle = array[(left + right) / 2];
        do
        {
            while (compare(array[left], middle) == LESS)
                left++;
            while (compare(middle, array[right]) == LESS)
                right--;
            if (left <= right)
            {
                if (compare(array[right], array[left]) == LESS)
                {
                    experiment_t tmp = array[left];
                    array[left] = array[right];
                    array[right] = tmp;
                }
                left++;
                right--;
            }
        } while (left <= right);
        qs_sort(array, first, right, compare);
        qs_sort(array, left, last, compare);
    }
}

// upper TRUE.
// lower FALSE.
// int case_char(char a)
// {
//     if (a > 'A' && a < 'Z')
//         return TRUE;
// }

/*
Меньше 0	str1 меньше, чем str2 LESS
Равно 0	    str1 равна str2 EQUAL
Больше 0	str1 больше, чем str2 TRUE
*/
int str_cmp(experiment_t experiment_1, experiment_t experiment_2)
{
    int temp = strcmp(experiment_1.surname, experiment_2.surname);
    if (temp < 0)
        return LESS;
    if (temp > 0)
        return TRUE;
    return EQUAL;

    // if (strlen(experiment_1.surname) < strlen(experiment_2.surname))
    //     return LESS;
    // else if (strlen(experiment_1.surname) > strlen(experiment_2.surname))
    //     return TRUE;
    // for (int i = 0; i < strlen(experiment_1.surname); i++)
    // {
    //     if (experiment_1.surname[i] > experiment_2.surname[i])
    //     {
    //         if (experiment_1.surname[i] > 'A' && experiment_1.surname[i] < 'Z')
    //             printf("%c > %c\n", experiment_1.surname[i], experiment_2.surname[i]);
    //     }
    //     else if (experiment_1.surname[i] < experiment_2.surname[i])
    //         printf("%c < %c\n", experiment_1.surname[i], experiment_2.surname[i]);
    // }

    // return EQUAL;
}

int date_cmp(experiment_t experiment_1, experiment_t experiment_2)
{
    // printf("\n%d %d\n", experiment_1.day, experiment_2.day);
    // printf("%d %d\n", experiment_1.month, experiment_2.month);
    // printf("%d %d\n", experiment_1.year, experiment_2.year);
    if (experiment_1.day == experiment_2.day && experiment_1.month == experiment_2.month //
        && experiment_1.year == experiment_2.year)
        return EQUAL;

    if (experiment_1.year < experiment_2.year)
        return LESS;

    if (experiment_1.year == experiment_2.year && experiment_1.month < experiment_2.month)
        return LESS;

    if (experiment_1.year == experiment_2.year && experiment_1.month == experiment_2.month //
        && experiment_1.day < experiment_2.day)
        return LESS;

    return TRUE;
}

int float_cmp(experiment_t experiment_1, experiment_t experiment_2)
{
    // printf("\n%f %f\n", experiment_1.array_experiment[0], experiment_2.array_experiment[0]);

    float temp = experiment_1.array_experiment[0] - experiment_2.array_experiment[0];

    if (temp < 0)
        return LESS;

    if (temp < EPS)
        return EQUAL;

    return TRUE;
}

int choice_sort(int (**compare)(experiment_t, experiment_t))
{
    printf("Введите ключ: \n");
    char key[MAX_LEN_KEY];
    scanf("%s", key);

    if (strcmp(key, "DATE") == OK)
        *compare = date_cmp;
    else if (strcmp(key, "TECHNICIAN") == OK)
        *compare = str_cmp;
    else if (strcmp(key, "DATA") == OK)
        *compare = float_cmp;
    else
        return ERROR_INPUT;

    return OK;
}