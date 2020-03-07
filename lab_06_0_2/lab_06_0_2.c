#include <stdio.h>

#define OK 0
#define TRUE 1
#define FALSE 0
#define MAX_LEN 215
#define MAX_LEN_WORD 16
#define ERROR -1
#define ERROR_LEN -2
#define ERRROR_EMPTY -3
#define ERROR_NUMBER -4

const int my_strcmp(char *const str1, char *const str2)
{
    int i = 0;
    int len1 = 0;
    int len2 = 0;

    while (str1[len1])
    	len1++;
    while (str2[len2])
    	len2++;
    if (len1 != len2)
    	return FALSE;
    while (str1[i])
    {
        if (str1[i] != str2[i])
            return FALSE;
        i++;
    }
    return TRUE;
}


// Проверяем, встречалось ли слово до index
int func(char str_word[MAX_LEN_WORD][MAX_LEN], char *const word, const int index)
{
    if (index == 0)
        return TRUE;
    for (int i = index; i > 0; i--)
    {
        if (my_strcmp(str_word[i - 1], word))
            return FALSE;
    }
    return TRUE;
}

void print_word(char str_word[MAX_LEN_WORD][MAX_LEN], const int len, int *const arr_key)
{
    printf("Result:");
    for (int i = 0; i < len && str_word[i][0] != ' ' && str_word[i][0] != '\0'; i++)
    {
        if (func(str_word, str_word[i], i))
        {
            printf("%s %d\n", str_word[i], arr_key[i]);
        }
    }
}

// Кол-во встреч
void count_meeting(char matrix[MAX_LEN_WORD][MAX_LEN], const int len, int *const arr)
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        count = 0;
        for (int j = 0; j < len; j++)
            if (my_strcmp(matrix[i], matrix[j]))
                count++;
        arr[i] = count;
    }
}

const int my_split(char *const str, char matrix[MAX_LEN][MAX_LEN], int len)
{
    int row = 0, column = 0;
    int index = 0;
    char *del = ",;:-.!?";
    char symbol = ' ';

    // Заполняем единственным разделителем
    for (int i = 0; str[i]; i++)
        for (int j = 0; del[j]; j++)
            if (str[i] == del[j])
            {
                str[i] = symbol;
                break;
            }
    // Убираем разделители в начале и конце
    while (str[index] == symbol)
        index++;
    // len--;
    while (str[len] == symbol)
        len--;

    // Проверяем наличие слов
    if (index == len)
        return ERRROR_EMPTY;

    // Разбиваем строку на слова
    while (index < len)
    {
        if (str[index] != symbol)
        {
            matrix[row][column++] = str[index];
            if (column > MAX_LEN_WORD)
                return ERROR_LEN;
        }
        else
        {
            while (str[index + 1] == symbol)
                index++;
            matrix[row++][column] = '\0';
            column = 0;
        }
        index++;
    }
    matrix[row++][column] = '\0';

    return row;
}

int my_gets(char *str)
{
    int i = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF && c != '\0')
    {
        if (c >= '0' && c <= '9')
            return ERROR_NUMBER;

        str[i++] = c;

        if (i > MAX_LEN)
            return ERROR_LEN;
    }
    str[i] = '\0';

    return i;
}


int main(void)
{
    char str[MAX_LEN];
    char str_word[MAX_LEN][MAX_LEN];

    const int len = my_gets(str);
    if (len < 0)
    {
        puts("Error input");
        return len;
    }

    const int quantity_word = my_split(str, str_word, len);

    if (quantity_word < 0)
    {
        puts("Error");
        return quantity_word;
    }

    int arr_key[quantity_word];
    count_meeting(str_word, quantity_word, arr_key);
    print_word(str_word, quantity_word, arr_key);

    return OK;
}
