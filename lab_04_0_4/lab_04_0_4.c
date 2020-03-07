#include <stdio.h> 
#define ERROR 1
#define OK 0
#define MAX_LEN 10
#define MIN_LEN 1

int scanf_arr(int *arr, const int n);
void bubble_sort(int *arr, const int n);
void print_arr(const int *arr, const int n);


int main()
{	
    int n;

    printf("Введите кол-во элементов массива:(до 10)\n");
    int rc = scanf("%d", &n);
    if (rc != 1 || n < MIN_LEN || n > MAX_LEN)
        return ERROR;

    int arr[n];
    printf("Заполните массив:\n");
    rc = scanf_arr(arr, n);
    if (rc != n)
        return ERROR;

    bubble_sort(arr, n);
    print_arr(arr, n);

    return OK;
}

int scanf_arr(int *arr, const int n)
{
    int rc = 0;

    for (int i = 0; i < n; i++)
        rc += scanf("%d", &arr[i]);

    return rc;
}

void bubble_sort(int *arr, const int n)
{
    void swap(int *a, int *b);

    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
                swap(&arr[j - 1], &arr[j]);
        }
}

void print_arr(const int *arr, const int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

