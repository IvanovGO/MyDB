#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "parser.h"
#include <ctype.h>

#define COMMA '.' //decimal divider


void parse_string(dlist * list, char * str){

char delim[1] = " ";


char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		if (strlen(ptr))  
		  if (isdigit(ptr[0])) {
		        int * num = (int*)malloc(sizeof(int));
		        *num=atoi(ptr);
		  	dlist_add(list,dnode_add(NULL,num));
				 } else {
				char * str = (char*)malloc(strlen(ptr));
				memcpy(str,ptr,strlen(ptr)+1);
				dlist_add(list,dnode_add(str,NULL));}
	
		ptr = strtok(NULL, delim);
			
	}
    

         		
return;
}
