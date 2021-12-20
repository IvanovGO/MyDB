#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define  _step if (p->next) {p=p->next;printf("-stp-s=%s-\n",p->str);} else {puts("unexpected end");return -1;}
#define  _stback p=p->prev;
#define  _s p->str
//printf("!p->str=%s!",p->str);
#define  _tst 
#define  _isok if (p)  if (p->str)
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

char * tmst=NULL;
//устанавливаем укзатель в начало списка			        
dnode * p = list->tail;
_step
_stback
if (!list->count) return 0;
//-------------------------------------CREATE----------------------	
	C_CREATE //если команда создать создаем бесконечный цикл для удобства
	{ puts("Create table recognized");  
        
        _step;//смещаемся на следующий элемент команду уже обработали
       
        
        
        if (!isDivider(_s)) {printf("Table name %s is specifyed \n",_s);}//смотрим имя таблицы
           else {puts("Incorrect table name");return -1;}//если начинается с разделителя то ошибка
              
              
         //какое-то соответствующее имя получено - можно создавать таблицу
         //создаем таблицу без столбцов	 и крепим ее к базе   	
         dtable * t = dtable_create(_s );
         dbase_add(base,t);
	// дальше у нас может быть либо ; либо скобки с именами и типами столбцов для таблицы
        _step ; 
        
                if (_s[0]==';') {return 1;}//если находим ; то уходим без ошибки
                	if (_s[0]=='(') {//находим открытые скобки
                		puts(" Open bracket ( found - adding columns");
                			
                		while(1){//заводим цикл по скобкам
                			_step;//шагаем
					_tst	//если нет закрывающего
						
                			if (_s[0]==')') 
                				 {puts("Closing bracket ) is found");break;}
                			tmst=_s;//сохраняем, скорей всего, имя столбца
                			_step;//шагаем на следующий
                			_tst
                			if (!strcmp(_s,"INDEXED"))//и проверяем индексируемый ли столбец
               				{puts("INDEXED found");//если да создаем столбец как индексируемый
	                		dtable_add(t,dcol_create(_s,true));
	                		_step;//шагаем
	                		}else//если нет создаем как неиндексируемый
	                			{puts("col is not INDEXED");
						dtable_add(t,dcol_create(_s,false));}
					//дальше должна быть либо запятая либо скобка	
					//_step;//шагаем и проверяем на запятую
					_tst
	                		if (_s[0]!=',') continue;//если нет то 
	                		if (_s[0]==';') return 1;
                			}//CREATE employees (id INDEXED, name INDEXED,  lol  );
                		}
             
              return 1;
	    }// CREATE END---------------------------
	 
	 C_SELECT
	 {puts("select found");
	 return 2;}
	 
	 C_INSERT
	 {puts("insert found");
	 return 3;}

	 C_DELETE
	 {puts("delete found");
	 return 4;}
	 
puts("Unrekognized command. Skipping...");	 
	 
	    
//все прошло успешно очищаем команду
return 0;
}
