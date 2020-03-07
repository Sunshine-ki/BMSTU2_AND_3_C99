#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "list.h"

#define FILE_NAME_IN 1
#define FILE_NAME_OUT "out.txt"
#define MODE_READ "r"
#define OK 0

int main(int argc, char ** argv)
{
	setbuf(stdout, NULL);
	
	node_s *list = NULL;
	
	FILE *f_in = fopen(argv[FILE_NAME_IN], MODE_READ);
	FILE *f_out = fopen(FILE_NAME_OUT, "w");

	input_list(f_in, &list);
		
	reverse(f_out, list);
	
	destruct(list);
	fclose(f_in);
	fclose(f_out);
   
    return OK;
}