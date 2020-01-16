/* File: test.c */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int args,char *argv[])
{
printf("\n%s",argv[0]);
int len = strlen(argv[0]);
for(int j=0;j<=len-2;j++){
argv[0][j] = argv[0][j+2];
}
argv[0][len-2]='\0';

printf("the value of args is %d \n",args);
for(int i=0;i<args;i++){
	printf("\n %s as string",argv[i]);
	int val = atoi(argv[i]);
	if(val!=0 || strcmp(argv[i],"0")==0){
	printf("\n the interger value is %d",val);
	}	
}
}
