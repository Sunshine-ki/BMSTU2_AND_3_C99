#ifndef CONSTANS_H

#define CONSTANS_H

typedef struct
{
    int day;
    int month;
    int year;
    int number;              // Количество показаний в виде целого числа.
    char *surname;           // Фамилия.
    float *array_experiment; // Показания (за день).
} experiment_t;

#endif