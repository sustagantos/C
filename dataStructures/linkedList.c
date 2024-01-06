//Linked List In C is a linear data structure consisting of nodes

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


linkedList* listInit(){        //allocs memory for Linked List, and first->NULL
    
    linkedList *l = (linkedList *) malloc (sizeof(linkedList));
    l->first = NULL;
    return l;

}

node* createNode(int value){        //allocs memory for Linked List Node, and puts a value in it

    node *n = (node *) malloc (sizeof(node));   //creates node and allocs memory to it
    n->info = value;
    n->next = NULL;
    return n;
    
}

void addToList(linkedList *l, int value) {     //adds a number to the list, not in order

    node *newNode = createNode(value);      //creates a new node, with parameter value
    node *aux = l->first;       //aux = the first list item

    if (aux == NULL) {      //if aux is NULL, means list is empty, then adds to 1st position
        l->first = newNode;

    }else{
    
        while (aux->next != NULL){    //goes to pre-last
            aux = aux->next;
        }

        newNode->next = NULL;      //new node is last element, therefore, points to NULL
        aux->next = newNode;
    }

}
    
void printList(linkedList *l){      //prints list

    node *aux = l->first;       
    printf("\nlinked list: ");

    while(aux!=NULL){       //while node isn't NULL
        printf("%d, ",aux->info);    //prints its info
        aux=aux->next;      //goes to next
    }
    printf("\n\n");

}
    


void main(){

    linkedList *list = listInit();      //declare and allocate a linked list

    addToList(list, 5);
    addToList(list, 4);
    addToList(list, 3);
    addToList(list, 2);
    addToList(list, 1);       


    printList(list);        //print the list

}