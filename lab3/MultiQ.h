#include"que.h"
typedef struct MultiQ{
int len;
Queue**arr;
}MultiQ;
MulitQ* createMQ(int num);// creates a list of num Queues, each of which is empty.
MultiQ* addMQ(MultiQ* mq, Element* t); // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
Element* nextMQ(MultiQ* mq); // returns the front of the non-empty Queue in mq with the highest priority.
MultiQ* delNextMQ(MultiQ* mq); // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
bool isEmptyMQ(MultiQ* mq); // tests whether all the Queues in mq are empty
int sizeMQ(MultiQ* mq); // returns the total number of items in the MultiQ
int sizeMQbyPriority(MultiQ* mq, int p); // returns the number of items in mq with the priority p.
Queue* getQueueFromMQ(MultiQ, int p); //returns the Queue with priority p.