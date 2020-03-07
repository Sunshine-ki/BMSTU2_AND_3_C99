#ifndef STRUCT_H

#define STRUCT_H

#define MAX_LEN_WORD 11

typedef struct node_s
{
    char word[MAX_LEN_WORD];
    struct node_s *next;
}node_s;

#endif