#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "func.h"
#include "cdio.h"

#define OK 0

#define ERROR_INPUT -1

int value(list *list_polynomial, int a)
{
    list *lst = list_polynomial;
    int sum = 0;

    while (lst)
    {
        sum += lst->number * pow(a, lst->pow_number);
        lst = lst->next_p;
    }

    return sum;
}

void derivative(list *list_polynomial)
{
    list *temp = list_polynomial;

    while (temp) // 2x^2 + 3x^5 + 4x^12 (2 2 3 5 4 12 0 0)
    {
        temp->number *= temp->pow_number;
        (temp->pow_number)--;
        temp = temp->next_p;
    }
}

list *addition(list *list_polynomial_1, list *list_polynomial_2)
{
    list *buf = list_polynomial_1;
    list *buf2 = list_polynomial_2;
    list *list_res = construct(0, 0);

    while (buf && buf2)
    {
        if (buf->pow_number == buf2->pow_number)
        {
            add_element(list_res, buf->number + buf2->number, buf->pow_number + buf2->pow_number);
            buf = buf->next_p;
            buf2 = buf2->next_p;
        }
        else if (buf->pow_number > buf2->pow_number)
        {
            add_element(list_res, buf->number, buf->pow_number);
            buf = buf->next_p;
        }
        else if (buf->pow_number < buf2->pow_number)
        {
            add_element(list_res, buf2->number, buf2->pow_number);
            buf2 = buf2->next_p;
        }
    }

    while (buf)
    {
        add_element(list_res, buf->number, buf->pow_number);
        buf = buf->next_p;
    }
    while (buf2)
    {
        add_element(list_res, buf2->number, buf2->pow_number);
        buf2 = buf2->next_p;
    }

    return list_res;
}

int separation(list *polynomial, list *polynomial_1, list *polynomial_2) // 2 - even
{
    list *temp = polynomial;

    while (temp)
    {
        add_element(temp->pow_number % 2 ? polynomial_2 : polynomial_1, temp->number, temp->pow_number);
        temp = temp->next_p;
    }

    return OK;
}

int mode_function(char answer[LEN_ANSWER])
{
    if (strcmp(answer, "val") == OK)
        return MODE_VAL;
    if (strcmp(answer, "ddx") == OK)
        return MODE_DDX;
    if (strcmp(answer, "sum") == OK)
        return MODE_SUM;
    if (strcmp(answer, "dvd") == OK)
        return MODE_DVD;
    return ERROR_BUFFER;
}