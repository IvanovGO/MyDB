#include <stdio.h>
#include <stdlib.h>
char * rand_string(int n){
char * p = (char *)malloc(sizeof(char)*n+1);
int t = 0;
for (int i = 0;i<n;i++){
//if (rand()%2) {  } else { p[i]=(char)rand()%26+0x61; }}
t = rand()%5+0x41; p[i]=(char)t;}
p[n]=(char)0;
return p;}
int main (int argc,char * argv[]){
char * s1;char * s2;char * s3;
printf("%i\n",atoi(argv[1]));
puts("create table (name,sure,job);");
for (int i =0;i<atoi(argv[1]);i++){
s1=rand_string(6);s2=rand_string(6);s3=rand_string(20);
printf("insert into table (\"%s\",\"%s\",\"%s\");\n",s1,s2,s3);}
puts("select * from table;");
return 0;}
