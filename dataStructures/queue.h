#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct NODE{
    int info;
    struct NODE *next;
}node;

typedef struct QUEUE{
    node *first;
    int size;
}queue;


queue* queueInit();
void addToQueue(queue *q, int value);
void printQueue(queue *q);
void removeFromQueue(queue *q);
void searchInQueue(queue *q, int number);


#endif