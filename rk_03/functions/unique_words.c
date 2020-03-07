#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../headers/unique_words.h"

char **create_unique_words()
{
    return (char **)malloc(sizeof(char *));
}

char *lower_word(char *word)
{
    int i = 0;

    char *word_copy = (char *)malloc(sizeof(strlen(word)) + 1);
    strcpy(word_copy, word);

    while (word_copy[i])
    {
        word_copy[i] = tolower(word_copy[i]);
        i++;
    }

    return word_copy;
}

int func_unique(word_s unique_words, char *word_find)
{
    // printf("%d ", unique_words.count);
    for (int i = 0; i < unique_words.count; i++)
    {
        if (!strcmp(lower_word(word_find), lower_word(unique_words.words[i])))
            return FALSE;
    }

    return TRUE;
}

void input_unique(word_s *unique_words_p, word_s *s, int n)
{
    word_s unique_words = *unique_words_p;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s[i].count; j++)
        {
            // printf("%d ", unique_words.count);
            if (func_unique(unique_words, s[i].words[j]))
            {
                unique_words.words = (char **)realloc(unique_words.words, sizeof(char *) * (unique_words.count + 1));
                unique_words.words[unique_words.count] = (char *)malloc(sizeof(strlen(s[i].words[j])) + 1);
                strcpy(unique_words.words[unique_words.count], lower_word(s[i].words[j]));
                unique_words.count++;
            }
        }
    }

    *unique_words_p = unique_words;
}

void print_unique_words(word_s unique_words)
{
    for (int i = 0; i < unique_words.count; i++)
        printf("%s ", unique_words.words[i]);
    puts("");
}

// Функция для сортировки строк по возрастанию
int comp1(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}