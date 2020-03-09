#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"newSort.h"
#include"quicksort.h"
#include"insertionsort.h"

#include<sys/time.h>
#include"timetest.h"
#include <math.h>




tt testRun(Record Ls[],int size) {
//run InsertionSort and QuickSort – separately – on Ls;
//return the running time measurements (IStime, QStime);

Record* ptr1 =(Record*)malloc(sizeof(Record)*size);
for(int i=0;i<size;i++){
	ptr1[i].empid=Ls[i].empid;
	strcpy(ptr1[i].name,Ls[i].name);
}


Record* ptr2 =(Record*)malloc(sizeof(Record)*size);
for(int i=0;i<size;i++){
	ptr2[i].empid=Ls[i].empid;
	strcpy(ptr2[i].name,Ls[i].name);
}
//double tt[2];
struct timeval t1, t2,t3,t4;
double elapsedTime,elapsedTime2;

gettimeofday(&t1, NULL);
quickSortIterative(ptr1,size,0);
gettimeofday(&t2, NULL);

elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
//printf("Total time for quicksort is %f ms.\n",elapsedTime);

gettimeofday(&t3, NULL);
insertionSort(ptr2,size);
gettimeofday(&t4, NULL);
elapsedTime2 = (t4.tv_sec - t3.tv_sec) * 1000.0;
elapsedTime2 += (t4.tv_usec - t3.tv_usec) / 1000.0;
//printf("Total time for insertionSort is %f ms.\n",elapsedTime2);
//Record* ptr1 =(Record*)malloc(sizeof(Record)*size);
tt* tp =(tt*)malloc(sizeof(tt));
tp->istime=elapsedTime2;
tp->QStime=elapsedTime;
//	printf("return from fun testrun\n");
return *tp;

}


/*int estimateCutoff(Record Ls[],int min,int max){

double tt1[2];
double tt2[2];
double tt[2];
double *p;
double *p1;
double *t;
p=testRun(Ls,min);
tt1[0]=p[0];
tt1[1]=p[1];
p = testRun(Ls,max);
tt2[0]=p1[0];
tt2[1]=p1[1];
int mid=99;
/*do{
	mid = (min+max)/2;
	t = testRun(Ls,mid);
	tt[0]=t[0];
	tt[1]=t[1];
}while(tt[0]-tt[1]<0.005);*/

//return mid;
//}*/
int  estimateCutoff(Record Ls[],int min,int max) { 
	 tt tt1 = testRun(Ls, min); // assert tt1.IStime < tt1.QStime  
	 tt tt2 = testRun(Ls, max);  // assert tt1.IStime > tt1.QStime      
 tt t;
 int mid;
 do {   mid =(min+max)/2;     
   t= testRun(Ls, mid);           
		  //if(t.istime-t.QStime<tt1.istime-tt1.QStime)min=mid; 
		   if (t.istime<t.QStime){
		   	min = mid;
		   }
		   else if (t.istime>t.QStime) 
		   	{max=mid;}
		  } 
		  while( fabs(t.istime) != fabs(t.QStime));    
printf("mid is %d \n",mid );
return mid; 
 } 
 