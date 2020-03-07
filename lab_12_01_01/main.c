#include <stdio.h>
#include <stdlib.h>

#include "cdio.h"
#include "struct.h"
#include "func.h"

#define OK 0

#define LEN_ANSWER 16
#define ERROR_INPUT -1
#define ERROR_BUFFER -2

int main(void)
{
    list *list_polynomial = NULL;
    char answer[LEN_ANSWER];
    printf("Mode (val / ddx / sum / dvd): ");
    scanf("%s", answer);
    int mode = mode_function(answer);

    if (mode > 0)
    {
        if (input_polynomial(stdin, &list_polynomial))
        {
            printf("Error input polynomial");
            destruct(list_polynomial);
            return ERROR_INPUT;
        }
    }
    switch (mode)
    {
    case MODE_VAL:
        printf("\nInput number: ");
        int a;

        if (scanf("%d", &a) != 1)
        {
            printf("Error input number");
            destruct(list_polynomial);
            return ERROR_INPUT;
        }

        int sum = value(list_polynomial, a);
        printf("Sum: %d", sum);

        break;

    case MODE_DDX:

        derivative(list_polynomial);
        output_polynomial(stdout, list_polynomial);

        break;
    case MODE_SUM:
        printf("\n");
        list *list_polynomial2 = NULL;
        if (input_polynomial(stdin, &list_polynomial2))
        {
            printf("Error input polynomial");
            destruct(list_polynomial);
            destruct(list_polynomial2);
            return ERROR_INPUT;
        }

        list *polynomial_res = addition(list_polynomial, list_polynomial2);

        printf("\npolynom res:\n");
        output_polynomial(stdout, polynomial_res);

        destruct(list_polynomial2);
        destruct(polynomial_res);
        break;
    case MODE_DVD:
        printf("\n");
        list *list_polynomial_1 = construct(0, 0);
        list *list_polynomial_2 = construct(0, 0);

        separation(list_polynomial, list_polynomial_1, list_polynomial_2);
        // reverse_polynomial(list_polynomial_1);

        // printf("\npolynom:\n");
        // output_polynomial(stdout, list_polynomial);
        printf("\npolynom 1:\n");
        output_polynomial(stdout, list_polynomial_1);
        printf("\npolynom 2:\n");
        output_polynomial(stdout, list_polynomial_2);

        destruct(list_polynomial_1);
        destruct(list_polynomial_2);
        break;

    default:
        printf("Error input");
        return ERROR_INPUT;
        break;
    }

    printf("\npolynom:\n");
    output_polynomial(stdout, list_polynomial);
    destruct(list_polynomial);

    printf("\n");
    return OK;
}

// list *list_polynomial_1 = construct(0, 0);
// list *list_polynomial_2 = construct(0, 0);
// // list *list_polynomial_1 = NULL;
// // list *list_polynomial_2 = NULL;

// input_polynomial(stdin, &list_polynomial);
// // input_polynomial(stdin, &list_polynomial_1);
// // input_polynomial(stdin, &list_polynomial_2);

// // int sum = value(list_polynomial);
// // printf("SUM : %d", sum);
// // derivative(list_polynomial);
// separation(list_polynomial, list_polynomial_1, list_polynomial_2);
// printf("\npolynom:\n");
// output_polynomial(stdout, list_polynomial);
// printf("\npolynom 1:\n");
// output_polynomial(stdout, list_polynomial_1);
// printf("\npolynom 2:\n");
// output_polynomial(stdout, list_polynomial_2);

// destruct(list_polynomial);
// // destruct(list_polynomial_1);
// // destruct(list_polynomial_2);