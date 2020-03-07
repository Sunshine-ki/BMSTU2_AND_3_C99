#include "test_sort.h"
#include "cdio.h"
#include "constants.h"
#include "sort.h"
#include "delete.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define OK 0
#define ERROR_TEST 1
#define EPS 1e-5


int test_sort_correct_str()
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
    }

    strcpy(test_exp[0].surname, "Dog");
    strcpy(test_exp[1].surname, "Cat");
    strcpy(test_exp[2].surname, "Fox");

    int (*compare)(experiment_t, experiment_t);
    compare = str_cmp;

    qs_sort(test_exp, 0, len - 1, compare);

    // printf("%s %s %s", test_exp[0].surname, test_exp[1].surname, test_exp[2].surname);
    if (strcmp(test_exp[0].surname, "Cat") != 0 || strcmp(test_exp[1].surname, "Dog") != 0 ||
        strcmp(test_exp[2].surname, "Fox") != 0)
    {
        destruct_array_experiment(&test_exp, len);
        free(test_exp);
        return ERROR_TEST;
    }

    destruct_array_experiment(&test_exp, len);
    free(test_exp);
    return OK;
}


int test_sort_str_identic()
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
    }

    strcpy(test_exp[0].surname, "Fox");
    strcpy(test_exp[1].surname, "Fox");
    strcpy(test_exp[2].surname, "Fox");

    int (*compare)(experiment_t, experiment_t);
    compare = str_cmp;

    qs_sort(test_exp, 0, len - 1, compare);

    if (strcmp(test_exp[0].surname, "Fox") != 0 || strcmp(test_exp[1].surname, "Fox") != 0 ||
        strcmp(test_exp[2].surname, "Fox") != 0)
    {        
        destruct_array_experiment(&test_exp, len);
        free(test_exp);
        return ERROR_TEST;
    }

    destruct_array_experiment(&test_exp, len);
    free(test_exp);
    return OK;
}

int test_sort_arr_identic()
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
        test_exp[i].array_experiment = (float *) malloc(sizeof(float));
        if (test_exp[i].array_experiment == NULL)
        {
            destruct_array_experiment(&test_exp, len);
            free(test_exp);
            return ERROR_TEST;
        }
        test_exp[i].array_experiment[0] = i;
    }
    

    int (*compare)(experiment_t, experiment_t);
    compare = float_cmp;

    qs_sort(test_exp, 0, len - 1, compare);

    // for (int j = 0; j < len; j++)
    //     printf("%lf ", test_exp[j].array_experiment[0]);

    if ((test_exp[0].array_experiment[0] > EPS) || (test_exp[1].array_experiment[0] - 1 > EPS) ||
        (test_exp[2].array_experiment[0] - 2 > EPS))
    {
        destruct_array_experiment(&test_exp, len);
        free(test_exp);
        return ERROR_TEST;
    }

    destruct_array_experiment(&test_exp, len);
    free(test_exp);
    return OK;
}

int test_sort_arr_negative()
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
        test_exp[i].array_experiment = (float *) malloc(sizeof(float));
        if (test_exp[i].array_experiment == NULL)
        {
            destruct_array_experiment(&test_exp, len);
            free(test_exp);
            return ERROR_TEST;
        }
        test_exp[i].array_experiment[0] = -i;
    }
    

    int (*compare)(experiment_t, experiment_t);
    compare = float_cmp;

    qs_sort(test_exp, 0, len - 1, compare);

    // for (int j = 0; j < len; j++)
        // printf("%lf ", test_exp[j].array_experiment[0]);

    if ((test_exp[2].array_experiment[0] > EPS) || (test_exp[1].array_experiment[0] + 1 > EPS) ||
        (test_exp[0].array_experiment[0] + 2 > EPS))
    {
        destruct_array_experiment(&test_exp, len);
        free(test_exp);
        return ERROR_TEST;
    }

    destruct_array_experiment(&test_exp, len);
    free(test_exp);
    return OK;
}

int test_sort_data_identic()
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

    int (*compare)(experiment_t, experiment_t);
    compare = date_cmp;

    qs_sort(test_exp, 0, len - 1, compare);

    if ((test_exp[0].day != 1 && test_exp[0].month != 2 && test_exp[0].year != 2000) ||
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