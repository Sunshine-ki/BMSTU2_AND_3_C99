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

int not_decrease(int matrix[][MAX_LEN], const int n, const int index)
{   
    if (n == 1)
        return 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (matrix[i + 1][index] >= matrix[i][index])
            return 0;
    }
    return 1;
}

void func(int matrix[][MAX_LEN], int *const arr, const int n, const int m)
{
    for (int i = 0; i < m; i++)
        arr[i] = not_decrease(matrix, n, i);
}

void print_arr(const int *const arr, const int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n, m, rc = 0;
    matrix_variable matrix;

    printf("Введите количество строк\n");
    rc = scanf("%d", &n);
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

    int arr[m];

    rc = scanf_matrix(matrix, n, m);
    if (rc)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }

    func(matrix, arr, n, m);
    print_arr(arr, m);

    return OK;
}

