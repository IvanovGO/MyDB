#include "dlist.h"
#include "dbase.h" 

bool isSpacer(char * ch);

bool isDivider(char * ch);//test seqence fore */-=_+)([]}{

void parse_string(dlist * list,char * str);// parsing string whit expression

int parse_comm(dlist * list,dbase * base);
