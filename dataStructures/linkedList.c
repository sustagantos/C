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
    printf("\nlinked list: ");

    while(aux!=NULL){  //while node isn't NULL
        printf("%d, ",aux->info);  //prints its info
        aux=aux->next;  //goes to next
    }

}
    
node* findInList(linkedList *l, int value){  //finds in list, if there is to find
    
    node *aux = l->first;

    while(aux != NULL){ //while node isn't NULL
        if(aux->info == value){ //checks if value is equal aux->info
            printf("\n%d is in the list",value);    //prints it's in and returns
            return aux;
        }
        aux = aux->next;    //goes to next element
    }

    printf("\n%d is not in the list",value);    //prints it's not in list and returns NULL
    return NULL;

}

void removeFromList(linkedList *l, int value){

    node *aux = l->first;

    if(findInList(l,value) != NULL){    //if value is in list

        while (aux->next->info != value){  //goes to pre-value
            aux = aux->next;
        }

        aux->next = aux->next->next;    //node points to next next value
        free(aux->next);    //frees unused node

        printf(" and got removed!");
        return;
    }
    printf(" so it can't be removed!");
}

void main(){

    linkedList *list = listInit();  //declare and allocate a linked list

    for(int i = 0; i <= 20; i++){   //adds 1-20 in the list
        addToList(list, i);
    }

    printf("\n\nprinting list:");
    printList(list);

    printf("\n\nsearching in list:");
    findInList(list, 18);
    findInList(list, 23);

    printf("\n\nremoving from list:");
    removeFromList(list,18);
    removeFromList(list, 23);

    printf("\n\nprinting list:");
    printList(list);
}