//creating string for C!

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>     //C lib

#include "string.h"     //mine


sentence* sentenceInit(){  //allocs memory for sentence, and first->NULL
    
    sentence *s = (sentence *) malloc (sizeof(sentence));
    s->first = NULL;
    return s;

}

element* createElement(char digit){  //allocs memory for element, and puts a letter in it

    element *e = (element *) malloc (sizeof(element));  //creates node and allocs memory to it
    e->letter = digit;
    e->next = NULL;
    return e;
    
}

void addToSentence(sentence *s, char digit) {  //adds a digit to the string

    element *newElement = createElement(digit);  //creates a new node, with parameter digit
    element *aux = s->first;  //aux = the first list item

    if (aux == NULL) {  //if aux is NULL, means sentence is empty, then adds to 1st position
        s->first = newElement;

    }else{
    
        while (aux->next != NULL){  //goes to pre-last
            aux = aux->next;
        }

        newElement->next = NULL;  //new element is last element, therefore, points to NULL
        aux->next = newElement;
    }

}

void printSentence(sentence *s){  //prints sentence

    if(s != NULL){  
        
        element *aux = s->first;       
        printf("\nsentence: ");

        while(aux!=NULL){  //while element isn't NULL
            printf("%c",aux->letter);  //prints its info
            aux=aux->next;  //goes to next
        }
    }

}

int sentenceSize(sentence *s){ //prints sentence size
    int size = 0;
    element *aux = s->first; 
    while(aux != NULL){  //while element isn't NULL
        size++;     //adds 1
        aux=aux->next;  //goes to next
    }
    return size;

}

void freeSentence(sentence *sent) {     //frees sentence

    element *aux = sent->first;
    element *aux2;

    while (aux != NULL) {   //while element isn't NULL
        aux2 = aux->next;   //aux2 receives next, clears previous
        free(aux);
        aux = aux2;
    }

    sent->first = NULL;

}

void copySentence(sentence *destination, sentence *source){     //copies second to first

    element *aux = source->first;
    while(aux != NULL){
        addToSentence(destination, aux->letter);
        aux = aux->next;
    }

}

void concatenate(sentence *destination, sentence *first, sentence *second){

    element *aux = destination->first;
    copySentence(destination, first);   //copies first to destination
    copySentence(destination, second);  //copies second to destination

}

void main(){

    char userInput01[MAX], userInput02[MAX];
    int s01size, s02size;

    sentence *s01 = sentenceInit();
    sentence *s02 = sentenceInit();
    sentence *s03 = sentenceInit();


    printf("\nthis is dinamic \"string\" in C!");
    printf("\nit allocates memory in execution time to it, in sort of a linked list");


    printf(SEPARATOR);


    printf("\nType something: ");
    fgets(userInput01, MAX, stdin);     //gets user input
    userInput01[strcspn(userInput01, "\n")] = '\0';     //changes "\n" to "\0"

    for(size_t i=0; i<strlen(userInput01); i++){    //goes trough user input adding to sentence
        addToSentence(s01, userInput01[i]);
    }

    s01size = sentenceSize(s01);    //gets sentence size

    printSentence(s01);
    printf(" has %d characters (var is s01)",s01size);


    printf(SEPARATOR);


    printf("\nFirst sentence will be copied to another");

    copySentence(s02, s01);     //s01 copied to s02
    freeSentence(s01);

    printf("\nFirst is now empty, so type another one: ");
    fgets(userInput01, MAX, stdin);     //gets user input
    userInput01[strcspn(userInput01, "\n")] = '\0';     //changes "\n" to "\0"

    for(size_t i=0; i<strlen(userInput01); i++){    //goes trough user input adding to sentence
        addToSentence(s01, userInput01[i]);
    }


    printf(SEPARATOR);    


    printSentence(s01);
    printf(" (var is s01)");
    printSentence(s02);
    printf(" (var is s02)");


    printf(SEPARATOR);


    printf("\nNow, this is the concatenated version of both sentences:");
    concatenate(s03, s01, s02);

    printSentence(s03);
    printf(" (var is s03)");
}