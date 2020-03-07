#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

#include "headers/my_snprintf.h"

// int snprintf (char * restrict s , size_t n , const char * restrict format , ...);
// После успешного завершения функция snprintf () должна вернуть количество байтов,
// которые были бы записаны в s, если бы n было достаточно большим, за исключением завершающего нулевого байта.

int my_str_len(char *str)
{
    if (!str)
        return 0;
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int my_int_len(long long int a)
{
    long long int len = 0;
    while (a)
    {
        a /= 10;
        len++;
    }
    return len;
}

char int_to_char(long long int a)
{
    if (a < 0)
        a *= -1;
    return a + '0';
}

void count_after(char *pointer_buf, int *i, va_list pointer)
{
    // printf(" До %d  ", *i);
    long long int lli;
    long int long_integer;
    int integer;

    while (*pointer_buf)
    {
        // printf(" До %d  ", *i);

        if (*pointer_buf != '%')
        {
            pointer_buf++;
            (*i)++;
            continue;
        }
        pointer_buf++;
        switch (*pointer_buf)
        {
            case 's':
                *i += my_str_len(va_arg(pointer, char *));
                pointer_buf++;
                break;
            case 'd':
                integer = va_arg(pointer, int);
                if (integer < 0)
                    *i += 1;
                *i += my_int_len(integer);
                pointer_buf++;
                break;
            case 'l':
                pointer_buf++;
                if (*pointer_buf == 'd')
                {
                    long_integer = va_arg(pointer, long int);
                    if (long_integer < 0)
                        *i += 1;
                    *i += my_int_len(long_integer);
                    pointer_buf++;
                }
                else if (*pointer_buf == 'l')
                {
                    pointer_buf++;
                    if (*pointer_buf == 'd')
                    {
                        lli = va_arg(pointer, long long int);
                        if (lli < 0)
                            (*i) += 1;
                        *i += my_int_len(lli);
                        pointer_buf++;
                    }
                    else
                    {
                        *i += 1;
                    }
                }
                else
                    *i += 1;
                break;
            default:
                *i += 1;
                break;
        }
    }
}

void write_str_in_buf(char *pointer_buf, int *i, va_list pointer, char *buf)
{
    for (char *temp = va_arg(pointer, char *); *temp; temp++)
    {
        buf[*i] = *temp;
        (*i)++;
    }
}

void write_int_all_in_buf(char *pointer_buf, int *i, va_list pointer, char *buf, int choice)
{
    long long int integer;

    if (choice == INT)
        integer = va_arg(pointer, int);
    else if (choice == LONG_INT)
        integer = va_arg(pointer, long int);
    else
        integer = va_arg(pointer, long long int);
    
    int len = my_int_len(integer);
    // printf("LEN = %d\n", len);

    if (integer < 0)
    {
        buf[*i] = '-';
        (*i)++;
    }

    for (int j = len - 1; j >= 0; j--)
    {
        buf[*i] = int_to_char(integer / (long long int)pow(10, j));
        // printf("%c", int_to_char(integer / (int)pow(10, j)));
        // printf("%d", integer / (int)pow(10, j));
        integer = integer - ((integer / (long long int)pow(10, j)) * (long long int)pow(10, j));
        (*i)++;
    }
}

int my_snprintf(char *buf, ...)
{
    int i = 0;

    // Специальный тип данных va_list
    // который позволяет обрабатывать списки
    // параметров с нефиксированным количеством.
    va_list pointer;

    // va_list выступает в данной роли как указатель
    // Первый параметр макроса - param связывает
    //  объект va_list с первым необязательным параметром
    va_start(pointer, buf);

    int len = va_arg(pointer, int);
    if (len < 0)
        return ERROR;

    for (char *pointer_buf = va_arg(pointer, char *); *pointer_buf; pointer_buf++)
    {
        // printf("i = %d ", i);
        if (i >= len - 1 || buf == NULL)
        {
            if (buf)
                buf[i] = '\0';

            count_after(pointer_buf, &i, pointer);
            return i;
        }
        if (*pointer_buf != '%')
        {
            buf[i] = *pointer_buf;
            i++;
            continue;
        }
        pointer_buf++;
        switch (*pointer_buf)
        {
            case 'l':
                pointer_buf++;
                if (*pointer_buf == 'l')
                {
                    pointer_buf++;                    
                    write_int_all_in_buf(pointer_buf, &i, pointer, buf, LONG_LONG_INT);
                }
                else 
                    write_int_all_in_buf(pointer_buf, &i, pointer, buf, LONG_INT);
                break;
            case 'd':
                write_int_all_in_buf(pointer_buf, &i, pointer, buf, INT);
                break;
            case 's':
                write_str_in_buf(pointer_buf, &i, pointer, buf);
                break;
            default:
                buf[i] = '%';
                i++;
                buf[i] = *pointer_buf;
                i++;
                break;
        }
    }

    buf[i] = '\0';

    // Макрос позволяет выйти из функции
    // с переменным списком параметров.
    va_end(pointer);

    return i;
}