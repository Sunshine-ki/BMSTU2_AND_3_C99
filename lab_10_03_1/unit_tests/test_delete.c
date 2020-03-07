#include "test_delete.h"
#include "constants.h"
#include "delete.h"
#include "cdio.h"

#include <stdlib.h>
#include <stdio.h>

#define OK 0
#define ERROR_TEST 1

int test_delete_identical()
{
    experiment_t * test_exp;
    int len = 3;
    test_exp = (experiment_t *) malloc(sizeof(experiment_t) * len);
    if (test_exp == NULL)
        return ERROR_TEST;
    for (int i = 0; i < len; i++)
    {
        test_exp[i].surname = (char *) malloc(sizeof(char) * 7);
        if (test_exp[i].surname == NULL)
        {
            destruct_array_experiment(&test_exp, len);
            free(test_exp);
            return ERROR_TEST;
        }
        test_exp[i].array_experiment = (float *) malloc(sizeof(float) * 3);
        if (test_exp[i].array_experiment == NULL)
        {
            destruct_array_experiment(&test_exp, len);
            free(test_exp);
            return ERROR_TEST;
        }
        test_exp[i].day = 1;
        test_exp[i].month = 2;
        test_exp[i].year = 2000;
    }

    delete_experiment(&test_exp, &len);

    if (len != 3 || (test_exp[0].day != 1 && test_exp[0].month != 2 && test_exp[0].year != 2000) ||
        (test_exp[1].day != 1 && test_exp[1].month != 2 && test_exp[1].year != 2000) ||
        (test_exp[2].day != 1 && test_exp[2].month != 2 && test_exp[2].year != 2000))
    {
        destruct_array_experiment(&test_exp, len);
        free(test_exp);
        return ERROR_TEST;
    }

    destruct_array_experiment(&test_exp, len);
    free(test_exp);
    return OK;
}

int test_delete_all()
{
    experiment_t * test_exp;
    int len = 3;
    test_exp = (experiment_t *) malloc(sizeof(experiment_t) * len);
    if (test_exp == NULL)
        return ERROR_TEST;
    for (int i = 0; i < len; i++)
    {
        test_exp[i].surname = (char *) malloc(sizeof(char) * 7);
        if (test_exp[i].surname == NULL)
        {
            destruct_array_experiment(&test_exp, len);
            free(test_exp);
            return ERROR_TEST;
        }
        test_exp[i].array_experiment = (float *) malloc(sizeof(float) * 3);
        if (test_exp[i].array_experiment == NULL)
        {
            destruct_array_experiment(&test_exp, len);
            free(test_exp);
            return ERROR_TEST;
        }
        test_exp[i].day = 1;
        test_exp[i].month = 2;
        test_exp[i].year = 1000;
    }

    if (delete_experiment(&test_exp, &len) > 0)
    {
        destruct_array_experiment(&test_exp, len);
        free(test_exp);
        return ERROR_TEST;
    }

    if ((test_exp[0].day != 1 && test_exp[0].month != 2 && test_exp[0].year != 2000) ||
        (test_exp[1].day != 1 && test_exp[1].month != 2 && test_exp[1].year != 2000) ||
        (test_exp[2].day != 1 && test_exp[2].month != 2 && test_exp[2].year != 2000))
    {
        destruct_array_experiment(&test_exp, len);
        free(test_exp);
        return ERROR_TEST;
    }
    // printf("%d", len);

    destruct_array_experiment(&test_exp, len);
    free(test_exp);
    return OK;
}

int test_delete_correct()
{
    experiment_t * test_exp;
    int len = 3;
    test_exp = (experiment_t *) malloc(sizeof(experiment_t) * len);
    if (test_exp == NULL)
        return ERROR_TEST;
    for (int i = 0; i < len; i++)
    {
        test_exp[i].surname = (char *) malloc(sizeof(char) * 7);
        if (test_exp[i].surname == NULL)
        {
            destruct_array_experiment(&test_exp, len);
            free(test_exp);
            return ERROR_TEST;
        }
        test_exp[i].array_experiment = (float *) malloc(sizeof(float) * 3);
        if (test_exp[i].array_experiment == NULL)
        {
            destruct_array_experiment(&test_exp, len);
            free(test_exp);
            return ERROR_TEST;
        }
        test_exp[i].day = 1;
        test_exp[i].month = 2;
        test_exp[i].year = 2000;
    }

    test_exp[0].year = 1000;


    delete_experiment(&test_exp, &len);

    if (len != 2)
    {
        destruct_array_experiment(&test_exp, len);
        free(test_exp);
        return ERROR_TEST;
    }

    // if (len != 3 || (test_exp[0].day != 1 && test_exp[0].month != 2 && test_exp[0].year != 2000) ||
    //     (test_exp[1].day != 1 && test_exp[1].month != 2 && test_exp[1].year != 2000) ||
    //     (test_exp[2].day != 1 && test_exp[2].month != 2 && test_exp[2].year != 2000))
    // {
    //     destruct_array_experiment(&test_exp, len);
    //     free(test_exp);
    //     return ERROR_TEST;
    // }

    // printf("%d len", len);

    destruct_array_experiment(&test_exp, len);
    free(test_exp);
    return OK;
}