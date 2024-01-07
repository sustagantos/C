//A Stack works on the LIFO process (Last In First Out)

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


stack* stackInit(){  //allocs memory for stack, and first->NULL
    
    stack *s = (stack *) malloc (sizeof(stack));
    s->first = NULL;
    return s;

}

node* createNode(int value){  //allocs memory for stack Node, and puts a value in it

    node *n = (node *) malloc (sizeof(node));  //creates node and allocs memory to it
    n->info = value;
    n->next = NULL;
    return n;
    
}

void addTostack(stack *s, int value) {  //adds a number to the stack

    node *newNode = createNode(value);  //creates a new node, with parameter value
    node *aux = s->first;  //aux = the first queue item

    while(aux != NULL){
        aux = aux->next;
    }

    newNode->next = NULL;  //insert in last position
    aux->next = newNode;     //s points to new node now

}

void printStack(stack *s){      //prints stack

    node *aux = s->first;

    printf("\nstack:");

    while(aux != NULL){
        printf(" %d", aux->info);
        aux = aux->next;
    }


}

void main(){

    stack *s01 = stackInit();

    addTostack(s01, 3);
    addTostack(s01, 5);
    addTostack(s01, 7);
    addTostack(s01, 11);

    printStack(s01);

}