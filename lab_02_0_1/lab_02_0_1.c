#include<stdio.h>
#define ERROR 1

int expon(int a, int n)
{
    int exp = a;
    
    if (n == 0)
        return 1;
    if (n > 0)
    {   
        while (n > 1)
        {
            exp *= a;
            n--;
        }
        return exp;
    }
    else 
        return ERROR;
}

int main()
{
    int a, n = 0;
    int rc;

    rc = scanf("%d%d", &a, &n);

    if ((n <= 0) || (rc < 2))
        return ERROR;
    else
        printf("a в степени n: %d", expon(a, n));

    return 0;
}
