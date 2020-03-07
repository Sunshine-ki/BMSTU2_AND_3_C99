#include <stdio.h>
#define OK 0
#define ERROR 1 

int scanf_arr(int *arr, int n)
{	
	int rc = 0;
	for (int i = 1; i < n; i++)
		rc += scanf("%d", &arr[i]);
	if (rc != n - 1)
		return ERROR;
	else 
		return OK;
}

void printf_arr(int *arr, int n)
{
	for (int i = arr[0] == 0 ? 1 : 0; i < n; i++)
		printf("%d ", arr[i]);
}

void func_sum(int *arr_a, int *arr_b, int *arr_new, int n)
{
	arr_b[0] = 0;
	arr_a[0] = 0;
	arr_new[0] = 0;

	int temp = 0, c;
	for (int i = n - 1; i >= 0; i--)
	{
		c = arr_a[i] + arr_b[i] + temp;
		if (c > 10)
		{
			arr_new[i] = c - 10;
			temp = 1;
		}
		else
		{
			arr_new[i] = c;
			temp = 0;
		}
	}	
}


int main()
{
	setbuf(stdout, NULL);
	int n, rc; 

	printf("Введите размерность массивов: ");
	rc = scanf("%d", &n);
	if (rc != 1) return ERROR;
	n += 1;
	int arr_a[n], arr_b[n], arr_new[n];
	// arr_null(arr_a, arr_b, arr_new, n);
	// arr_a[0] = 0, arr_b[0] = 0, arr_new[0] = 0;
	printf("Заполните массив A: ");
	if (scanf_arr(arr_a, n))
		return ERROR;
	printf("Заполните массив B: ");
	if (scanf_arr(arr_b, n))
		return ERROR;
	func_sum(arr_a, arr_b, arr_new, n);
	printf("Новый массив: \n");
	printf_arr(arr_new, n);

	return OK;
}
