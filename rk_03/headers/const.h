#ifndef __CONST_H__

#define __CONST_H__

#define FILE_NAME_OUT "files/out.txt"
#define FILE_NAME_IN 1
#define MODE_WRITE "w"
#define MODE_READ "r"

#define MAX_LEN_WORD 64

#define FALSE 0
#define TRUE 1

#define OK 0

typedef struct
{
	char **words;
	int count;
} word_s;

#endif