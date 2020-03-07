#include <stdio.h>

#define OK 0

int char_to_int(char c)
{
    return c == '0' ? 0 : 1;
}

void fill_file(FILE *f, FILE *f_out)
{
    char c, d;
    int len = 0;
    int temp = 0;

    while (fscanf(f, "%c", &c) && c != EOF && !feof(f) && c != '\n')
        len++;
    for (int i = 0; i < len && c != EOF && !feof(f); i++)
    {
        for (int j = 0; j < len && c != EOF && !feof(f); j++)
        {
            for (int k = 0; k < len && c != EOF && !feof(f); k++)
            {
                fseek(f, (len + 2) * i + k, SEEK_SET);
                fscanf(f, "%c", &c);
                fseek(f, (len + 2) * k + j, SEEK_SET);
                fscanf(f, "%c", &d);
                temp += char_to_int(c) * char_to_int(d);
            }
            fprintf(f_out, "%d", temp);
            temp = 0;
        }
        fputs("\n", f_out);
    }
}

int main(void)
{
    FILE *f = fopen("in.txt", "r");
    FILE *f_out = fopen("out.txt", "w");

    fill_file(f, f_out);

    fclose(f);
    fclose(f_out);

    return OK;
}
