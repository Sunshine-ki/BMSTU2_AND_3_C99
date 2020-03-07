#include "headers/func_multiplication.h"
#include "headers/constants.h"
#include "headers/cdio.h"

// Перемножение двух кфадратных матриц.
void multiplication_matrix(matrix_t const matrix_a, matrix_t const matrix_b, matrix_t const matrix_res, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix_res[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                matrix_res[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    // print_matrix(matrix_res, n, n);
}

void identity_matrix(matrix_t const matrix_a, const int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix_a[i][j] = (i == j);
}

// Копирует квадратные матрицы (matrix в matrix_res)
void copy_matrix(matrix_t const matrix_res, matrix_t const matrix, const int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix_res[i][j] = matrix[i][j];
}

// Умножает матрицы (квадратные) по условию:
// Возводит matrix_i в степень pow_i
// Затем данные матрицы перемножаются.
int func_multiplication(matrix_t const matrix_a, matrix_t const matrix_b, matrix_t const matrix_res, const int n, const int pow_1, const int pow_2)
{
    matrix_t matrix_copy_res;

    if (construct(&matrix_copy_res, n, n))
        return ERROR_BUFFER;

    if (pow_1 == 0)
        identity_matrix(matrix_a, n);
    else if (pow_1 > 1)
    {
        multiplication_matrix(matrix_a, matrix_a, matrix_res, n);

        for (int i = 2; i < pow_1; i++)
        {
            copy_matrix(matrix_copy_res, matrix_res, n);
            multiplication_matrix(matrix_copy_res, matrix_a, matrix_res, n);
        }
        copy_matrix(matrix_a, matrix_res, n);
    }
    if (pow_2 == 0)
        identity_matrix(matrix_b, n);
    else if (pow_2 > 1)
    {
        multiplication_matrix(matrix_b, matrix_b, matrix_res, n);
        for (int i = 2; i < pow_2; i++)
        {
            copy_matrix(matrix_copy_res, matrix_res, n);
            multiplication_matrix(matrix_copy_res, matrix_b, matrix_res, n);
        }
        copy_matrix(matrix_b, matrix_res, n);
    }

    multiplication_matrix(matrix_a, matrix_b, matrix_res, n);

    destruct(matrix_copy_res, n, n);

    return OK;
}