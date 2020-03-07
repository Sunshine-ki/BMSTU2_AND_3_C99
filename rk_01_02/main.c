#include <stdio.h>
#include <math.h>

#define READED 1
#define YES 1
#define NO 0
#define ERROR 1
#define OK 0


int check_simple(int num)
{
	if (num == 1)
		return NO;
	for (int i = 2; i < (int) sqrt(num) + 1; i++)
		if (num % i == 0)
			return NO;
	return YES;
}

void fib(int *a, int *b)
{
	int temp;
	temp = *b;
	*b += *a;
	*a = temp;
}
	
int main()
{
	int n;

	if (scanf("%d", &n) != READED)
		return ERROR;

 	int a = 1;
	for (int b = 2; b < n;)
	{
		fib(&a, &b);
		if (check_simple(b))
			printf("%d ", b);
	}

	return OK;
}


