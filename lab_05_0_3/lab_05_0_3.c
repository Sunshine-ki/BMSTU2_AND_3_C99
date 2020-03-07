#include <stdio.h>
#define OK 0
#define ERROR 1
#define MAX_LEN 10
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
        printf("\n");
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
    }
}

void sum_row(int matrix[][MAX_LEN], int *const arr, const int n, const int m)
{
    int summ;

    for (int i = 0; i < n; i++)
    {
        summ = 0;
        for (int j = 0; j < m; j++)
        {
            summ += matrix[i][j];
        }
        arr[i] = summ;
    }
}

void func(int matrix[][MAX_LEN], int *const arr, const int n, const int m)
{
    void swap(int *a, int *b);
    int arr_index[n];
    matrix_variable matrix_copy;

    for (int i = 0; i < n; i++)
        arr_index[i] = i;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            matrix_copy[i][j] = matrix[i][j];
    }

    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
                swap(&arr_index[j - 1], &arr_index[j]);
            }
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            matrix[i][j] = matrix_copy[arr_index[i]][j];
    }
}

void swap(int *const a, int *const b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, m;
    matrix_variable matrix;

    printf("Введите количество строк\n");
    int rc = scanf("%d", &n);
    if (rc != 1 || n < MIN_LEN || n > MAX_LEN)
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

    int arr[n];
    printf("Введите элементы массива\n");
    rc = scanf_matrix(matrix, n, m);
    if (rc)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }

    sum_row(matrix, arr, n, m);
    func(matrix, arr, n, m);
    print_matrix(matrix, n, m);

    return OK;
}
