//A Stack works on the LIFO process (Last In First Out)

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


stack* stackInit(){  //allocs memory for stack, and first/last->NULL
    
    stack *s = (stack *) malloc (sizeof(stack));
    s->first = NULL;
    s->last = NULL;
    s->size = 0;
    return s;

}

node* createNode(int value){  //allocs memory for stack Node, and puts a value in it

    node *n = (node *) malloc (sizeof(node));  //creates node and allocs memory to it
    n->info = value;
    n->next = NULL;
    n->previous = NULL;
    return n;
    
}

void addTostack(stack *s, int value) {  //adds a number to the stack (last position)

    node *newNode = createNode(value);  //creates a new node, with parameter value
    
    if(s->first == NULL){
        s->first = newNode;
        s->last = newNode;
    }else{
        newNode->previous = s->last;
        s->last->next = newNode;
        s->last = newNode;
    }

    s->size++;

}

void printStack(stack *s){      //prints stack

    node *aux = s->last;

    printf("\nstack:");

    while(aux != NULL){
        printf(" %d,",aux->info);
        aux = aux->previous;
    }
}

void removeFromStack(stack *s){     //removes from last position

    node *aux = s->last;

    if(s->last == NULL){
        printf("\nstack is empty");
    }else{
        s->last->previous->next = NULL;
        s->last = s->last->previous;
        free(aux);
    }
    s->size--;

}

void main(){

    stack *s01 = stackInit();   

    addTostack(s01, 3);
    addTostack(s01, 5);
    addTostack(s01, 7);
    addTostack(s01, 11);

    printStack(s01);
    removeFromStack(s01);
    printStack(s01);


}