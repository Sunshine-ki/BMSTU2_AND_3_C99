/*Лабораторная работа №3
Вывод файла на экран «app.exe p input_file» (print),
Сортировка файла «app.exe s input_file» (sort),
Создание «app.exe t input_file» (touch)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 0
#define TRUE 1
#define MODE 1
#define LEN 5
#define START 5
#define STOP 15
#define ERROR -1
#define NAME_FILE 2
#define COUNT_ARGC 3
#define READ_ERROR -5
#define ERROR_SORT -6
#define ERROR_INPUT -2
#define ERROR_EMPTY -3
#define ERROR_WRITE -4

int print_file(FILE *const f)
{
    int num, count = 0;

    fseek(f, 0, SEEK_SET);
    printf("\n");
    while (fread(&num, sizeof(int), 1, f) == 1)
    {
        printf("%d ", num);
        ++count;
    }

    return count;
}


int write_file(FILE *const f)
{
    int num;
    srand(time(NULL));
    for (int i = 0; i < LEN; i++)
    {
        num = -1 * START + rand() % STOP;
        if (fwrite(&num, sizeof(int), 1, f) != TRUE)
            return ERROR;
    }

    return OK;
}


// Позволяет прочитать число в указанной позиции
int get_number_by_pos(FILE *const f, const int index)
{
    // fseek(f, 0, SEEK_SET);
    int num;

    fseek(f, sizeof(int) * index, SEEK_SET);

    fread(&num, sizeof(int), 1, f);

    return num;
}


// Позволяет записать число в указанную позицию
void put_number_by_pos(FILE *const f, const int index, const int num)
{
    fseek(f, sizeof(int) * index, SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
}


int f_sort(FILE *const f)
{
    int count = 0, temp;

    while (fread(&temp, sizeof(int), 1, f))
        ++count;

    if (!count)
        return ERROR_EMPTY;

    int left = 0, right = count - 1;

    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (get_number_by_pos(f, i) > get_number_by_pos(f, i + 1))
            {
                temp = get_number_by_pos(f, i);
                put_number_by_pos(f, i, get_number_by_pos(f, i + 1));
                put_number_by_pos(f, i + 1, temp);
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (get_number_by_pos(f, i - 1) > get_number_by_pos(f, i))
            {
                temp = get_number_by_pos(f, i - 1);
                put_number_by_pos(f, i - 1, get_number_by_pos(f, i));
                put_number_by_pos(f, i, temp);
            }
        }
        left++;
    }

    return OK;
}


int main(const int argc, const char **const argv)
{
    setbuf(stdout, NULL);

    if (argc != COUNT_ARGC)
    {
        puts("Не достаточно аргументов.");
        return ERROR;
    }

    FILE *f;
    // Заполняем файл рандомными значениями
    if (strcmp(argv[MODE], "t") == OK)
    {
        f = fopen(argv[NAME_FILE], "wb");
        if (!f)
        {
            puts("Некорректные данные.");
            return ERROR_INPUT;
        }
        
        if (write_file(f))
        {
            fclose(f);
            return ERROR;
        }
        printf("Файл успешно заполнен.\n");

        fclose(f);
    }
    // Сортируем файл
    else if (strcmp(argv[MODE], "s") == OK)
    {
        f = fopen(argv[NAME_FILE], "rb + wb");

        if (!f)
        {
            puts("Некорректные данные.");
            return ERROR_INPUT;
        }

        if (f_sort(f))
        {
            fclose(f);
            return ERROR_SORT;
        }
        printf("\nФайл успешно отсортирован!\n");

        fclose(f);
    }
    // Выводим содержимое файлы
    else if ((strcmp(argv[MODE], "p")) == OK)
    {
        f = fopen(argv[NAME_FILE], "rb");
        if (!f)
        {
            puts("Некорректные данные.");
            return ERROR_INPUT;
        }

        if (!print_file(f))
        {
            puts("Файл пуст.\n");
            fclose(f);
            return ERROR_EMPTY;
        }

        fclose(f);
    }
    else 
        puts("Некорректные данные.");
    return OK;
}
