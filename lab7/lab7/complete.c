#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include<sys/time.h>
typedef struct timet{
	double istime;
	double QStime;
}tt ;
tt testRun(emp arr[], int s) {       
//run InsertionSort and QuickSort – separately – on Ls;                  
	struct timeval t1, t2,t3,t4;
    double elapsedTime1,elapsedTime2;
	gettimeofday(&t1, NULL);
    quickSortIterative(arr, 0, s - 1,8);
     gettimeofday(&t2, NULL);
    elapsedTime1 = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime1 += (t2.tv_usec - t1.tv_usec) / 1000.0;
	 struct timet *ti=(struct timet *)malloc(sizeof(tt));
	ti->QStime=elapsedTime1;
	gettimeofday(&t1, NULL);
    insertionSort( arr, s);
     gettimeofday(&t2, NULL);
    elapsedTime2 = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime2 += (t2.tv_usec - t1.tv_usec) / 1000.0;
	ti->istime=elapsedTime2;
	

return *ti;
} 

int  estimateCutoff(int min,int max,emp arr[]) { 
	 tt tt1 = testRun(arr, min); // assert tt1.IStime < tt1.QStime  
	 tt tt2 = testRun(arr, max);  // assert tt1.IStime > tt1.QStime      
 tt t;
 int mid;
 do {   mid =(min+max)/2;     
   t= testRun(arr, mid);           
		  if(t.istime-t.QStime<tt1.istime-tt1.QStime)min=mid; 
		   else {max=mid;}
		  } while( t.istime == t.QStime);    
return mid; 
 } 
 void insertionSort(Record arr[], int n) 
{ 
     
    for (int i = 1; i < n; i++) { 
        int val = arr[i].empid;
        char t_name[11]; 
        strcpy(t_name,arr[i].name);
        int j = i - 1; 
  

        while (j >= 0 && arr[j].empid > val) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1].empid = val;
        strcpy(arr[j+1].name,t_name); 
    } 
} 
void swap(Record* a, Record* b) 
{ 
    Record* ptr=(Record*)malloc(sizeof(Record));;
    ptr->empid = a->empid;
    strcpy(ptr->name,a->name);

    a->empid = b->empid;
    strcpy(a->name,b->name);

    b->empid = ptr->empid;
    strcpy(b->name,ptr->name); 
} 
  

int partition(Record arr[], int l, int h) 
{ 
    int x = arr[h].empid; 
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++) { 
        if (arr[j].empid <= x) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 
  
void quickSortIterative(Record arr[], int n, int s) 
{ 
    
    int stack[n]; 
  
   
    int top = -1; 
  
    
    int l=0;
    int h=n-1;
    stack[++top] = l; 
    stack[++top] = h; 
  
    
    while (top >= 0) { 
        // Pop h and l 
        h = stack[top--]; 
        l = stack[top--]; 
  
        
        int p=0;
        if (h-l+1>s || s<1){
        p = partition(arr, l, h); 
        }
        
        if (p - 1 > l && ((p-l>s) ||  (s<1))   ) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 
  
   
        if (p + 1 < h && ((h-p>s ||s<1))    ) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    }
   /* printArr(arr,10); */
} 
void insertionSort(Record arr[], int n) 
{ 
     
    for (int i = 1; i < n; i++) { 
        int val = arr[i].empid;
        char t_name[11]; 
        strcpy(t_name,arr[i].name);
        int j = i - 1; 
  

        while (j >= 0 && arr[j].empid > val) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1].empid = val;
        strcpy(arr[j+1].name,t_name); 
    } 
} 
void newSort(Record arr[], int n,int s) {
	
		
		quickSortIterative(arr,n,s);
		insertionSort(arr,n); 
	

}