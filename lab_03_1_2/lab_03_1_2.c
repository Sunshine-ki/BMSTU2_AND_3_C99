#include <stdio.h>

#define OK 0
#define TWO 2
#define TRUE 1
#define FALSE 0
#define EPS 1e-5
#define ERROR -1
#define ERROR_EMPTY -3
#define ERROR_OPEN_FILE -2

typedef short int little;

little average_max_min(FILE *const f, float *const avg)
{
    float num;

    if (fscanf(f, "%f ", &num) != TRUE)
        return ERROR_EMPTY;

    float max;
    float min;
    int flag = FALSE;

    max = num;
    min = num;

    while (fscanf(f, "%f ", &num) == TRUE)
    {
        flag = TRUE;
        max = num > max ? num : max;
        min = num < min ? num : min;
    }
    if (!flag)
        return ERROR;

    *avg = (min + max) * 0.5;

    return OK;
}

int quantity(FILE *const f, float const avg)
{
    float num;
    int count = 0;
    fseek(f, 0, SEEK_SET);
    fscanf(f, "%f ", &num);
    while (fscanf(f, "%f ", &num) == TRUE)
    {
        if (num > avg)
            ++count;
    }

    return count;
}

int main(const int argc, const char **const argv)
{
    if (argc != TWO)
    {
        printf("Не верные аргументы командной строки.\n");
        return ERROR;
    }

    FILE *f = fopen(argv[1], "r");

    if (!f)
    {
        printf("Не удалось открыть файл.\n");
        return ERROR_OPEN_FILE;
    }
    printf("Файл успешно открыт!\n");
    float avg;

    const little err = average_max_min(f, &avg);
    if (err)
    {
        printf("\n!Задача некорректна!\n");
        fclose(f);
        return err;
    }

    printf("Результат: %d\n", quantity(f, avg));
    fclose(f);

    return OK;
}
