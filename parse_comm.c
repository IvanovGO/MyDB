#include "parser.h"
#include <stdio.h>
#include <string.h>





int parse_comm(dlist * list,dbase * base){
if (!list->tail) {	puts ("Empty command list");
			return 0;}
dnode * p = list->head;

int count=0;
while(p) {

if (p->num) printf("Num=%1.1f\n",*p->num);

if (p->str) {printf("No %i Str= %s\n",count,p->str);


if (!strcmp(p->str,"quit")) {
				puts("quit");
				return -1;}

/*
if (!strcmp(p->str,"create")) {
		if (p->prev) dbase_add(base,create_table(create_row(create_cell(p->str)))); }else
			puts ("Specify table name");*/


if (!strcmp(p->str,"select")) 	puts ("Not implemented yet");


if (!strcmp(p->str,"insert"))  puts ("Not implemented yet");



	}
	p=p->prev;
	count++;
dlist_clear(list);}
return 0;
}
