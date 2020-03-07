#ifndef SORT_H

#define SORT_H

#include "constants.h"

// void sort(experiment_t *array, int n, int (*compare)(experiment_t, experiment_t));

void qs_sort(experiment_t *array, int first, int last, int (*compare)(experiment_t, experiment_t));

int str_cmp(experiment_t experiment_1, experiment_t experiment_2);

int date_cmp(experiment_t experiment_1, experiment_t experiment_2);

int float_cmp(experiment_t experiment_1, experiment_t experiment_2);

int choice_sort(int (**compare)(experiment_t, experiment_t));

#endif