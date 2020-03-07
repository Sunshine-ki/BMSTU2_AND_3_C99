#include <stdio.h>

#define MAX_LEN 100
#define OK 0

typedef long long int lli;


void matrix_square(lli matrix[][MAX_LEN], FILE *f_out, lli len)
{
    int temp = 0;

    for (lli i = 0; i < len; i++)
    {
            for (lli j = 0; j < len; j++)
            {
                for (lli k = 0; k < len; k++)
                {
                    temp += matrix[i][k] * matrix[k][j];
                    // printf("%d %d\n", matrix[i][k], matrix[k][j]);
                }
                fprintf(f_out, "%d", temp);
                temp = 0;
                // break;
            }
            fputs("\n", f_out);
    }
}

lli matrix_fill(lli matrix[][MAX_LEN], FILE *f)
{
    char c;
    lli len = 0;
    lli i = 0, j = 0;

    while (fscanf(f, "%c", &c) && c != EOF && c != '\n')
        len++;
    fseek(f, 0, SEEK_SET);

    while (fscanf(f, "%c", &c) && c != EOF && !feof(f))
    {
        if (c == '\n')
        {
            j = 0;
            i++;
            continue;
        }
        matrix[i][j] = c == '0' ? 0 : 1;
        j++;
    }

    return len;
}

int main(void)
{
    FILE *f = fopen("in.txt", "r");
    FILE *f_out = fopen("out.txt", "w");
    lli matrix[MAX_LEN][MAX_LEN];

    lli len = matrix_fill(matrix, f);
    matrix_square(matrix, f_out, len);

    fclose(f);
    fclose(f_out);

    return OK;
}
