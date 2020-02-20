#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"record.h"
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