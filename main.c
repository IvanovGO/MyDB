#include <string.h> 

#include "parser.h"
#include <stdio.h>


int main(){
printf("Учебная СУБД.\nВведите HELP для полученя подсказки.\n");
dlist * tree = dlist_init();
dbase * tables=dbase_init();

char command[0xff]; 

while (strcmp(command,"quit")){
printf(">>");
gets(command);
parse_string(tree,(char*)command);
//if (parse_comm(tree,tables)==-1) return 0;
dlist_list(tree);
}
puts("Exiting");
return 0;
}
