#include <stdio.h>
#define OK 0
#define ERROR 1
#define MAX_LEN 10
#define MIN_LEN 1
#define TRUE 1
#define FALSE 0


int sum_even(const int *arr, const int n);
int scanf_arr(int *arr, int n);
int check(const int *arr, const int n);

int main(void)
{
    int n;
    int rc = scanf("%d", &n);

    if (rc != 1 || n < MIN_LEN || n > MAX_LEN)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }

    int arr[n];

    rc = scanf_arr(arr, n);
    if (rc != n)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }
    if (check(arr, n))
    {
        printf("Нет чётных элементов");
        return ERROR;
    }
    
    printf("\n Сумма чётных элементов массива: %d", sum_even(arr, n));

    return OK;
}

int sum_even(const int *arr, const int n)
{
    int summ = 0;

    for (int i = 0; i < n; i++)
        summ += arr[i] % 2 == 0 ? arr[i] : 0;

    return summ;
}

int check(const int *arr, const int n)
{
    int flag = FALSE;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            flag = TRUE;
            break;
        }
    }
    if (!flag)
        return ERROR;

    return OK;
}

int scanf_arr(int *arr, int n)
{
    int rc = 0;
    printf("Введите элементы массива: \n");
    for (int i = 0; i < n; i++)
        rc += scanf("%d", &arr[i]);
    return rc;
}
