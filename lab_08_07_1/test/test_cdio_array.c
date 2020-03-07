#include "../headers/cdio_array.h"
#include "../headers/test_cdio_array.h"
#include "../headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

int tests_cdio_array()
{      
    int i = ONE;  
    double *arr_1 = NULL;

    if (construct(&arr_1, 6) != OK)
    {
        printf("Ошибка на тесте %d", i);
        destruct(arr_1);
        return ERROR_TEST;
    }
    // print_array(arr_1, 6);
    destruct(arr_1);
    i++; 

    // double *arr_2;
    // if (construct(&arr_2, -6) != ERROR_INPUT)
    // {
    //     printf("Ошибка на тесте %d", i);
    //     destruct(arr_2);
    //     return ERROR_TEST;
    // }
    // i++;
    // // print_array(arr_1, 6);
    // input_array(arr_2, 0);

    // if (construct(&arr_2, 0) != OK)
    // {
    //     printf("Ошибка на тесте %d", i);
    //     destruct(arr_2);
    //     return ERROR_TEST;
    // }
    // destruct(arr_2);
    // i++;

    // double arr_3[3];
    // input_array(arr_3, 3);

    return OK;
}
