#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "parser.h"
#define COMMA '.' //decimal divider
int num_len;
int str_len;

bool nonstop(char ch){
//puts ("nonstop");
switch (ch){
case '\r':;
case '\n':;
case 0:;
case ' ':;
case '[':;
case ']':;
case ';':;
case '|':;
case '*':;
case '>':;
case '<':;
case '"':;
case 0x27:;
case '=':;
case '+':;
 return false;}
return true;}

bool isDigi(char ch,char nxt){//is symbol number?
if ((ch=='-')&&((nxt>0x2f)&&(nxt<0x3a))) return true;
if (((ch>0x2f)&&(ch<0x3a))&&(nxt==' ')) return true;
if (((ch>0x2f)&&(ch<0x3a))&&(nxt=='\0')) return true;
if (((ch>0x2f)&&(ch<0x3a))&&(nxt==')')) return true;

if (((ch>0x2f)&&(ch<0x3a))&&(nxt==COMMA)) return true;
if (((ch>0x2f)&&(ch<0x3a))&&((nxt>0x2f)&&(nxt<0x3a))) return true;
return false;}


double parse_fract(char * str,int ns){//parsing factorial part 0.xxxxxx
double rez=0;
int i = ns;
char dec =0;
	while ((str[i+1]>0x2f)&&(str[i+1]<0x3a)){
	dec++;
	i++;}
	num_len+=dec;
for (int d=i;d>i-dec;d--) rez+=(str[d]&0x0F)*pow(10,i-d);
//printf("fract part = %f\n",rez);
rez=rez/pow(10,dec);
return rez;}


double * parse_num(char * str, int ns){ //str - pointer to string with expr ns - start of real
double * rez = (double *)malloc(sizeof(double));//memory alocation for rez;
*rez=0;
num_len=0;
double fraction=0;//00.xxxx
char dec=0;
int i = ns;
if (str[ns]=='-') i++;
	while ((str[i]>0x2f)&&(str[i]<0x3a)){
	dec++;
	i++;}
	num_len=dec;
	if(str[i]==COMMA) {fraction=parse_fract(str,i);i--;}
for (int d=i;d>i-dec;d--)  *rez+=(str[d]&0x0F)*pow(10,i-d);
if (fraction) *rez+=fraction;
if (str[ns]=='-') {*rez*=-1; num_len++;}
return rez; 
}


char * parse_symb(char * str, int ns){
char z[0xff];
int i = ns;
if (isDigi(str[i],str[i+1])) return NULL;
//puts ("parse symb");
str_len=0;
z[str_len]=str[i];
i++;str_len++;
while (nonstop(str[i]))
	{
	z[str_len]=str[i];
	i++;
	str_len++;
	}
	z[str_len]='\0';
char * rez = (char *)malloc(str_len+2);
printf("z=%s\n",z);
return memcpy(rez,&z,str_len+1); }

void parse_string(dlist * list, char * str){


double * num;
char * symb;

for (int i = 0; i<strlen(str);i++) {
         
    	if (isDigi(str[i],str[i+1])) { num =  parse_num(str,i);
				printf("%3.4f parsed\n",*num);//
				dlist_ins(list,dnode_add(NULL,num));
		                i+=num_len+1;
					
				} else
                  		
        if (str[i]!=' ') {  symb = parse_symb(str,i-1);
                             printf("parsed %s\n",symb);
        			dlist_ins(list,dnode_add(symb,NULL));
        			  i+=str_len+1;}
         
         	                	}
         		
return ;
}
