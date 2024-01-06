//Linked List In C is a linear data structure consisting of nodes

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


linkedList* listInit(){  //allocs memory for Linked List, and first->NULL
    
    linkedList *l = (linkedList *) malloc (sizeof(linkedList));
    l->first = NULL;
    return l;

}

node* createNode(int value){  //allocs memory for Linked List Node, and puts a value in it

    node *n = (node *) malloc (sizeof(node));  //creates node and allocs memory to it
    n->info = value;
    n->next = NULL;
    return n;
    
}

void addToList(linkedList *l, int value) {  //adds a number to the list, not in order

    node *newNode = createNode(value);  //creates a new node, with parameter value
    node *aux = l->first;  //aux = the first list item

    if (aux == NULL) {  //if aux is NULL, means list is empty, then adds to 1st position
        l->first = newNode;

    }else{
    
        while (aux->next != NULL){  //goes to pre-last
            aux = aux->next;
        }

        newNode->next = NULL;  //new node is last element, therefore, points to NULL
        aux->next = newNode;
    }

}
    
void printList(linkedList *l){  //prints list

    node *aux = l->first;       
    printf("linked list: ");

    while(aux!=NULL){  //while node isn't NULL
        printf("%d, ",aux->info);  //prints its info
        aux=aux->next;  //goes to next
    }
    printf("\n");

}
    
void findInList(linkedList *l, int value){  //finds in list, if there is to find
    
    node *aux = l->first;

    while(aux != NULL){
        if(aux->info == value){
            printf("%d is in the list!\n",value);
            return;
        }
        aux = aux->next;
    }

    printf("%d is not in the list!\n",value);

}

void removeFromList(linkedList *l, int value){
    
}

void main(){

    linkedList *list = listInit();  //declare and allocate a linked list

    for(int i = 0; i <= 20; i++){   //adds 1-20 in the list
        addToList(list, i);
    }

    printList(list);

    findInList(list, 18);
    findInList(list, 23);

}