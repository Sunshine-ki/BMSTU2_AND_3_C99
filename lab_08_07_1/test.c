#include <stdio.h>
#include "headers/test_cdio_array.h"
#include "headers/test_computational.h"
#include "headers/test_change_array.h"
#include "headers/constants.h"

int main(void)
{
    int count_error = 0;

    count_error += tests_cdio_array();
    count_error += tests_comput_correct();
    count_error += tests_comput_null_data();
    count_error += tests_comput_negative_data();
    count_error += tests_comput_negativ_positiv();
    count_error += tests_change_negative_elem();
    count_error += tests_change_array();
    count_error += tests_change_identical();
    count_error += tests_change_correct_data();
    count_error += test_min_element_correct();
    count_error += test_min_element_negative();
    count_error += test_min_elem_negativ_positiv();
    count_error += test_min_element_null_data();

    if (count_error)
    {
        printf("\nОшибок: %d\n", count_error);
        return count_error;
    }
    printf("Ошибок нет!\n");

    return OK;
}
