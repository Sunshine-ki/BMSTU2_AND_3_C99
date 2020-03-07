#include <stdio.h>
#include <stdlib.h>

#include "headers/cdio.h"
#include "headers/constants.h"
#include "headers/matrix_increase.h"
#include "headers/matrix_increase_tests.h"
#include "headers/func_multiplication_tests.h"

int matrix_increase_correct()
{
    matrix_t matrix;
    int row = 4;
    int col = 4;
    if (construct(&matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = i;

    matrix_t matrix_res;
    if (construct(&matrix_res, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix_res[i][j] = i;

    // print_matrix(matrix, row, col);
    creature_matrix_row_col(matrix, &row, &col, row);
    // print_matrix(matrix, row, col);

    if (cmp_matrix(matrix, matrix_res, row) != TRUE)
    {
        destruct(matrix, row, col);
        destruct(matrix_res, row, col);
        printf("Ошибка увеличения!");
        return ERROR_TEST;
    }

    if (destruct(matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }
    if (destruct(matrix_res, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    return OK;
}

int matrix_increase_negative()
{
    matrix_t matrix;
    int row = 4;
    int col = 4;
    if (construct(&matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = -i;

    matrix_t matrix_res;
    if (construct(&matrix_res, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix_res[i][j] = -i;

    // print_matrix(matrix, row, col);
    creature_matrix_row_col(matrix, &row, &col, row);
    // print_matrix(matrix, row, col);

    if (cmp_matrix(matrix, matrix_res, row) != TRUE)
    {
        destruct(matrix, row, col);
        destruct(matrix_res, row, col);
        printf("Ошибка увеличения!");
        return ERROR_TEST;
    }

    if (destruct(matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }
    if (destruct(matrix_res, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    return OK;
}
