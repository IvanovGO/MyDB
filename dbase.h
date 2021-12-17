#include <stdbool.h>



typedef struct dcell {
double * real;
int * integer;
char * string;
char * name;
struct dcell * prev;
struct dcell * pnext;
		} dcell;


typedef struct drow {

dcell * cell;
struct drow * next;
struct drow * prev;
struct drow * row;
		} drow;

typedef struct dtable {
struct dtable * prev;
struct dbase * base;
char * name;
drow * row;
struct dtable * next; } dtable;


typedef struct dbase {
struct dtable * head;
struct dtable * tail;
struct dtable * table;
long count;          } dbase;


dbase * dbase_init();

dtable * dbase_remove(dtable * table);

dtable * create_table(drow * row);

drow * create_row(dcell * cell);

dcell * create_cell(char * str);

void dbase_clear(dbase * base);

int dbase_add(dbase * base,dtable * table);//добавление узла в конец

int dbase_ins(dbase * base, dtable * table);//вставка узла в начало

bool dbase_is_empty(dbase * base);

bool dbase_is_trivial(dbase * base);


unsigned long dbase_base(dbase * base);//вывод узлов

dtable * dbase_remove(dtable * table);//удаление узла

dtable * dtable_add(char * str);

int dtable_print(dtable * table);




