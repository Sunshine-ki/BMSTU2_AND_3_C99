#ifndef STRUCT_H

#define STRUCT_H

typedef struct list
{
    int number;
    int pow_number;
    struct list *next_p;
} list;

#endif