#include <stdio.h>
#include <string.h>

#define OK 0
#define MAX_LEN_STR 3
#define MAX_LEN_DEL 3
#define MAX_LEN_SYMBOL 3
#define ERROR 1


// Функция выполняет поиск первого вхождения в строку str1 любого из
// символов строки str2. Возвращает указатель на первое вхождение в str1 
// найденного символа, или — пустой указатель, если нет ни одного совпадения.
// Поиск не учитывает завершающий нуль-символ.
char *my_strpbrk(char *const str1, const char *const str2)
{
    int j = 0;

    while (str1[j])
    {
        for (int i = 0; str2[i]; i++)
            if (str1[j] == str2[i])
                return &str1[j];
        ++j;
    }

    return NULL;
}


// Функция выполняет поиск символов строки str2 в строке str1. 
// Возвращает длину начального участка строки str1 которая 
// состоит только из символов, которые являются частью строки str2.
size_t my_strspn(const char *const str1, const char *const str2)
{
    int count = 0, j;

    for (int i = 0; str1[i]; i++)
    {
        for (j = 0; str2[j]; j++)
            if (str1[i] == str2[j])
            {
                count++;
                break;
            }
        if (!str2[j])
            break;
    }
    return count;
}


// Функция strcspn выполняет поиск первого вхождения
// в строку str1 любого из символов строки str2, 
// и возвращает количество символов до найденного первого вхождения.
// Поиск учитывает и завершающий нуль-символов, поэтому, если 
// функция возвращает длину строки str1, это значит, 
// что  ни один из символов строки str2 не входит в состав str1.
size_t my_strcspn(const char *const str1, const char *const str2)
{
    int i;

    for (i = 0; str1[i]; i++)
        for (int j = 0; str2[j]; j++)
            if (str1[i] == str2[j])
                return i;
    return i;
}


// Функция strchr() возвращает указатель на первое
// вхождение символа ch в строку, на которую указывает str.
// Если символ ch не найден, возвращается NULL.
char *my_strchr(char *const str, const int symbol)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == symbol)
            return &str[i];
        i++;
    }
    if (symbol == '\0')
        return &str[i];

    return NULL;
}

// Функция ищет последнее вхождение символа symbol в строку str.
// Возвращает указатель на последнее вхождение символа в строке str.
// Завершающий нулевой символ считается частью строки. 
// Таким образом, он также может быть найден для получения указателя на конец строки.
char *my_strrchr(char *const str, const int symbol)
{
    if (!str)
        return NULL;

    int index = -1, i = 0;

    while (str[i])
    {
        if (str[i] == symbol)
        {
            index = i;
        }
        i++;
    }
    if (str[i] == symbol)
        index = i;

    if (index == -1)
        return NULL;

    return &str[index];
}


int main(void)
{
    int count_error = 0;
    char *arr_str[MAX_LEN_STR] = { "this Is a test", "oNe two three 4 \0", "Little\0 prince" };
    char *arr_del[MAX_LEN_DEL] = { "ace", "si \0 ht ", " sdqd" };
    char arr_symbol[MAX_LEN_SYMBOL] = { '\0', 'y', '1' };

    for (int i = 0; i < MAX_LEN_STR; i++)
        for (int j = 0; j < MAX_LEN_DEL; j++)
        {
            if (my_strpbrk(arr_str[i], arr_del[j]) != strpbrk(arr_str[i], arr_del[j]))
                printf("strpbrk\ncount : %d index_i : %d, index_j : %d\n\n", \
                    ++count_error, i, j);

            if (my_strspn(arr_str[i], arr_del[j]) != strspn(arr_str[i], arr_del[j]))
                printf("strspn\ncount : %d index_i : %d, index_j : %d\n\n", \
                    ++count_error, i, j);

            if (my_strcspn(arr_str[i], arr_del[j]) != strcspn(arr_str[i], arr_del[j]))
                printf("strcspn\ncount : %d index_i : %d, index_j : %d\n\n", \
                    ++count_error, i, j);

            if (my_strchr(arr_str[i], arr_symbol[j]) != strchr(arr_str[i], arr_symbol[j]))
                printf("strchr\ncount : %d index_i : %d, index_j : %d\n\n", \
                    ++count_error, i, j);    

            if (my_strrchr(arr_str[i], arr_symbol[j]) != strrchr(arr_str[i], arr_symbol[j]))
            {
                printf("%s\n", my_strrchr(arr_str[i], arr_symbol[j]));
                printf("strrchr\ncount : %d index_i : %d, index_j : %d\n\n", \
                    ++count_error, i, j);            
            }
        }
    if (count_error)
        return ERROR;
    printf("No errors!\n");

    return OK;
}