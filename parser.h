#include "dlist.h"
#include "dbase.h" 

/****************************************************************
Библиотека парсинга строк команд СУБД сосоит из одного заголовочного файла
parser.h и кода реализации в файлах parse_str.c и parse_comm.c
parse_str.c  раскладывает строку на составляющие
parse_comm.c интерпретирует сотавляющие средствами библиотеки dbase
*****************************************************************/

void parse_string(dlist * list,char * str);// parsing string whit expression

int parse_comm(dlist * list,dbase * base);

bool isSpacer(char * ch);

bool isDivider(char * ch);

bool isDigit(char * ch);

bool isCharacter(char * ch);
