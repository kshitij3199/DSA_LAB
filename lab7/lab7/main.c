#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"newSort.h"
#include"timetest.h"
#include<sys/time.h>





int main(int argc,char *argv[]){

int size=100;
int cur_loc=0;
Record* ptr =(Record*)malloc(sizeof(Record)*size);

//printf("Enter file name\n");
//scanf("%s",fln);


FILE *fptr = fopen(argv[1],"r"); 
//FILE *cp = fopen("copyfile.txt","w"); 
if (fptr == NULL) 
{
	printf("no such file found");
      exit(1); 
}
char t_name[11];
int t_empid;

while(fscanf(fptr,"%[^ ] %d",t_name,&t_empid)!=EOF){

	if (cur_loc>=size){
		 printf("\n realloc is to be called");
		 ptr =(Record*)realloc(ptr,sizeof(Record)*size*2);
		size = size*2;

	}
	//printf("\n reading Record no. %d 	CG %f 	Name %s",cur_loc+1,t_cgpa,t_name);
	
	ptr[cur_loc].empid = t_empid;
	strcpy(ptr[cur_loc].name,t_name);
	cur_loc++;
	if(fgetc(fptr)==EOF){
			break;
		}
}
fclose(fptr);
/*for(int i=0;i<cur_loc;i++){
	printf("\n before sorting  Record no. %d 	empid %d 	Name %s",i+1,ptr[i].empid,ptr[i].name);
}*/


printf("\n Now doing sorting");
//quickSortIterative(ptr,10,4);
//insertionSort(ptr,10);
//newSort(ptr,10,5);
/*for(int i=0;i<cur_loc;i++){
	printf("\n before sorting  Record no. %d 	empid %d 	Name %s",i+1,ptr[i].empid,ptr[i].name);
}*/

int e=estimateCutoff(ptr,0,10);
printf(" cutoff is %d\n",e );


struct timeval t1, t2;
double elapsedTime;
for(int i=0;i<cur_loc;i++){
	printf("\n After sorting  Record no. %d 	empid %d 	Name %s",i+1,ptr[i].empid,ptr[i].name);
}
gettimeofday(&t1, NULL);

newSort(ptr,size,e);
gettimeofday(&t2, NULL);

elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
printf("Total time for Newsort is %f ms.\n",elapsedTime);



FILE *cp = fopen(argv[2],"a+");
fprintf(cp,"Size of file: %d \n",cur_loc);
fprintf(cp, "critical value is %d\n",e );
fprintf(cp,"Total time for Newsort is %f ms.\n",elapsedTime);

fclose(cp);
}