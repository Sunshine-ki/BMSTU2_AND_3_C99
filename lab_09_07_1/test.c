#include <stdio.h>
#include "headers/cdio_tests.h"
#include "headers/func_multiplication_tests.h"
#include "headers/matrix_reduction_tests.h"
#include "headers/matrix_increase_tests.h"

int main(void)
{
    int count_errors = 0;

    count_errors += test_cdio_square_matr();
    count_errors += test_cdio_rect1_matr();
    count_errors += test_cdio_rect2_matr();
    count_errors += test_cdio_incorrect_data();
    count_errors += test_cdio_empty();
    count_errors += multi_correct_data();
    count_errors += multi_negative_data();
    count_errors += min_elem_correct_first();
    count_errors += min_elem_correct_last();
    count_errors += min_elem_zero();
    count_errors += matrix_increase_correct();
    count_errors += matrix_increase_negative();

    if (count_errors)
        printf("Errors: %d\n", count_errors);

    return 0;
}