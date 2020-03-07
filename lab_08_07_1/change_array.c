#include "headers/change_array.h"
#include "headers/constants.h"
#include <stdlib.h>
#include <math.h>

// Освобождает место для элемента на позиции index.
// Т.е. двигает все элементы (после index) вправо 
void swap(double *const arr, const int index, const int len)
{
    double *temp;

    for (double *p = arr + len - 1; p > arr + index; p--)
    {
        temp = p;
        *p = *(p - 1);
        *(p - 1) = *temp;
    }
}

// Закидывает в конец массива элемент, 
// Который имеет наменьшую разницу с num 
void swap_array(double *const arr, const int len, const double num)
{   
    double temp = fabs(num - fabs(*arr));
    double next;
    double *index = arr;

    for (double *p = arr + 1; p < arr + len; p++)
    {
        next = fabs(num - fabs(*p));
        if (next < temp)
        { 
            temp = next;
            index = p;
        }    
    }   
    for (double *p = index; p < arr + len - 1; p++)
    {
        index = p;
        *p = *(p + 1);
        *(p + 1) = *index;
    }
}

// Вставляет минимальный элемент в начало,конец и на позицию index
void insert_array(double *const arr, const int len, int index, const double mini)
{
    swap(arr, index, len); 
    swap(arr, 0, len);
    *(arr) = mini;
    *(arr + index + 1) = mini;
    *(arr + len - 1) = mini;
}
