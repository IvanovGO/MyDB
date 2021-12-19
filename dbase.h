#include <stdbool.h>

/*************************************************************************
Учебная библиотка реализующая простейшую систему управления базами данных
База данных представляет собой структуру хранящую ссылку на таблицы и свое
название. Таблицы хранят ссылки на базу данных к которой они принадлежат и
указатели на первую и поледнюю структуры столбцов. Структуры столбцы хранят
свои названия и ссылки на первую и последнюю ячейки которые в свою очередь 
хрант информацию об адресе своих соседей и указатель собственно данные.
Кроме перечисленного в структурах находится некоторая избыточная информация
вроде пинадлежности к вышестощей в иерархии структуре, количестве, порядке и т.п.
P.S.Под термином доавление или удаление следует понимать "прописку" и "выписку"
из соответствующих структур. сами данные никуда не перемещаются могут лишь 
"потерятся" если их "выписать" из структуры при т.н. удалении, но память 
выделенная в куче за ними так и остается занятой.  
***************************************************************************/

typedef struct dcell {//структура ячейка
int index;//порядковый номер ячейки
char * string;//даннные
struct dcell * prev;//предудыщая
struct dcell * next;//следующая
struct dcol * col;//принадлежность к колонке
		} dcell;


typedef struct dcol {//структура колонка
char * name;//имя
bool indexed;//индексируемая или нет?
unsigned int count;//количество принадлежащих ячеек
struct dcol * next;//следующая колонка
struct dcol * prev;//предыдущая колонка
struct dcell * head;//головная ячейка
struct dcell * tail;//первая ячейка(хвост)
struct dtable * table;//таблица приписки
		} dcol;

typedef struct dtable {//структура таблица
struct dtable * prev;//предыдущая таблица из базы
struct dbase * base;//база приписки
char * name;//имя таблицы
unsigned int count;//количество столбцов
struct dcol * head;//головной столбец
struct dcol * tail;//хвостовой столбец
struct dtable * next; } dtable;//следующая таблица

//стэк с задачей для  организации вывода информации
//из таблиц 
typedef struct dptodo {
struct dcol * col;//ссылка на колонку
struct dptodo * next;//следующий!
} dptodo;


typedef struct dbase {//структура базы данных
char * name;//имя
struct dtable * head;//головна таблица
struct dtable * tail;//хвостова таблица
unsigned int count;          } dbase;//количество таблиц в базе



//-------------------------BASE WORKING
dbase * dbase_init(char * name);//создать базу данных
unsigned int dbase_add(dbase * base,dtable * table);//добавление таблицы к базе
void dbase_clear(dbase * base);//удалить все из базы
unsigned int dbase_ins(dbase * base, dtable * table);//вставка таблицы в начало базы
bool dbase_is_empty(dbase * base);//проверка базы на наличие хоть одной таблицы
bool dbase_is_trivial(dbase * base);//в базе одна таблица 
dtable * dbase_remove(dtable * table);//удалить таблицу

//-------------------------TABLE WORKING
dtable * dtable_create( char * name );//создание таблицы
unsigned int dtable_add(dtable * table,dcol * col);//добавление колонки к таблице
dcol * dtable_remove(dcol * col);//удалить колонку из таблицы
unsigned int dtable_print_todo (dptodo * todo);//печать таблицы по заданию
dptodo * dtable_create_todo(dtable * table,char * colname);//создать задание
dptodo * dtable_todo_add(dptodo * todo,char * colname);//добавить к заданию
dcol * dtable_find(dtable * table,char * colname);//поиск столбца по имени.
bool dtable_is_empty(dtable * table);
//--------------------------COLUMN WORKING
dcol * dcol_create(char * name, bool indexed);//создать колонку
int dcell_add(dtable * table,dcell * cell);//
bool dcol_is_empty(dcol * col);
dcell * dcol_remove(dcell * cell);//
dcell * dcol_find_cell_index(dcol*col,unsigned int index);//

//--------------------------CELL WORKING
dcell * create_cell(char * str);
