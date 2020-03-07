#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

#define OK 0
#define TRUE 1
#define FALSE 0

void input_list(FILE *f,  node_s **list_p)
{
	char new_word[MAX_LEN_WORD];
	node_s *list = *list_p;
	
	while (TRUE)
	{
		if (feof(f))
			break;
		
		fscanf(f, "%s", new_word);
		push(&list, new_word);
	}
	
	*list_p = list;
}

int push(node_s **list, char new_word[MAX_LEN_WORD])
{
    node_s *temp = (node_s *)malloc(sizeof(node_s));

    temp->next = *list;
    strcpy(temp->word, new_word);
    *list = temp;
	
    return OK;
}

void destruct(node_s *list)
{
    if (!list)
        return;
	
    node_s *temp = list;
    node_s *p = list->next;

    while (TRUE)
    {
        free(temp);
        temp = p;
        if (temp == NULL)
            break;
        p = temp->next;
    }
}

void reverse(FILE *f, node_s *list)
{
    node_s *temp = list;
    while (temp)
    {
        fprintf(f, "%s\n", temp->word);
        temp = temp->next;
    }
}
