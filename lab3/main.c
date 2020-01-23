#include <stdio.h>
#include "que.h"
int main(){
	printf("Start\n");
	Queue* q =  newQ();
	Element*e = createElement(5);
	q=addQ(q,e);
	e = createElement(6);
	q=addQ(q,e);
	e = createElement(7);
	q=addQ(q,e);
	printf("the length of queue is %d\n",lengthQ(q) );







	return 0;
}