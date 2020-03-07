/*
О каждом эксперименте известны дата проведения, 
фамилия проводившего и набор
показаний прибора за день. 
Обрабатывая данные о наборе экспериментов в виде
массива записей.

Удалить из массива экспериментов все эксперименты,
проведённые не позже 1 февраля 1993 года.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "delete.h"
#include "constants.h"
#include "cdio.h"
#include "sort.h"

#define OK 0
#define ERROR_INPUT -1
#define ERROR_BUFFER -2
#define ERROR_DELETE -3

int main(void)
{
    experiment_t * array_experiment = NULL;

    int n = fill_array_experiment(&array_experiment);

    if (n < 0)
    {
        destruct_array_experiment(&array_experiment, n);
        free(array_experiment);
        return ERROR_INPUT;
    }

    if (delete_experiment(&array_experiment, &n))
    {
        destruct_array_experiment(&array_experiment, n);
        free(array_experiment);
        return ERROR_DELETE;
    }

    if (delete_average_experiment(array_experiment, n))
    {
        destruct_array_experiment(&array_experiment, n);
        free(array_experiment);
        return ERROR_BUFFER;
    }

    int (*compare)(experiment_t, experiment_t);
    if (choice_sort(&compare))
    {
        printf("Ошибка ввода ключа!\n");
        destruct_array_experiment(&array_experiment, n);
        free(array_experiment);
        return ERROR_INPUT;
    }

    // sort(array_experiment, n, compare);
    qs_sort(array_experiment, 0, n - 1, compare);

    FILE *f = fopen("results.txt", "w");
    output_to_file(f, array_experiment, n);

    fclose(f);
    destruct_array_experiment(&array_experiment, n);
    free(array_experiment);

    printf("\n");
    return OK;
}