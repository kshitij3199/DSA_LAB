#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"struct.h"

int main(){
	int size=10;
//struct ccinfo memory[10];
ccinfo* ptr =(ccinfo*)malloc(sizeof(ccinfo)*size);
int cur_loc=0;

FILE *fptr = fopen("100000","r"); 
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
	printf("\n cur_loc is %d  size %d",cur_loc,size);
	
	if (cur_loc>=size){
		 printf("\n realloc is to be called");
		 ptr =(ccinfo*)realloc(ptr,sizeof(ccinfo)*size*2);
		size = size*2;

	}
		printf("\n reading element no. %d ",cur_loc+1);
		ptr[cur_loc].card_no = num;
		strcpy(ptr[cur_loc].bank_code,banc);
		printf("\n prinying banc %s",banc);
		strcpy(ptr[cur_loc].exp_date,ed);
			printf("\n prinying ed %s",ed);
		strcpy(ptr[cur_loc].f_name,f_n);
		strcpy(ptr[cur_loc].l_name,l_n);
		cur_loc++;
		if(fgetc(fptr)==EOF){
			break;
		}

}

printf("\n the content of files are");
for(int i=0;i<cur_loc;i++){
	printf("\n %d the card no. are %ld",i+1,ptr[i].card_no);
	printf("	BANK CODE	%s",ptr[i].bank_code);
	printf("	EXP_DATE	%s",ptr[i].exp_date);
	printf("	F_NAME	%s",ptr[i].f_name);
	printf("	l_name	%s",ptr[i].l_name);
}




}