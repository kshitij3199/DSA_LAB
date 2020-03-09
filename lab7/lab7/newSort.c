#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"record.h"
#include"quicksort.h"
#include"insertionsort.h"
void newSort(Record arr[], int n,int s) {
	
		
		quickSortIterative(arr,n,s);
		insertionSort(arr,n); 
	

}