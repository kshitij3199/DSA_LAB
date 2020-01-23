#include "MultiQ.h"
MulitQ* createMQ(int num){
	MultiQ* mq = (MultiQ*)malloc(sizeof(MultiQ));
	mq->arr = (Queue**)malloc(sizeof(Queue*)*num);
	mq->len = num;
	for(int i=0;i<num;i++){
		mq->arr[i]=newQ();
	}
	return mq;
}
MultiQ* addMQ(MultiQ* mq, Element* t){
	int p = t->pri;
	mq->arr[p] = addQ(mq->arr[p],t);
	return mq;
}
Element* nextMQ(MultiQ* mq){
	for(int i =mq->len-1;i>=0;i++){
		if (isEmptyQ(mp->arr[i]) == FALSE){
			return front(mp->arr[i]);
			break;
		}
	}
}
MultiQ* delNextMQ(MultiQ* mq){
	for(int i =mq->len-1;i>=0;i++){
		if (isEmptyQ(mp->arr[i]) == FALSE){
			mp->arr[i] = delQ(mp->arr[i]);
			return mp;
			break;
		}
	}

}