#include "delete.h"
#include "cdio.h"

#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR_BUFFER -2
#define ERROR_DELETE -3
#define CONST_DEL 3
#define DAY_DELETE 1
#define MONTH_DELETE 2
#define YEAR_DELETE 1993
// Удалить из массива экспериментов все эксперименты,
// проведённые не позже 1 февраля 1993 года.

int delete_experiment(experiment_t **array_experiment, int *n)
{
    experiment_t temp;
    int new_n = *n;

    for (int i = *n - 1; i >= 0; i--)
    {
        if (((*array_experiment) + i)->year < 1993 ||
            (((*array_experiment) + i)->year == 1993 && ((*array_experiment) + i)->month < 2) ||
            (((*array_experiment) + i)->year == 1993 && ((*array_experiment) + i)->month == 2 && ((*array_experiment) + i)->day == 1))
        {
            for (int j = i; j < *n - 1; j++)
            {
                temp = (*array_experiment)[j];
                (*array_experiment)[j] = (*array_experiment)[j + 1];
                (*array_experiment)[j + 1] = temp;
                // for (int k = 0; k < *n; k++)
                //     printf("\n%s %d\n", (*array_experiment)[k].surname, (*array_experiment)[k].day);
                // printf("---------");
            }
            new_n--;
            // printf("%d ", temp.day);
        }
    }

    // printf("n_new =  %d \n", new_n);
    if (new_n <= 0)
    {
        printf("Все эксперементы удалены!\n");
        return ERROR_DELETE;
    }
    // *array_experiment = (experiment_t *)realloc(*array_experiment, sizeof(experiment_t) * new_n);

    for (int i = new_n; i < *n; i++)
        destruct_experiment((*array_experiment) + i);

    experiment_t * array_experiment_temp = (experiment_t *)realloc(*array_experiment, sizeof(experiment_t) * new_n);
    if (!array_experiment_temp)
        return ERROR_BUFFER;

    *array_experiment = array_experiment_temp;
    array_experiment_temp = NULL;

    *n = new_n;

    return OK;
}

int delete_average_experiment(experiment_t *array, int n)
{
    float average;
    float *array_temp;

    for (int i = 0; i < n; i++)
    {
        average = 0;
        for (int j = 0; j < array[i].number; j++)
            average += array[i].array_experiment[j];
        // temp.... if....
        array_temp = realloc(array[i].array_experiment, sizeof(float));
        if (!array_temp)
        {
            return ERROR_BUFFER;
        }
        array[i].array_experiment = array_temp;
        array[i].array_experiment[0] = average / array[i].number;
        array[i].number = 1;
    }

    return OK;
}