#include "test_cdio.h"
#include "cdio.h"
#include "constants.h"

#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR_TEST 1



int correct_data_destr_arr()
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
    destruct_array_experiment(&test_exp, len);
    free(test_exp);
    return OK;
}

int correct_name_data_destr()
{
    experiment_t test_exp;
    test_exp.surname = (char*) malloc(sizeof(char) * 5);
    if (test_exp.surname == NULL)
        return ERROR_TEST;
    strcpy(test_exp.surname, "NULL");
    test_exp.array_experiment = NULL;
    destruct_experiment(&test_exp);
    return OK;
}

int correct_arr_data_destr()
{
    experiment_t test_exp;
    test_exp.surname = NULL;
    test_exp.array_experiment = (float *)malloc(sizeof(float) * 5);
    if (test_exp.array_experiment == NULL)
        return ERROR_TEST;
    for (int i = 0; i < 5; i++)
        test_exp.array_experiment[i] = i;
    destruct_experiment(&test_exp);    
    return OK;
}

int null_data_destr_exp()
{
    experiment_t test_exp;
    test_exp.surname = NULL;
    test_exp.array_experiment = NULL;
    destruct_experiment(&test_exp);
    return OK;
}