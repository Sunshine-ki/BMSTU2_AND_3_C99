#include <stdio.h> 
#define ERROR 1
#define OK 0
#define MAX_LEN 10
#define MIN_LEN 1

int scanf_arr(int *arr, const int n);
void del(int *arr, const int num, const int len_arr);
int palindrome(int a);
void print_arr(const int *arr, const int n);
void func(int *arr, int *n);

int main()
{   
    int n;
    printf("Введите кол-во элементов массива(до 10):\n");
    int rc = scanf("%d", &n);
    if (rc != 1 || n > MAX_LEN || n < MIN_LEN)
        return ERROR;

    int arr[n];
    printf("Заполните массив");
    rc = scanf_arr(arr, n);
    if (rc != n)
        return ERROR;

    func(arr, &n);

    if (!n)
        return ERROR;
    print_arr(arr, n);
    return OK;
}

void func(int *arr, int *n)
{
    int i = 0;

    while (i < *n)
    {
        if (palindrome(arr[i])) 
            del(arr, i, (*n)--);
        else
            i++;
    }
}

int scanf_arr(int *arr, const int n)
{
    int rc = 0;

    for (int i = 0; i < n; i++)
        rc += scanf("%d", &arr[i]);

    return rc;
}

int palindrome(int a)
{
    int b = 0, copy_a = a;  

    while (a)
    {
        b *= 10;
        b += a % 10;
        a /= 10;
    }
    if (copy_a == b) 
        return 1;
    else 
        return 0;
}

void del(int *arr, const int num, const int len_arr)
{
    for (int i = num; i < len_arr; i++)
        arr[i] = arr[i + 1];
}

void print_arr(const int *arr, const int n)
{   
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
