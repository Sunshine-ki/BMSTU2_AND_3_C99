#ifndef CDIO_H

#define CDIO_H

#include "constants.h"
#include <stdio.h>

int input_experiment(experiment_t *experiment);

void output_to_file(FILE *f, experiment_t *array_experiment, int n);

void destruct_experiment(experiment_t *experiment);

int fill_array_experiment(experiment_t **array_experiment);

void destruct_array_experiment(experiment_t **array_experiment, int n);

#endif