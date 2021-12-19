#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define  _step (p=p->next)
#define  _s p->str
#define   _isok if (p) if (p->str)
#define  _isnok else {puts("Unespected NULL");return -1;}
#define  _t if (p) 
#define  C_CREATE if (!strcmp(p->str,"CREATE")) while(1) 
#define  C_INSERT if (!strcmp(p->str,"INSERT")) while(1)  
#define  C_SELECT if (!strcmp(p->str,"SELECT")) while(1) 
#define  C_DELETE if (!strcmp(p->str,"DELETE")) while(1) 




int parse_comm( dlist * list, dbase * base){
//функция получает ссылку на список dlist с командами  
//и ссылку на базу данных dbase
//-------------------------------------------------------

			        
//устанавливаем укзатель в начало списка			        
dnode * p = list->tail;
if (!list->count) return 0;
//-------------------------------------CREATE----------------------	
	C_CREATE //если команда создать создаем бесконечный цикл для удобства
	{ puts("Create table recognized");  
        
        _step;//смещаемся на следующий элемент команду уже обработали
       
        _isok { //проверяем на пустой указатель
        
        if (!isDivider(_s)) {printf("Table name %s is specifyed \n",_s);}//смотрим имя таблицы
           else {puts("Incorrect table name");return -1;}//если начинается с разделителя то ошибка
              } _isnok
              
         //какое-то соответствующее имя получено - можно создавать таблицу
         //создаем таблицу без столбцов	 и крепим ее к базе   	
     dbase_add(base,dtable_create(_s ));
	// дальше у нас может быть либо ; либо скобки с именами и типами столбцов для таблицы
        _step ;
        _isok {
                if (_s[0]==';') {break;}
                	if (_s[0]=='(') {//находим открытые скобки
                		puts("column found");
                		}
              }_isnok
              break;
	    }// CREATE END---------------------------
	    
//все прошло успешно очищаем команду
dlist_clear(list); 
return 0;
}
