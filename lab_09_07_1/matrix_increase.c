// Увеличивает матрицу.
#include "headers/matrix_increase.h"
#include "headers/constants.h"
#include "headers/cdio.h"

#include <stdlib.h>
#include <math.h>

// Увеличивает квадратную матрицу.
// Из matrix[n][n] в matrix[n_new][n_new].
int extend_matrix(matrix_t *const matrix, const int n, int n_new)
{
    if (n < 1 || n_new < 1)
        return ERROR;

    lli *temp;

    for (int i = 0; i < n; i++)
    {
        temp = (lli *)realloc((*matrix)[i], n_new * sizeof(lli *));
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
        // (*matrix)[i] = (lli *)realloc((*matrix)[i], n_new * sizeof(lli *));
    }
    matrix_t matrix_temp;
    // *matrix = (matrix_t)realloc(*matrix, n_new * sizeof(lli *));
    matrix_temp = (matrix_t)realloc(*matrix, n_new * sizeof(lli *));
    if (matrix_temp)
    {
        *matrix = matrix_temp;
        matrix_temp = NULL;
    }
    else
    {
        destruct(matrix_temp, n, n);
        return ERROR_BUFFER;
    }
    for (int i = n; i < n_new; i++)
    {
        temp = (lli *)malloc(n_new * sizeof(lli *));

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
        // (*matrix)[i] = (lli *)malloc(n_new * sizeof(lli *));
    }

    return OK;
}

// Добавляет элементы в строки и стобцы матрицы.
void creature_matrix_row_col(matrix_t const matrix, int *const row, int *const col, const int row_new)
{
    int average = 1;
    lli max;

    // Добавляем среднее геометрическое модулей
    // В конец рядов.
    for (int k = *row; k < row_new; k++)
    {
        for (int i = 0; i < *col; i++)
        {
            for (int j = 0; j < *row; j++)
            {
                average *= abs(matrix[j][i]);
            }
            average = pow(average, 1.0 / *row);
            matrix[*row][i] = average;
            average = 1;
        }
        (*row)++;
    }

    // Добавляет в конец строки
    // Максимальное значение данной строки.
    for (int k = *col; k < *row; k++)
    {
        for (int i = 0; i < *row; i++)
        {
            max = matrix[i][0];
            for (int j = 1; j < *col; j++)
            {
                if (matrix[i][j] > max)
                    max = matrix[i][j];
            }
            matrix[i][*col] = max;
        }
        (*col)++;
    }
}
