// Уменьшает матрицу.
#include "headers/matrix_reduction.h"
#include "headers/constants.h"
#include "headers/cdio.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Находит индекс (i, j) минимального элемента в матрице
// При обходе по столбцам.
void minimum_element_in_the_matrix(const matrix_t matrix, const int row, const int col, int index[2])
{
    lli min_element = matrix[0][0];
    lli next_element;
    index[0] = 0;
    index[1] = 0;

    // Итерируемся по столбцам
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
        {
            next_element = matrix[j][i];
            if (next_element < min_element)
            {
                min_element = next_element;
                index[0] = j;
                index[1] = i;
            }
        }
}

// Меняет местами ряд матрицы (i)
// И последний элемент.
void swap_row(matrix_t const matrix, const int row, const int col, const int index)
{
    lli *temp;

    for (int i = index; i < row - 1; i++)
    {
        temp = matrix[i];
        matrix[i] = matrix[i + 1];
        matrix[i + 1] = temp;
    }
}

// Меняет местами ряд матрицы j
// И последний элемент.
void swap_col(matrix_t const matrix, const int row, const int col, const int index)
{
    int temp;

    for (int i = index; i < col - 1; i++)
        for (int j = 0; j < row; j++)
        {
            temp = matrix[j][i];
            matrix[j][i] = matrix[j][i + 1];
            matrix[j][i + 1] = temp;
        }
}

// Приводит матрицу к квадратному виду.
int del_matrix_row_col(matrix_t *const matrix, int *const row, int *const col)
{
    int index_1[2];
    int copy_row = *row;
    int copy_col = *col;
    int k = 0;
    index_1[0] = 0;
    index_1[1] = 0;
    matrix_t matrix_temp;

    if (*row > *col)
    {
        while (k < copy_row - copy_col)
        {
            minimum_element_in_the_matrix(*matrix, *row, *col, index_1);
            swap_row(*matrix, copy_row, copy_col, index_1[0]);
            k++, (*row)--;
        }
        for (int i = *row; i < copy_row; i++)
            free((*matrix)[i]);

        *matrix = (matrix_t)realloc(*matrix, (*row) * sizeof(lli *));
        matrix_temp = (matrix_t)realloc(*matrix, (*row) * sizeof(lli *));
        if (matrix_temp)
        {
            *matrix = matrix_temp;
            matrix_temp = NULL;
        }
        else
        {
            destruct(matrix_temp, *row, *col);
            return ERROR_BUFFER;
        }
    }
    else if (*col > *row)
    {
        while (k < copy_col - copy_row)
        {
            minimum_element_in_the_matrix(*matrix, *row, *col, index_1);
            swap_col(*matrix, copy_row, copy_col, index_1[1]);
            k++, (*col)--;
            // for (int i = 0; i < *row; i++)
            //     (*matrix)[i] = (lli *)realloc((*matrix)[i], (*col) * sizeof(lli *));
        }

        lli *temp;

        for (int i = 0; i < *row; i++)
        {
            temp = (lli *)realloc((*matrix)[i], (*col) * sizeof(lli *));

            if (temp)
            {
                (*matrix)[i] = temp;
                temp = NULL;
            }
            else
            {
                destruct_arr(temp);
                return ERROR_BUFFER;
            }
        }
    }
    return OK;
}

// {
//     while (k < copy_col - copy_row)
//     {
//         minimum_element_in_the_matrix(*matrix, *row, *col, index_1);
//         swap_col(*matrix, copy_row, copy_col, index_1[1]);
//         k++, (*col)--;

//         // if (*row == 1)
//         //     return OK;

//         // lli *temp;
//         // for (int i = 0; i < *row; i++)
//         // {
//         //     temp = (lli *)realloc((*matrix)[i], (*col) * sizeof(lli *));

//         //     if (temp)
//         //     {
//         //         (*matrix)[i] = temp;
//         //         temp = NULL;
//         //     }
//         //     else
//         //     {
//         //         destruct_arr(temp);
//         //         return ERROR_BUFFER;
//         //     }
//         (*matrix)[i] = (lli *)realloc((*matrix)[i], (*col) * sizeof(lli *));
//     // }
// }
