#include <stdio.h> 
#define OK 0
#define ERROR 1
#define MAX_LEN 10
#define MIN_LEN 1

int scanf_arr(int *arr, const int n);
int count(int *arr, const int n, const int average);
int summ(const int *arr, const int n);
void copy_arr(const int *arr, int *arr_new, const int n, const int average);
void print_arr(const int *arr, const int n);

int main()
{
    int n;
    int average, quantity;
    
    printf("Введите кол-во элементов массива (до 10):\n");
    int rc = scanf("%d", &n);

    if (rc != 1 || n < MIN_LEN || n > MAX_LEN)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }

    int arr[n];

    printf("Заполните массив:\n");
    rc = scanf_arr(arr, n);
    if (rc != n)
    {
        printf("Некорректные данные\n");
        return ERROR;
    }

    average = summ(arr, n) / n;
    //Считаем количество элементов больше среднего арифметического
    quantity = count(arr, n, average);
    if (quantity == 0)
        return ERROR;

    int arr_new[quantity];
    copy_arr(arr, arr_new, n, average);
    print_arr(arr_new, quantity);

    return OK;	
}

int scanf_arr(int *arr, const int n)
{
    int rc = 0;

    for (int i = 0; i < n; i++)
        rc += scanf("%d", &arr[i]);

    return rc;
}

int count(int *arr, const int n, const int average)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        count += arr[i] > average ? 1 : 0;

    return count;
}

int summ(const int *arr, const int n)
{
    int summ = 0;

    for (int i = 0; i < n; i++)
        summ += arr[i];

    return summ;
}

void copy_arr(const int *arr, int *arr_new, const int n, const int average)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - average > 0)
            arr_new[j++] = arr[i];
    }
}

void print_arr(const int *arr, const int n)
{	
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
