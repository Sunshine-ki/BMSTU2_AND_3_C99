#include "headers/cdio.h"
#include "headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

short int construct(matrix_t *const matrix, const int row, const int col)
{
    if (row < 1 || col < 1)
    {
        puts("Некорректный размер матрицы!");
        return ERROR_INPUT_SIZE_MATRIX;
    }

    *matrix = (matrix_t)malloc(row * sizeof(lli *));

    if (*matrix == NULL)
    {
        puts("Ошибка!");
        return ERROR_BUFFER;
    }
    for (int i = 0; i < row; i++)
    {
        (*matrix)[i] = (lli *)malloc(col * sizeof(lli));
        if ((*matrix)[i] == NULL)
        {
            puts("Ошибка!");
            for (i = i - 1; i >= 0; i--)
                free((*matrix)[i]);
            free(*matrix);
            return ERROR_BUFFER;
        }
    }

    return OK;
}

short int input_matrix(const matrix_t matrix, const int row, const int col)
{
    if (row < 1 || col < 1)
    {
        puts("Некорректный размер матрицы!");
        return ERROR_INPUT_SIZE_MATRIX;
    }

    if (*matrix == NULL)
    {
        puts("Ошибка!");
        return ERROR_BUFFER;
    }

    unsigned short int rc = 0;
    puts("Заполните матрицу: \n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            rc = scanf("%lli", &matrix[i][j]);
            if (rc != 1)
            {
                printf("Ошибка ввода элемента матрицы!\n");
                return ERROR_INPUT;
            }
        }

    return OK;
}

short int print_matrix(const matrix_t matrix, const int row, const int col)
{
    if (row < 1 || col < 1)
    {
        puts("Некорректный размер матрицы!");
        return ERROR_INPUT_SIZE_MATRIX;
    }
    if (*matrix == NULL)
    {
        puts("Ошибка!");
        return ERROR_BUFFER;
    }

    puts("");
    for (int i = 0; i < row; i++)
    {
        puts("");
        for (int j = 0; j < col; j++)
            printf("%lli ", matrix[i][j]);
    }
    puts("");

    return OK;
}
short int destruct(const matrix_t matrix, const int row, const int col)
{
    if (row < 1 || col < 1)
    {
        puts("Некорректный размер матрицы!");
        return ERROR_INPUT_SIZE_MATRIX;
    }

    if (*matrix == NULL)
    {
        puts("Ошибка!");
        return ERROR_BUFFER;
    }

    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return OK;
}

void destruct_arr(lli *arr)
{
    if (arr)
    {
        free(arr);
        arr = NULL;
    }
}