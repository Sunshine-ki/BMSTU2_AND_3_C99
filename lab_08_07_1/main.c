#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "headers/change_array.h"
#include "headers/cdio_array.h"
#include "headers/computational.h"
#include "headers/constants.h"

int main(void)
{
    setbuf(stdout, NULL);

    int len;
    
    printf("Введите размер массива: ");
    int rc = scanf("%d", &len);
    if (rc != ONE || len <= CONST_DEL - 1)
    {
        printf("Ошибка ввода размера массива!");
        return ERROR_INPUT;
    }
    double *arr = NULL;
    if (construct(&arr, len))
    {
        printf("Ошибка!");
        return ERROR_BUFFER;
    }
    if (input_array(arr, len))
    {
        destruct(arr);
        return ERROR_INPUT;
    }

    double n_1 = function_1(arr, len); // + key [-lm] !!!
    if (n_1 < 0)
    {
        printf("Ошибка");
        destruct(arr);
        return ERROR_INPUT;
    }
    swap_array(arr, len, n_1);
    swap_array(arr, len, n_1);
    len -= 2;
    double *arr_new = (double*) realloc(arr, len * sizeof(double));

    if (arr_new)
    {
        arr = arr_new;
        arr_new = NULL;
    }
    else
    {
        destruct(arr);
        return ERROR_BUFFER;
    }
    double mini = min_element_in_array(arr, len);

    int index;
    printf("Введите индекс: ");
    rc = scanf("%d", &index);
    if (rc != ONE || len < index || index < ZERO)
    {
        printf("Ошибка ввода индекса!");
        destruct(arr);
        return ERROR_INPUT;
    }

    len += 3;
    arr_new = (double*) realloc(arr, len * sizeof(double));
    if (arr_new)
    {
        arr = arr_new;
        arr_new = NULL;
    }
    else
    {
        destruct(arr);
        return ERROR_BUFFER;
    }

    insert_array(arr, len, index, mini);
    print_array(arr, len);
 
    destruct(arr);
    return OK;
}