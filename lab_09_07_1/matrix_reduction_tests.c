#include <stdio.h>
#include <stdlib.h>

#include "headers/cdio.h"
#include "headers/constants.h"
#include "headers/matrix_reduction.h"
#include "headers/matrix_reduction_tests.h"

int min_elem_correct_first()
{
    matrix_t matrix1;
    int row = 3;
    int col = 3;
    int index[2] = { 0 };

    if (construct(&matrix1, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix1[i][j] = i;

    minimum_element_in_the_matrix(matrix1, row, col, index);

    if (index[0] != 0 && index[1] != 0)
    {
        printf("Ошибка поиска минимального элемента!");
        return ERROR_TEST;
    }

    destruct(matrix1, row, col);

    return OK;
}

int min_elem_correct_last()
{
    matrix_t matrix1;
    int row = 3;
    int col = 3;
    int index[2] = { 0 };

    if (construct(&matrix1, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix1[i][j] = i;
    matrix1[row - 1][col - 1] = -1;

    minimum_element_in_the_matrix(matrix1, row, col, index);

    if (index[0] != 2 && index[1] != 2)
    {
        printf("Ошибка поиска минимального элемента!");
        return ERROR_TEST;
    }

    destruct(matrix1, row, col);

    return OK;
}

int min_elem_zero()
{
    matrix_t matrix1;
    int row = 3;
    int col = 3;
    int index[2] = { 0 };

    if (construct(&matrix1, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix1[i][j] = 0;

    minimum_element_in_the_matrix(matrix1, row, col, index);

    if (index[0] != 0 && index[1] != 0)
    {
        printf("Ошибка поиска минимального элемента!");
        return ERROR_TEST;
    }

    destruct(matrix1, row, col);

    return OK;
}