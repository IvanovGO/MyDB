#include <string.h> 

#include "parser.h"
#include <stdio.h>



int main(int argc, char * argv[]){
printf("Учебная СУБД.\n");
if (argc!=2) {puts("incorrect count of arguments"); return -1;}
dlist * tree = dlist_init();
dbase * tables=dbase_init("test");


FILE * datafile;

datafile = fopen(argv[1],"r");

if (!datafile) {puts("cant open file"); return -2;}

char command[0xff]; 

//fscanf(datafile,"%s",str);

while(!feof(datafile)){
fgets(command,0xff,datafile);
//printf("Read  - %s",command);
parse_string(tree,command);
parse_comm(tree,tables);

}

fclose(datafile);
return 0;
}
