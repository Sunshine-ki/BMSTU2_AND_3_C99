#include <stdio.h>

#include "constants.h"
#include "test_cdio.h"
#include "test_sort.h"
#include "test_delete.h"

#define OK 0
#define ERROR -1

int main(void)
{
    if (correct_name_data_destr())
    {
        printf("Error correct_name_data_destr()");
        return ERROR;
    }
    if (correct_arr_data_destr())
    {
        printf("Error correct_arr_data_destr()");
        return ERROR;
    }
    if (null_data_destr_exp())
    {
        printf("Error null_data_destr_exp()");
        return ERROR;
    }
    if (test_sort_correct_str())
    {
        printf("Error test_sort_correct_str()");
        return ERROR;
    }
    if (correct_data_destr_arr())
    {
        printf("Error correct_data_destr_arr()");
        return ERROR;
    }
    if (test_sort_arr_identic())
    {
        printf("Error test_sort_arr_identic()");
        return ERROR;
    }

    if (test_delete_identical())
    {
        printf("Error test_delete_identical()");
        return ERROR;
    }
    if (test_delete_correct())
    {
        printf("Error test_delete_correct()");
        return ERROR;
    }
    if (test_delete_all())
    {
        printf("Error test_delete_all()");
        return ERROR;
    }

    printf("Все тесты прошли!\n");

    return OK;
}
