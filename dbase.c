#include "dbase.h"
#include <stdlib.h>
#include <stdio.h>
//#include <stdbool.h>

/*
typedef struct dtable {
struct dtable * prev;
struct dbase * base;
int data;
struct dtable * next; } dtable;   
	        

typedef struct dbase {
struct dtable * head;
struct dtable * tail;
long count;          } dbase;
*/




drow * create_row(dcell * cell){

drow * p = (drow *)malloc(sizeof(drow));
p->cell=cell;
printf("Row by adress %p sucessfully created\n",p);
return p;
}

dcell * create_cell(char * str){
dcell * p = (dcell*)malloc(sizeof(dcell));
printf("Cell %s by adress %p sucessfully created\n",str,p);
return p;

}

dtable * create_table(drow * row ){

dtable * p = (dtable*)malloc(sizeof(dtable));

p->row=row;
p->next=NULL;
p->prev=NULL;
p->base=NULL;

printf("Table on adress %p sucessfully created\n",p);
return p;}


dbase * dbase_init(){//создание двусвязанного списка
dbase * p = (dbase *)malloc(sizeof(dbase)); 
if (!p) return NULL;
p->count=0;
p->head=NULL;
p->tail=NULL;
return p;
}


bool dbase_is_empty(dbase * base){
if (!base->head&&!base->tail) return true;
return false;
}

bool dbase_is_trivial(dbase * base){
if (base->head==base->tail) return true;
return false;
}



int dbase_add(dbase*base,dtable * table){//добавление узла в конец
//puts("dbase add");
if (dbase_is_empty(base)){//puts("empty");
base->head=table;
base->tail=table;
//puts("-----------add in empty---------");
}  else 
{
table->prev=base->head;
table->prev->next=table;
base->head=table;
//puts("add in not empty");
}
base->count++;
table->base=base;
return base->count;
}

int dbase_ins(dbase * base, dtable * table){ //вставка узла в начало
if (dbase_is_empty(base)){//puts("empty");
base->head=table;
base->tail=table;
} else {table->next=base->tail;
table->next->prev=table;
base->tail=table;}
base->count++;
table->base=base;
return base->count;
}



void dbase_clear(dbase * base){
if (!base->tail) return;
dtable * p = base->tail;
while(p) {
	dbase_remove(p);
	p=p->next;}
}

unsigned long dbase_base(dbase * base){//вывод узлов
if (!base->tail) return -1;
unsigned long c=0;
dtable * p = base->tail;
while(p) {c++;
	dtable_print(p);
	p=p->next;}
return c;}

int dtable_print(dtable * table){



//printf("prev-%p next-%i str-%p num-%p \n",(void*)table,		
//				table->str,table->num,(void*)table->base);

return 0;
}

/*
dtable * dbase_remove(dtable * table){//удаление узла
puts("dbase remove");
printf("count %li ",table->base->count);
printf("count-- %li \n",table->base->count);
if (table->base->head!=table) {table->prev->next=table->next->prev;
			     return table;} else table->base->head=table->prev;
table->base->count--;
if (table->base->tail==table) {table->base->tail=NULL;
if (table->base->count) {
      	printf("Warning! Count mismatch with dbase is empty. %li tables is orphaned!",table->base->count);
  			}return table;}
table->base=NULL;
return table;
}*/


dtable * dbase_remove(dtable * table){
if (!table) return NULL;
//puts("dbase_remove");
dbase * base = table->base;
//printf("base->count=%li >>",base->count);
if (!base->count) return NULL;
base->count--;
//if (!base) puts("base NULL");
//printf("base->count=%li \n",base->count);

if (!base->count){
base->tail=NULL;
base->head=NULL;
table->base=NULL;
return table;
}
if (table==table->base->head) {
table->prev->next=NULL;
table->base->head=table->prev;
table->base=NULL;
return table;
}

if (table==table->base->tail) {
table->next->prev=NULL;
table->base->tail=table->next;
table->base=NULL;
return table;
}

table->next->prev=table->prev;
table->prev->next=table->next;


table->base=NULL;
table->next=NULL;
table->prev=NULL;
return table;
}




dtable * dtable_add(char * str){
dtable * p = (dtable*)malloc(sizeof(dtable));
if (!p) return NULL;
/*----*/
p->name=str;
p->row=NULL;
/**-----*/
p->prev=NULL;
p->next=NULL;
p->base=NULL;
return p;}





