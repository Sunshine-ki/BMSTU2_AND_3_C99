/*
Лабораторная работа № 7.
Вариант 2.
Тип обрабатываемых файлов: Текстовый.
Параметры командной строки(Запуск программы):

1.Упорядочивает информацию о товаре
по убыванию цены за единицу товара:
«app.exe st file_in file_out»

2.Выводит на экран информацию о товарах,
наименование которых заканчивается
на заданную подстроку:
«app.exe ft file_in substr»

3.Добавляет информацию о новом товаре
в уже упорядоченную последовательность
товаров так, чтобы упорядоченность не нарушилась.
«app.exe at file_in_out»
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 0
#define TRUE 1
#define FALSE 0
#define MODE 1
#define NAME_FILE_IN 2
#define NAME_FILE_OUT 3
#define SUBSTRING 3
#define MAX_LEN_NAME 31
#define MAX_LEN_MANUFACTURER 16
#define MAX_LEN_STRING 100
#define MAX_QUANTITY_PRODUCT 100
// #define ERROR_OPEN_FILE -1
#define ERROR_EMPTY -2
#define ERROR_FILL -3
#define ERROR_INFO -4
#define ERROR_PARAMETERS 53

typedef struct
{
    char name[MAX_LEN_NAME];
    char manufacturer[MAX_LEN_MANUFACTURER];
    int price;
    int quantity;
} product;


int my_strstr(char const *const str, char const *const str_sub, int len_sub)
{
    int len_str = 0;
    while (str[len_str])
        len_str++;
    if (len_sub > len_str)
        return FALSE;
    for (int i = len_sub - 1, j = len_str - 1; i >= 0; i--, j--)
    {
        if (str[j] != str_sub[i])
            return FALSE;
    }

    return TRUE;
}

int print_info(const product arr[MAX_QUANTITY_PRODUCT],
    const char *const substr, const int len)
{
    int len_sub = 0;
    int flag = TRUE;

    while (substr[len_sub])
        len_sub++;

    for (int j = 0; j < len; j++)
    {
        if (my_strstr(arr[j].name, substr, len_sub))
        {
            printf("%s\n%s\n%d\n%d\n", arr[j].name, arr[j].manufacturer,
                arr[j].price, arr[j].quantity);
            flag = FALSE;
        }
    }

    return flag;
}

void write_file(FILE *const f, const product
    arr[MAX_QUANTITY_PRODUCT], const int len)
{
    fprintf(f, "%s\n%s\n%d\n%d", arr[0].name, arr[0].manufacturer,
        arr[0].price, arr[0].quantity);
    for (int j = 1; j < len; j++)
    {
        fprintf(f, "\n%s\n%s\n%d\n%d", arr[j].name, arr[j].manufacturer,
            arr[j].price, arr[j].quantity);
    }
}

// Вывод структуры (Для себя)
// void print_struct(const product arr[MAX_QUANTITY_PRODUCT], const int len)
// {
//     for (int j = 0; j < len; j++)
//         printf("%s\n%s\n%d\n%d\n", arr[j].name, arr[j].manufacturer,
//             arr[j].price, arr[j].quantity);
// }

void swap_struct(product arr[MAX_QUANTITY_PRODUCT], const int i, const int j)
{
    product temp;
    temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void sort_struct(product arr[MAX_QUANTITY_PRODUCT], const int len)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j].price < arr[j + 1].price)
                swap_struct(arr, j, j + 1);
            else if (arr[j].price == arr[j + 1].price &&
                arr[j].quantity < arr[j + 1].quantity)
                swap_struct(arr, j, j + 1);
            // else if (arr[j].price == arr[j + 1].price &&
            //     arr[j].quantity == arr[j + 1].quantity &&
            //     strcmp(arr[j].name, arr[j + 1].name) == 1)
            //     swap_struct(arr, j, j + 1);
        }
}

int fill(FILE *const f, product arr[MAX_QUANTITY_PRODUCT])
{
    int i = 0;
    // int rc = 0;
    fseek(f, 0, SEEK_SET);
    while (TRUE)
    {
        if (feof(f))
            break;
        fgets(arr[i].name, MAX_LEN_NAME, f);
        for (int j = 0; j < MAX_LEN_NAME; j++)
            if (arr[i].name[j] == '\n')
            {
                arr[i].name[j] = '\0';
                break;
            }
        // printf("!%s!\n", arr[i].name);
        fgets(arr[i].manufacturer, MAX_LEN_MANUFACTURER, f);
        for (int j = 0; j < MAX_LEN_MANUFACTURER; j++)
            if (arr[i].manufacturer[j] == '\n')
            {
                arr[i].manufacturer[j] = '\0';
                break;
            }
        fscanf(f, "%d\n%d\n", &(arr[i].price), &(arr[i].quantity));
        // if (rc != 2)
        // {
        //     // puts("Неккоректные данные!");
        //     return ERROR_FILL;
        // }
        i++;
    }

    return i;
}

int fill_new_info(product *new_info)
{
    fgets(new_info->name, MAX_LEN_NAME, stdin);
    for (int j = 0; j < MAX_LEN_NAME; j++)
        if (new_info->name[j] == '\n')
        {
            new_info->name[j] = '\0';
            break;
        }
    fgets(new_info->manufacturer, MAX_LEN_MANUFACTURER, stdin);
    for (int j = 0; j < MAX_LEN_MANUFACTURER; j++)
        if (new_info->manufacturer[j] == '\n')
        {
            new_info->manufacturer[j] = '\0';
            break;
        }
    const int rc = scanf("%d\n%d", &(new_info->price), &(new_info->quantity));
    if (rc != 2)
    {
        // puts("Неккоректные данные!");
        return ERROR_FILL;
    }

    return OK;
}

void add_struct(product arr[MAX_QUANTITY_PRODUCT], const int len)
{
    int i = len - 1;

    while (i && arr[i - 1].price <= arr[i].price)
    {
        if (arr[i - 1].price == arr[i].price &&
            arr[i - 1].quantity < arr[i].quantity)
            swap_struct(arr, i, i - 1);
        else if (arr[i - 1].price < arr[i].price)
            swap_struct(arr, i, i - 1);
        i--;
    }
}

int error_substr(char substr[MAX_LEN_STRING])
{
    int i = 0;
    while (substr[i])
    {
        if (i > MAX_LEN_NAME)
            return TRUE;
        i++;
    }

    return FALSE;
}

int main(const int argc, const char **const argv)
{
    setbuf(stdout, NULL);

    if (argc != 4 && argc != 3)
    {
        puts("Недостаточно аргументов!\n");
        return ERROR_PARAMETERS;
    }
    // print_struct(array_product, len);

    if (strcmp(argv[MODE], "st") == OK)
    {
        if (argc != 4)
            return ERROR_PARAMETERS;

        FILE *f = fopen(argv[NAME_FILE_IN], "r");
        if (!f)
        {
            // fclose(f);
            return ERROR_FILL;
        }
        if (getc(f) == EOF)
        {
            puts("Файл пуст!");
            fclose(f);
            return ERROR_EMPTY;
        }
        product array_product[MAX_QUANTITY_PRODUCT];
        const int len = fill(f, array_product);
        if (len <= 0)
        {
            fclose(f);
            return ERROR_FILL;
        }
        FILE *f_out = fopen(argv[NAME_FILE_OUT], "w");

        if (!f_out)
        {
            fclose(f);
            return ERROR_FILL;
        }

        sort_struct(array_product, len);
        puts("\nИнформация успешно упорядочена!");
        write_file(f_out, array_product, len);
        puts("\nИнформация успешно записана в новый файл!");
        fclose(f_out);
        fclose(f);
    }
    else if (strcmp(argv[MODE], "ft") == OK)
    {
        if (argc != 4)
            return ERROR_PARAMETERS;
        FILE *f = fopen(argv[NAME_FILE_IN], "r");
        if (!f)
        {
            // fclose(f);
            return ERROR_FILL;
        }
        if (getc(f) == EOF)
        {
            puts("Файл пуст!");
            fclose(f);
            return ERROR_EMPTY;
        }

        product array_product[MAX_QUANTITY_PRODUCT];
        const int len = fill(f, array_product);
        if (len <= 0)
        {
            fclose(f);
            return ERROR_FILL;
        }
        char substr[MAX_LEN_STRING];
        strcpy(substr, argv[SUBSTRING]);
        if (error_substr(substr))
        {
            puts("Неверная подстрока!");
            fclose(f);
            return ERROR_INFO;
        }
        // puts("Информация: \n");
        if (print_info(array_product, substr, len))
        {
            fclose(f);
            return ERROR_INFO;
        }
        fclose(f);
    }
    else if (strcmp(argv[MODE], "at") == OK)
    {
        if (argc != 3)
            return ERROR_PARAMETERS;
        FILE *f = fopen(argv[NAME_FILE_IN], "r");
        if (!f)
        {
            // fclose(f);
            return ERROR_FILL;
        }
        if (getc(f) == EOF)
        {
            puts("Файл пуст!");
            fclose(f);
            return ERROR_EMPTY;
        }

        product array_product[MAX_QUANTITY_PRODUCT];
        int len = fill(f, array_product);
        if (len <= 0)
        {
            fclose(f);
            return ERROR_FILL;
        }
        product new_info;
        fclose(f);
        puts("Введите информацию о товаре:\n");
        if (fill_new_info(&new_info) != OK)
            return ERROR_INFO;
        array_product[len] = new_info;
        len++;
        f = fopen(argv[NAME_FILE_IN], "w");
        add_struct(array_product, len);
        write_file(f, array_product, len);
        fclose(f);
        puts("Информация успешно записана!");
    }
    else
    {
        puts("Некорректные аргументы!");
        // fclose(f);
        return ERROR_PARAMETERS;
    }

    return OK;
}
