#include "../headers/find_max.h"

int scalar_product(int *arr1, int *arr2, int n)
{
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        res += arr1[i] * arr2[i];
    }

    return res;
}

void find_two_max_sentence(word_s *s, int **binary_matrix, int n, int m)
{
    int arr_res[2];
    int max = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (scalar_product(binary_matrix[i], binary_matrix[j % m], n) > max)
            {
                arr_res[0] = i;
                arr_res[1] = j;
                max = scalar_product(binary_matrix[i], binary_matrix[j % m], n);
            }
            // printf("%d %d %d \n", i, j % m, scalar_product(binary_matrix[i], binary_matrix[j % m], n)); // s[i].words[j]);
        }
    }

    printf("Индексы двух максимально похожих предложений:\n");
    printf("%d и %d\n", arr_res[0], arr_res[1]);
}