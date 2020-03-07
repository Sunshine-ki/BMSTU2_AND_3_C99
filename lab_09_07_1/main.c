#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "headers/cdio.h"
#include "headers/constants.h"
#include "headers/matrix_reduction.h"
#include "headers/matrix_increase.h"
#include "headers/func_multiplication.h"

int main(void)
{
    // Первая матрица.
    matrix_t matrix_a;
    int row_1, col_1;

    printf("Введите размеры первой матрицы: \n");
    int rc = scanf("%d", &row_1);
    if (rc != 1 || row_1 < 1)
    {
        puts("Некорректный размер матрицы!");
        return ERROR_INPUT_SIZE_MATRIX;
    }

    rc = scanf("%d", &col_1);
    if (rc != 1 || col_1 < 1)
    {
        puts("Некорректный размер матрицы!");
        return ERROR_INPUT_SIZE_MATRIX;
    }
    if (col_1 == 1 && row_1 == 1)
    {
        puts("Невозможно получить результат!");
        return ERROR_INPUT_SIZE_MATRIX;
    }

    if (construct(&matrix_a, row_1, col_1))
    {
        // destruct(matrix_a, row, col);
        return ERROR;
    }
    if (input_matrix(matrix_a, row_1, col_1))
    {
        destruct(matrix_a, row_1, col_1);
        return ERROR;
    }

    // Вторая матрица.
    matrix_t matrix_b;
    int row_2, col_2;

    printf("Введите размеры второй матрицы: \n");
    rc = scanf("%d", &row_2);
    if (rc != 1 || row_2 < 1)
    {
        puts("Некорректный размер матрицы!");
        destruct(matrix_a, row_1, col_1);
        return ERROR_INPUT_SIZE_MATRIX;
    }

    rc = scanf("%d", &col_2);
    if (rc != 1 || col_2 < 1)
    {
        puts("Некорректный размер матрицы!");
        destruct(matrix_a, row_1, col_1);
        return ERROR_INPUT_SIZE_MATRIX;
    }
    if (col_2 == 1 && row_2 == 1)
    {
        destruct(matrix_a, row_1, col_1);
        puts("Невозможно получить результат!");
        return ERROR_INPUT_SIZE_MATRIX;
    }

    if (construct(&matrix_b, row_2, col_2))
    {
        // destruct(matrix_b, row, col);
        destruct(matrix_a, row_1, col_1);
        return ERROR;
    }
    if (input_matrix(matrix_b, row_2, col_2))
    {
        destruct(matrix_a, row_1, col_1);
        destruct(matrix_b, row_2, col_2);
        return ERROR;
    }

    int pow_1;
    printf("Введите степень первой матрицы: \n");
    rc = scanf("%d", &pow_1);
    if (rc != 1 || pow_1 < 0)
    {
        puts("Некорректная степень матрицы!");
        destruct(matrix_a, row_1, col_1);
        destruct(matrix_b, row_2, col_2);
        return ERROR_INPUT;
    }

    int pow_2;
    printf("Введите степень второй матрицы: \n");
    rc = scanf("%d", &pow_2);
    if (rc != 1 || pow_2 < 0)
    {
        puts("Некорректная степень матрицы!");
        destruct(matrix_a, row_1, col_1);
        destruct(matrix_b, row_2, col_2);
        return ERROR_INPUT;
    }

    if (del_matrix_row_col(&matrix_a, &row_1, &col_1))
    {
        destruct(matrix_a, row_1, col_1);
        destruct(matrix_b, row_2, col_2);
        return ERROR_BUFFER;
    }
    if (del_matrix_row_col(&matrix_b, &row_2, &col_2))
    {
        destruct(matrix_a, row_1, col_1);
        destruct(matrix_b, row_2, col_2);
        return ERROR_BUFFER;
    }

    int n;

    if (row_1 > row_2)
    {
        if (extend_matrix(&matrix_b, row_2, row_1))
        {
            destruct(matrix_a, row_1, col_1);
            destruct(matrix_b, row_2, col_2);
            return ERROR_BUFFER;
        }
        creature_matrix_row_col(matrix_b, &row_2, &col_2, row_1);
        n = row_1;
    }
    else if (row_1 < row_2)
    {
        if (extend_matrix(&matrix_a, row_1, row_2))
        {
            destruct(matrix_a, row_1, col_1);
            destruct(matrix_b, row_2, col_2);
            return ERROR_BUFFER;
        }
        creature_matrix_row_col(matrix_a, &row_1, &col_1, row_2);
        n = row_2;
    }
    else
        n = row_2;

    matrix_t matrix_res;

    if (construct(&matrix_res, n, n))
    {
        destruct(matrix_a, n, n);
        destruct(matrix_b, n, n);
        return ERROR;
    }

    if (func_multiplication(matrix_a, matrix_b, matrix_res, row_1, pow_1, pow_2))
    {
        destruct(matrix_a, n, n);
        destruct(matrix_b, n, n);
        return ERROR;
    }
    // print_matrix(matrix_a, n, n);
    // print_matrix(matrix_b, n, n);
    print_matrix(matrix_res, n, n);

    destruct(matrix_a, n, n);
    destruct(matrix_b, n, n);
    destruct(matrix_res, n, n);

    puts("");

    return OK;
}