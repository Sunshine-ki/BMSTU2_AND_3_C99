#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "cdio.h"

#define INVALID_CHAR "1234567890!@#$%^&*()_+№;:?-=.,<>"
#define MONTHS {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#define MAX_SURNAME 256
#define MAX_LEN_KEY 16
#define ERROR_BUFFER -2
#define ERROR_INPUT -1
#define ERROR_TEST -1
#define SURNAME 1000
#define MAX_DATA 16
#define MAX_DATE 11
#define OK 0
#define END 1

int input_experiment(experiment_t *experiment)
{
    int months[] = MONTHS;
    char answer[MAX_DATE];
    int rc = 0;

    experiment->surname = NULL;
    experiment->array_experiment = NULL;

    printf("Введите дату: ");
    // for (int i = 0; i < 12; i++)
    //     printf("%d ", months[i]);
    rc = scanf("%11s", answer);
    // printf("\nanswer: %s rc = %d\n", answer, rc);
    if (rc != 1)
    {
        printf("Ошибка ввода даты!\n");
        return ERROR_INPUT;
    }

    rc = sscanf(answer, "%d.%d.%d", &experiment->day, &experiment->month, &experiment->year);
    // printf("\nexperiment->day: %d rc = %d\n", experiment->day, rc);
    if (rc != 3)
    {
        printf("Ошибка ввода даты!\n");
        return ERROR_INPUT;
    }

    if (experiment->day == 0 && experiment->month == 0 && experiment->year == 0)
    {
        return END;
    }
    if (experiment->day < 1 || experiment->month < 1 || experiment->year < 1)
    {
        printf("Ошибка ввода даты!\n");
        return ERROR_INPUT;
    }

    if (experiment->day > 31 || experiment->month > 12 || experiment->year > 2019)
    {
        printf("Ошибка ввода даты!\n");
        return ERROR_INPUT;
    }

    if ((experiment->day < 10 && answer[0] != '0') || (experiment->month < 10 && answer[3] != '0') //
        || (experiment->year < 10 && answer[8] != '0'))
    {
        printf("Ошибка ввода даты!\n");
        return ERROR_INPUT;
    }
    if ((experiment->year < 1000 && answer[6] != '0') || (experiment->year < 100 && answer[7] != '0'))
    {
        printf("Ошибка ввода даты!\n");
        return ERROR_INPUT;
    }
    // printf("!!!!!%d %d", months[experiment->month - 1], experiment->month - 1);
    if ((experiment->month == 2) && ((experiment->year % 4 != 0) || ((experiment->year % 100 == 0) && (experiment->year % 400 != 0))) && (experiment->day > 28))
    {
        printf("Ошибка ввода даты!!\n");
        return ERROR_INPUT;
    }
    else if (experiment->day > months[experiment->month - 1])
    {
        printf("Ошибка ввода даты!\n");
        return ERROR_INPUT;
    }

    printf("\nВведите фамилию: ");
    char surname_temp[SURNAME];
    rc = scanf("%256s", surname_temp);
    // printf("\nrc = %d", rc); // Отладочные принты (Спросить про отладку define или что-то такое...)
    if (!rc || strlen(surname_temp) > MAX_SURNAME)
    {
        printf("\nНекорректный ввод фамилии!\n");
        return ERROR_INPUT;
    }
    char substr[] = INVALID_CHAR;
    for (int i = 0; i < strlen(substr); i++)
    {
        if (strchr(surname_temp, substr[i]) != NULL)
        {
            printf("Ошибка ввода фамилии!");
            return ERROR_INPUT;
        }
    }
    experiment->surname = (char *)malloc((strlen(surname_temp) + 1) * sizeof(char));
    if (!experiment->surname)
        return ERROR_INPUT;
    strcpy(experiment->surname, surname_temp);
    // printf("\nSurname: %s \n", experiment->surname);

    printf("\nВведите количество показаний в виде целого числа: ");
    rc = scanf("%d", &experiment->number);
    if (!rc || experiment->number <= 0)
    {
        printf("Ошибка ввода количества показаний!\n");
        return ERROR_INPUT;
    }

    experiment->array_experiment = (float *)malloc(experiment->number * sizeof(float));
    if (!experiment->array_experiment)
        return ERROR_INPUT;
    printf("\nВведите показания в виде действительных чисел, разделённых пробелами: \n");
    for (int i = 0; i < experiment->number; i++)
    {
        rc = scanf("%f", &experiment->array_experiment[i]);
        if (!rc)
        {
            printf("Ошибка ввода показаний!");
            return ERROR_INPUT;
        }
        // printf("\ni=%d, experiment->array_experiment[i] = %f \n", i, experiment->array_experiment[i]);
        // printf("%f", experiment->array_experiment[i]);
    }
    // printf("\nnumber: %d\n", experiment->number);

    return OK;
}

void output_to_file(FILE *f, experiment_t *array_experiment, int n)
{
    for (int k = 0; k < n; k++)
    {
        // fprintf(f, "%d.%d.%d", array_experiment[k].day, array_experiment[k].month, array_experiment[k].year);
        if (array_experiment[k].day < 10)
            fprintf(f, "0");
        fprintf(f, "%d.", array_experiment[k].day);
        if (array_experiment[k].month < 10)
            fprintf(f, "0");
        fprintf(f, "%d.", array_experiment[k].month);
        if (array_experiment[k].year < 10)
            fprintf(f, "0");
        if (array_experiment[k].year < 100)
            fprintf(f, "0");
        if (array_experiment[k].year < 1000)
            fprintf(f, "0");
        fprintf(f, "%d", array_experiment[k].year);

        fprintf(f, "\n%s\n%d %f\n", array_experiment[k].surname,
        array_experiment[k].number, array_experiment[k].array_experiment[0]);
    }
    // fprintf(f, "\n");
}

void destruct_experiment(experiment_t *experiment)
{
    if (experiment->surname)
    {
        free(experiment->surname);
        experiment->surname = NULL;
    }
    if (experiment->array_experiment)
    {
        free(experiment->array_experiment);
        experiment->array_experiment = NULL;
    }
}

int fill_array_experiment(experiment_t **array_experiment)
{
    int temp = 0, i = 0;
    // experiment_t array_experiment_temp;
    while (temp != END)
    {
        *array_experiment = (experiment_t *)realloc(*array_experiment, sizeof(experiment_t) * (i + 1));
        temp = input_experiment((*array_experiment) + i);
        // array_experiment_temp = (experiment_t *)realloc(*array_experiment, sizeof(experiment_t) * (i + 1));
        // if (!array_experiment_temp)
        // {
        //     printf("Ошибка!");
        //     destruct_array_experiment(array_experiment, i);
        //     return ERROR_BUFFER;
        // }

        if (temp < 0)
        {
            while (i >= 0)
            {
                destruct_experiment((*array_experiment) + i);
                i--;
            }
            // destruct_array_experiment(array_experiment, i);
            return ERROR_INPUT;
        }
        i++;
    }

    return i - 1;
}

void destruct_array_experiment(experiment_t **array_experiment, int n)
{
    for (int i = 0; i < n; i++)
        destruct_experiment((*array_experiment) + i);
}