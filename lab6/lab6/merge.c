#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include"struct.h"
#include"merge.h"



void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
	int a=0;
	int b=0;
	int c=0;
	int s;
	if (sz1<sz2){
		s = sz1;
	}
	else {
		s = sz2;
	}
	while(a<sz1 && b<sz2){

		if(Ls1[a].cgpa <=Ls2[b].cgpa){
			Ls[c]=Ls1[a];
			a++;c++;
		}else{
			Ls[c]=Ls2[b];
			b++;c++;
		}
	}
	while(a < sz1){
		Ls[c]=Ls1[a];
			a++;c++;
	}
	while(b < sz2){
		Ls[c]=Ls2[b];
			b++;c++;
	}
	/*for(int i=0;i<sz1;i++){
	printf("\nls1 is  %f ",Ls1[i].cgpa);
	}
	for(int i=0;i<sz1+sz2;i++){
	printf("\nls2 is  %f ",Ls2[i].cgpa);
	}
	for(int i=0;i<sz1+sz2;i++){
	printf("\nls is  %f ",Ls[i].cgpa);
	}*/
}

void Merge_sort_recursive(Element arr[],int l,int r){
	printf("indide recursive function\n");
	if (l<r){
		int m = (l+r)/2;
		//sorting first and second halves
		Merge_sort_recursive(arr,l,m);
		Merge_sort_recursive(arr,m+1,r);

		
		Element* ptr = (Element*)malloc(sizeof(Element)*(r-l+1));

		merge(arr+l,m-l+1,arr+m+1,r-m,ptr);
		for(int i=0;i<r-l+1;i++){
			printf("inside for %f\n",ptr[i].cgpa );
			arr[i+l]=ptr[i];
		}
	}

}

int min(int x, int y) { return (x<y)? x :y; } 

void Merge_sort_iterative(Element arr[],int n){
	int c_size;
	int l_start;
	for(c_size=1;c_size<=n-1;c_size=2*c_size){
		for(l_start=0;l_start<n-1;l_start+=2*c_size){
			int mid = min(l_start + c_size - 1, n-1); 
  
           int right_end = min(l_start + 2*c_size - 1, n-1);

           int s1 = mid-l_start+1;
           int s2 = right_end-mid; 
           Element* ptr = (Element*)malloc(sizeof(Element)*(right_end-l_start+1));
           merge(arr+l_start,s1, arr+mid+1,s2,ptr);
           for(int i=0;i<right_end-l_start+1;i++){
			printf("inside for %f\n",ptr[i].cgpa );
			arr[i+l_start]=ptr[i];
		}

		}
	}
}







