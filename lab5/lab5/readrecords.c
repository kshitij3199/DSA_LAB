#include "readrecords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

ccinfo* readfile(ccinfo* ptr,long long int *cur_loc ){
	int size=10;
//int cur_loc=0;
ptr =(ccinfo*)malloc(sizeof(ccinfo)*size);

FILE *fptr = fopen("2","r"); 
//FILE *cp = fopen("copyfile.txt","w"); 
if (fptr == NULL) 
{
	printf("no such file found");
      exit(1); 
}
long num;
char banc[6];
char ed[8];
char f_n[6];
char l_n[6];
while(fscanf(fptr,"\"%ld,%[^,],%[^,],%[^,],%[^\"]\"",&num,banc,ed,f_n,l_n)!=EOF){
	printf("\n cur_loc is %lld  size %d",*cur_loc,size);
	
	if (*cur_loc>=size){
		 printf("\n realloc is to be called");
		 ptr =(ccinfo*)realloc(ptr,sizeof(ccinfo)*size*2);
		size = size*2;

	}
		printf("\n reading element no. %lld ",*cur_loc+1);
		ptr[*cur_loc].card_no = num;
		strcpy(ptr[*cur_loc].bank_code,banc);
		printf("\n prinying banc %s",banc);
		strcpy(ptr[*cur_loc].exp_date,ed);
			printf("\n prinying ed %s",ed);
		strcpy(ptr[*cur_loc].f_name,f_n);
		strcpy(ptr[*cur_loc].l_name,l_n);
		(*cur_loc)++;
		//lines++;
		if(fgetc(fptr)==EOF){
			break;
		}

}
return ptr;
}