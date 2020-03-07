#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERROR 1
#define MAX_LEN 20
#define MIN_LEN 1

typedef int matrix_variable[MAX_LEN][MAX_LEN];

int scanf_matrix(int matrix[][MAX_LEN], const int n, const int m)
{
    int rc = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rc += scanf("%d", &matrix[i][j]);
        }
    }
    if (rc != m * n)
        return ERROR;
    else
        return OK;
}

void print_matrix(int matrix[][MAX_LEN], const int n, const int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\n");
        for (int j = 0; j < m; j++)
            printf("%5d", matrix[i][j]);
    }
}

int count_start(const int *const arr, const int n, const int num)
{
    int temp, count = 0;

    for (int i = 0; i < n; i++)
    {
        temp = abs(arr[i]);
        while (temp >= 10)
            temp /= 10;
        if (num == temp)
            count++;
    }

    return count;
}

int count_end(const int *const arr, const int n, const int num)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i]) % 10 == num)
            count++;
    }

    return count;
}

void move_row(int matrix[][MAX_LEN], const int n, const int m, const int index)
{
    for (int i = n; i != index; i--)
        for (int j = 0; j < m; j++)
            matrix[i][j] = matrix[i - 1][j];
}

void insert(int *const arr, const int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 100;
}

int func(int matrix[][MAX_LEN], const int n, const int m, const int num)
{
    int n_new = n, c_s, c_e;

    for (int i = 0; i < n_new; i++)
    {
        c_s = count_start(matrix[i], m, num);
        c_e = count_end(matrix[i], m, num);
        if (c_s == c_e && c_s != 0)
        {
            n_new++;
            move_row(matrix, n_new, m, i + 1);
            insert(matrix[i + 1], m);
            i++;
        }
    }
    return n_new;
}

int main(void)
{
    int n, m, num, n_new;
    matrix_variable matrix;

    printf("Введите количество строк\n");
    int rc = scanf("%d", &n);
    if (rc != 1 || n < MIN_LEN || n > MAX_LEN / 2)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }
    printf("Введите количество столбцов\n");
    rc = scanf("%d", &m);
    if (rc != 1 || m < MIN_LEN || m > MAX_LEN)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }
    printf("Введите элементы матрицы\n");
    rc = scanf_matrix(matrix, n, m);
    if (rc)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }
    printf("Введите число\n");
    rc = scanf("%d", &num);
    if (rc != 1 || num < 0 || num > 9)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }

    n_new = func(matrix, n, m, num);
    print_matrix(matrix, n_new, m);

    return OK;
}
