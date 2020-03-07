#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "cdio.h"

#define OK 0
#define TRUE 1
#define FALSE 0

#define ERROR_INPUT -1
#define ERROR_BUFFER -2

list *construct(int num, int pow_num)
{
    list *lst;
    lst = (list *)malloc(sizeof(list));
    lst->number = num;
    lst->pow_number = pow_num;
    lst->next_p = NULL;
    return lst;
}

list *add_element(list *list_polynomial, int num, int pow_num)
{
    list *temp;

    temp = (list *)malloc(sizeof(list));

    temp->pow_number = pow_num;
    temp->number = num;
    temp->next_p = list_polynomial->next_p;
    list_polynomial->next_p = temp;

    return temp;
}

int input_polynomial(FILE *f, list **list_polynomial)
{
    int num, pow_num;

    printf("Input polynomial: ");

    if (fscanf(stdin, "%d %d", &num, &pow_num) != 2)
        return ERROR_INPUT;

    *list_polynomial = construct(num, pow_num);

    if (*list_polynomial == NULL)
        return ERROR_BUFFER;

    if (num == 0 && pow_num == 0)
        return OK;

    list *temp = *list_polynomial;

    while (TRUE)
    {
        if (fscanf(stdin, "%d %d", &num, &pow_num) != 2)
            return ERROR_INPUT;

        if (num == 0 && pow_num == 0)
            break;

        temp = add_element(temp, num, pow_num);

        if (temp == NULL)
            return ERROR_BUFFER;
    }

    return OK;
}

void output_polynomial(FILE *f, list *list_polynomial)
{
    list *temp = list_polynomial;
    if (!temp)
        return;
    while (TRUE)
    {
        if (temp->number) // 0 0 OR 0 1
            fprintf(f, "%d %d ", temp->number, temp->pow_number);
        if (temp->next_p == NULL)
            break;
        temp = temp->next_p;
    }
    fprintf(f, "L");
}

void destruct(list *list_polynomial)
{
    if (!list_polynomial)
        return;

    list *temp = list_polynomial;
    list *p = list_polynomial->next_p;

    while (TRUE)
    {
        free(temp);
        temp = p;
        if (temp == NULL)
            break;
        p = temp->next_p;
    }
}