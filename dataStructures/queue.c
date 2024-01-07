//A Queue is defined as a linear data structure that is open at both ends and
//the operations are performed in First In First Out (FIFO) order

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* queueInit(){  //allocs memory for queue, and first->NULL
    
    queue *q = (queue *) malloc (sizeof(queue));
    q->first = NULL;
    q->size = 0;
    return q;

}

node* createNode(int value){  //allocs memory for queue Node, and puts a value in it

    node *n = (node *) malloc (sizeof(node));  //creates node and allocs memory to it
    n->info = value;
    n->next = NULL;
    return n;
    
}

void addToQueue(queue *q, int value) {  //adds a number to the queue beginning

    node *newNode = createNode(value);  //creates a new node, with parameter value
    node *aux = q->first;  //aux = the first queue item

    newNode->next = aux;  //insert in first position
    q->first = newNode;     //q points to new node now
    q->size++;

}

void printQueue(queue *q){  //prints queue

    node *aux = q->first;

    printf("\nqueue:");

    for(int i = 0; i < q->size; i++){
        printf(" %d", aux->info);
        aux = aux->next;
    }

}

void removeFromQueue(queue *q){     //removes from queue

    node *aux = q->first;

    for(int i = 0; i < (q->size)-1; i++){   //goes to pre last item
        aux = aux->next;
    }

    printf("\n%d was removed from queue",aux->info);
    free(aux->next);
    aux->next = NULL;
    q->size--;

}

void searchInQueue(queue *q, int number){   //searches for number in queue

    node *aux = q->first;

    for(int i = 0; i < q->size; i++){   //goes to pre last item

        if(aux->info == number){
            printf("\n%d is in queue",aux->info);
            return;
        }

        aux = aux->next;
    }

    printf("\n%d is NOT in queue",number);
    return;


}

void main(){

    queue *q01 = queueInit();

    addToQueue(q01,11);
    addToQueue(q01,7);
    addToQueue(q01,5);
    addToQueue(q01,3);

    printQueue(q01);

    searchInQueue(q01,11);
    removeFromQueue(q01);
    searchInQueue(q01,11);

    printQueue(q01);

}