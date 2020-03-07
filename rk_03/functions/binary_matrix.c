#include "../headers/binary_matrix.h"
#include "../headers/unique_words.h"

int **create_binary_matrix(int n)
{
    return (int **)malloc(sizeof(int *) * n);
}

void input_binary_matrix(int **binary_matrix, word_s unique_words, word_s *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        binary_matrix[i] = (int *)malloc(sizeof(int) * unique_words.count);
        for (int j = 0; j < unique_words.count; j++)
        {
            // printf("%s \n", unique_words.words[j]);
            binary_matrix[i][j] = !func_unique(s[i], unique_words.words[j]);
        }
    }
}

void print_matrix(FILE *f, int **binary_matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", binary_matrix[i][j]);
        fprintf(f, "\n");
    }
}
