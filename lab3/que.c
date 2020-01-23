#include<stdlib.h>
#include <stdbool.h>
#include "que.h"
Queue* newQ(){
Queue* temp = (Queue*)malloc(sizeof(Queue));
temp->head=NULL;
temp->tail=NULL;
temp->length=0;
return temp;
}

bool isEmptyQ(Queue* q){
	if (q->head == NULL){
		return true;
	}
	else{
		return false;
	}
}

Queue* delQ(Queue* q){
	q->head = q->head->next;
	q->length--;
	return q;

}
Element* front(Queue* q){
	
	return  q->head;
}
Queue* addQ(Queue* q , Element* e){
	q->tail=e;
	q->length++;
	return q;

}
int lengthQ(Queue* q){
	return q->length;
}

Element* createElement(int d){
	Element* temp = (Element*) malloc(sizeof(Element));
	temp->data =d;
	return temp;
}