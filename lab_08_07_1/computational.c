#include "headers/computational.h"
#include <stdlib.h>
#include <math.h>

// Вычисляет 𝜇1 = 𝜇1(Array)
double function_1(double *const arr, const int len)
{
    double average = 0;

    for (double *p = arr; p < arr + len; p++)    
        average += pow(fabs(*p), 3);
    average = cbrt(average / len);

    // printf("\naverage:%lf\n", average);
    
    return average;
}

double min_element_in_array(double *const arr, const int len)
{
    double mini = *arr;

    for (double *p = arr + 1; p < arr + len; p++)
        if (*p < mini)
            mini = *p;

    return mini;
}
