#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>
//#include <stdbool.h>

/*
typedef struct dnode {
struct dnode * prev;
struct dlist * list;
int data;
struct dnode * next; } dnode;   
	        

typedef struct dlist {
struct dnode * head;
struct dnode * tail;
long count;          } dlist;
*/



dlist * dlist_init(){//создание двусвязанного списка
dlist * p = (dlist *)malloc(sizeof(dlist)); 
if (!p) return NULL;
p->count=0;
p->head=NULL;
p->tail=NULL;
return p;
}


bool dlist_is_empty(dlist * list){
if (!list->head&&!list->tail) return true;
return false;
}

bool dlist_is_trivial(dlist * list){
if (list->head==list->tail) return true;
return false;
}



int dlist_add(dlist*list,dnode * node){//добавление узла в конец
puts("dlist add");
if (dlist_is_empty(list)){puts("empty");
list->head=node;
list->tail=node;
puts("-----------add in empty---------");
}  else 
{
node->prev=list->head;
node->prev->next=node;
list->head=node;
puts("add in not empty");
}
list->count++;
node->list=list;
return list->count;
}

int dlist_ins(dlist * list, dnode * node){ //вставка узла в начало
if (dlist_is_empty(list)){//puts("empty");
list->head=node;
list->tail=node;
} else {node->next=list->tail;
node->next->prev=node;
list->tail=node;}
list->count++;
node->list=list;
return list->count;
}



void dlist_clear(dlist * list){
if (!list->tail) return;
dnode * p = list->tail;
while(p) {
	dlist_remove(p);
	p=p->next;}
}

unsigned long dlist_list(dlist * list){//вывод узлов
if (!list->tail) {puts("dlist_list:this is tail");
			return -1;}
unsigned long c=0;
dnode * p = list->tail;
while(p) {c++;
	dnode_print(p);
	p=p->next;}
return c;}

int dnode_print(dnode * node){

if (node->str) printf("Str= %s\n",node->str);
if (node->num) printf("Num=%3i\n",*node->num);

//printf("prev-%p next-%i str-%p num-%p \n",(void*)node,		
//				node->str,node->num,(void*)node->list);

return 0;
}

/*
dnode * dlist_remove(dnode * node){//удаление узла
puts("dlist remove");
printf("count %li ",node->list->count);
printf("count-- %li \n",node->list->count);
if (node->list->head!=node) {node->prev->next=node->next->prev;
			     return node;} else node->list->head=node->prev;
node->list->count--;
if (node->list->tail==node) {node->list->tail=NULL;
if (node->list->count) {
      	printf("Warning! Count mismatch with dlist is empty. %li nodes is orphaned!",node->list->count);
  			}return node;}
node->list=NULL;
return node;
}*/


dnode * dlist_remove(dnode * node){
if (!node) return NULL;
//puts("dlist_remove");
dlist * list = node->list;
//printf("list->count=%li >>",list->count);
if (!list->count) return NULL;
list->count--;
//if (!list) puts("list NULL");
//printf("list->count=%li \n",list->count);

if (!list->count){
list->tail=NULL;
list->head=NULL;
node->list=NULL;
return node;
}
if (node==node->list->head) {
node->prev->next=NULL;
node->list->head=node->prev;
node->list=NULL;
return node;
}

if (node==node->list->tail) {
node->next->prev=NULL;
node->list->tail=node->next;
node->list=NULL;
return node;
}

node->next->prev=node->prev;
node->prev->next=node->next;


node->list=NULL;
node->next=NULL;
node->prev=NULL;
return node;
}

dnode * dlist_min(dlist * list){
dnode * p = list->tail;
dnode * mp = p;
if (p->num){
int min=*p->num;
while (p){if (*p->num<min) {min=*p->num; mp=p;}
p=p->next;}
printf("mp-int=%i\n",*mp->num);
return mp;} 
else return NULL;
}

dnode * dlist_max(dlist * list){
if(!list->tail) return NULL;
dnode * p = list->tail;
dnode * mp = p;
if (p->num){
int max=*p->num;
while (p){if (*p->num>max) {max=*p->num; mp=p;}
p=p->next;}
return mp;}
else return NULL;
}



dnode * dnode_add(char * str,int * num){
dnode * p = (dnode*)malloc(sizeof(dnode));
if (!p) { puts("node cannot be created");
	return NULL;}
/*----*/
p->str=str;
p->num=num;
/**-----*/
p->prev=NULL;
p->next=NULL;
p->list=NULL;
return p;}


dlist * dlist_sort(dlist * list){
//puts ("SORT");
if (dlist_is_empty(list)) return NULL;
//puts("not empty");
if (dlist_is_trivial(list)) return list;
//puts("not trivaial");
dlist * p = dlist_init();

p=list;
//puts("list p");
printf ("tail p - %p dlist_list %li\n",(void*)p->tail,dlist_list(p));

dlist * ps = dlist_init();
while(p->count) {//puts("while");
dlist_add(ps,dlist_remove(dlist_max(p)));
//dlist_list(p);
}

return ps;
}



