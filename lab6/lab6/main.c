#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"struct.h"
#include"merge.h"

int main(){

int size=100;
int cur_loc=0;
Element* ptr =(Element*)malloc(sizeof(Element)*size);




FILE *fptr = fopen("10240.txt","r"); 
//FILE *cp = fopen("copyfile.txt","w"); 
if (fptr == NULL) 
{
	printf("no such file found");
      exit(1); 
}
char t_name[11];
float t_cgpa;

while(fscanf(fptr,"%[^,],%f",t_name,&t_cgpa)!=EOF){

	if (cur_loc>=size){
		 printf("\n realloc is to be called");
		 ptr =(Element*)realloc(ptr,sizeof(Element)*size*2);
		size = size*2;

	}
	//printf("\n reading element no. %d 	CG %f 	Name %s",cur_loc+1,t_cgpa,t_name);
	
	ptr[cur_loc].cgpa = t_cgpa;
	strcpy(ptr[cur_loc].name,t_name);
	cur_loc++;
	if(fgetc(fptr)==EOF){
			break;
		}
}
for(int i=0;i<cur_loc;i++){
	printf("\n before sorting  element no. %d 	CG %f 	Name %s",i+1,ptr[i].cgpa,ptr[i].name);
}


printf("\n Now doing sorting");

//Merge_sort_recursive(ptr,0,cur_loc-1);
Merge_sort_iterative(ptr,cur_loc);


for(int i=0;i<cur_loc;i++){
	printf("\n after sorting  element no. %d 	CG %f 	Name %s",i+1,ptr[i].cgpa,ptr[i].name);
}








	return 0;

}