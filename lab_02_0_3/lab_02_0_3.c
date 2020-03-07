#include <stdio.h>
#include <math.h>
#define ERROR 1
#define OK 0

float row_sum(float x, float eps)
{
    float s = 1;
    float temp = 1;
    int i = 1;

    while (fabs(temp) > eps)
    {
        temp = temp * (x / i);
        s += temp;
        i++;
    }
    return s;
}

int error(int rc, float eps)
{
    if (rc != 2 || eps > 1 || eps <= 0)
        return ERROR;
    else
        return OK;
}

int main()
{
    int rc;
    float x, eps;
    float approximate, exact;
    float absolute_error, relative_error;

    printf("Введите x и eps: ");
    rc = scanf("%f %f", &x, &eps);

    if (error(rc, eps))
        return ERROR;

    approximate = row_sum(x, eps);
    exact = expf(x);
    printf("\nПриближенное значение функции: ");
    printf("%f", approximate);
    printf("\nТочное значение функции: %f", exact);

    absolute_error = fabs(exact - approximate);
    printf("\nАбсолютная погрешность: %f", absolute_error);

    relative_error = fabs((exact - approximate) / approximate);
    printf("\nОтносительная погрешность: %f", relative_error);

    return OK;
}
