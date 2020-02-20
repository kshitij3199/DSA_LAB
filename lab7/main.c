#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"newSort.h"



double[] testRun(Record Ls[],int size) {
//run InsertionSort and QuickSort – separately – on Ls;
//return the running time measurements (IStime, QStime);
Record* ptr2 =(Record*)malloc(sizeof(Record)*size);
for(int i=0;i<size;i++){
	ptr2[i].empid=Ls[i].empid;
	strcpy(ptr2[i].name,Ls[i].name);
}
double tt[2];
struct timeval t1, t2,t3,t4;
double elapsedTime,elapsedTime2;

gettimeofday(&t1, NULL);
quickSortIterative(Ls,10,0);
gettimeofday(&t2, NULL);
elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
printf("Total time for quicksort is %d ms.\n",elapsedTime);

gettimeofday(&t3, NULL);
insertionSort(ptr,10);
gettimeofday(&t4, NULL);
elapsedTime = (t4.tv_sec - t3.tv_sec) * 1000.0;
elapsedTime += (t4.tv_usec - t3.tv_usec) / 1000.0;
printf("Total time for insertionSort is %d ms.\n",elapsedTime2);

tt[0]=elapsedTime2;
tt[1]=elapsedTime1;
return tt;

}


int estimateCutoff(Record Ls[],int min,int max){

double tt1[2];
double tt2[2];
double tt[2];

tt1=testRun(Ls,min);
tt2 = testRun(Ls,max);
int mid;
do{
	mid = (min+max)/2;
	tt = testRun(Ls,mid);
}while(tt[0]-tt[1]<0.005)



return mid
}

int main(){

int size=100;
int cur_loc=0;
Record* ptr =(Record*)malloc(sizeof(Record)*size);




FILE *fptr = fopen("10n","r"); 
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
for(int i=0;i<cur_loc;i++){
	printf("\n before sorting  Record no. %d 	empid %d 	Name %s",i+1,ptr[i].empid,ptr[i].name);
}


printf("\n Now doing sorting");
//quickSortIterative(ptr,10,4);
//insertionSort(ptr,10);
//newSort(ptr,10,5);
/*for(int i=0;i<cur_loc;i++){
	printf("\n before sorting  Record no. %d 	empid %d 	Name %s",i+1,ptr[i].empid,ptr[i].name);
}*/
int e=estimateCutoff(ptr,0,10);
printf("%cutoff is d\n",&e );
}