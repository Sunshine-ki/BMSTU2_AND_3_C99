#include <stdio.h>
#include <stdlib.h>

#include "headers/constants.h"
#include "headers/cdio_tests.h"
#include "headers/cdio.h"

// Квадратная
int test_cdio_square_matr()
{
    matrix_t matrix;
    int row = 4;
    int col = 4;
    if (construct(&matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    if (destruct(matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    return OK;
}

// Прямоугольная (row > col)
int test_cdio_rect1_matr()
{
    matrix_t matrix;
    int row = 4;
    int col = 2;
    if (construct(&matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    if (destruct(matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    return OK;
}

// Прямоугольная (row < col)
int test_cdio_rect2_matr()
{
    matrix_t matrix;
    int row = 2;
    int col = 4;
    if (construct(&matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    if (destruct(matrix, row, col) != OK)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    return OK;
}

// Отрицательные размеры
int test_cdio_incorrect_data()
{
    matrix_t matrix;
    int row = -2;
    int col = -4;
    if (construct(&matrix, row, col) != ERROR_INPUT_SIZE_MATRIX)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    return OK;
}

// Пустая матрица
int test_cdio_empty()
{
    matrix_t matrix;
    int row = 0;
    int col = 0;
    if (construct(&matrix, row, col) != ERROR_INPUT_SIZE_MATRIX)
    {
        printf("Ошибка!");
        return ERROR_TEST;
    }

    return OK;
}