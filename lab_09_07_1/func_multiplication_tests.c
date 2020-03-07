#include <stdio.h>
#include <stdlib.h>

#include "headers/cdio.h"
#include "headers/constants.h"
#include "headers/func_multiplication.h"
#include "headers/func_multiplication_tests.h"

// Сравненивает элементы квадратных матриц
int cmp_matrix(matrix_t const matrix_a, matrix_t const matrix_b, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix_a[i][j] != matrix_b[i][j])
                return FALSE;

    return TRUE;
}

int multi_correct_data()
{
    matrix_t matrix1;
    int row = 3;
    int col = 3;
    if (construct(&matrix1, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix1[i][j] = (i == j);

    matrix_t matrix2;
    if (construct(&matrix2, row, col) != OK)
    {
        destruct(matrix1, row, col);
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix2[i][j] = (i == j);

    matrix_t matrix_correct_res;
    if (construct(&matrix_correct_res, row, col) != OK)
    {
        destruct(matrix1, row, col);
        destruct(matrix2, row, col);
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix_correct_res[i][j] = (i == j);

    matrix_t matrix_res;
    if (construct(&matrix_res, row, col) != OK)
    {
        destruct(matrix1, row, col);
        destruct(matrix2, row, col);
        destruct(matrix_correct_res, row, col);
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix_res[i][j] = 0;

    multiplication_matrix(matrix1, matrix2, matrix_res, row);

    if (cmp_matrix(matrix_res, matrix_correct_res, col) != TRUE)
    {
        destruct(matrix1, row, col);
        destruct(matrix2, row, col);
        destruct(matrix_correct_res, row, col);
        printf("Ошибка умножения!");
        return ERROR_TEST;
    }

    destruct(matrix1, row, col);
    destruct(matrix2, row, col);
    destruct(matrix_res, row, col);
    destruct(matrix_correct_res, row, col);

    return OK;
}

int multi_negative_data()
{
    matrix_t matrix1;
    int row = 3;
    int col = 3;
    if (construct(&matrix1, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix1[i][j] = -1;

    matrix_t matrix2;
    if (construct(&matrix2, row, col) != OK)
    {
        destruct(matrix1, row, col);
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix2[i][j] = -1;

    matrix_t matrix_correct_res;
    if (construct(&matrix_correct_res, row, col) != OK)
    {
        destruct(matrix1, row, col);
        destruct(matrix2, row, col);
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix_correct_res[i][j] = 3;

    matrix_t matrix_res;
    if (construct(&matrix_res, row, col) != OK)
    {
        destruct(matrix1, row, col);
        destruct(matrix2, row, col);
        destruct(matrix_correct_res, row, col);
        printf("Ошибка!");
        return ERROR_TEST;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix_res[i][j] = 0;

    multiplication_matrix(matrix1, matrix2, matrix_res, row);

    if (cmp_matrix(matrix_res, matrix_correct_res, col) != TRUE)
    {
        destruct(matrix1, row, col);
        destruct(matrix2, row, col);
        destruct(matrix_correct_res, row, col);
        printf("Ошибка умножения!");
        return ERROR_TEST;
    }

    destruct(matrix1, row, col);
    destruct(matrix2, row, col);
    destruct(matrix_res, row, col);
    destruct(matrix_correct_res, row, col);

    return OK;
}