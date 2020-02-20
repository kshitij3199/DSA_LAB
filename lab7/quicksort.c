#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"record.h"
/*void printArr(Record arr[], int n) 
{ 
    for(int i=0;i<n;i++){
    printf("\n after sorting  Record no. %d    empid %d    Name %s",i+1,arr[i].empid,arr[i].name);
    }
} */

// A utility function to swap two elements 
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
  
/* This function is same in both iterative and recursive*/
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
  
/* A[] --> Array to be sorted,  
   l  --> Starting index,  
   h  --> Ending index */
/*void quickSortIterative(Record arr[], int l, int h) 
{ 
    // Create an auxiliary stack 
    int stack[h - l + 1]; 
  
    // initialize top of stack 
    int top = -1; 
  
    // push initial values of l and h to stack 
    stack[++top] = l; 
    stack[++top] = h; 
  
    // Keep popping from stack while is not empty 
    while (top >= 0) { 
        // Pop h and l 
        h = stack[top--]; 
        l = stack[top--]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        int p = partition(arr, l, h); 
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (p - 1 > l) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (p + 1 < h) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    }
   
} */
void quickSortIterative(Record arr[], int n, int s) 
{ 
    // Create an auxiliary stack 
    int stack[n]; 
  
    // initialize top of stack 
    int top = -1; 
  
    // push initial values of l and h to stack 
    int l=0;
    int h=n-1;
    stack[++top] = l; 
    stack[++top] = h; 
  
    // Keep popping from stack while is not empty 
    while (top >= 0) { 
        // Pop h and l 
        h = stack[top--]; 
        l = stack[top--]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        int p=0;
        if (h-l+1>s || s<1){
        p = partition(arr, l, h); 
        }
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (p - 1 > l && ((p-l>s) ||  (s<1))   ) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (p + 1 < h && ((h-p>s ||s<1))    ) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    }
   /* printArr(arr,10); */
} 
