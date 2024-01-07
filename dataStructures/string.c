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

void freeSentence(sentence *sent) {

    element *aux = sent->first;
    element *aux2;

    while (aux != NULL) {   //while element isn't NULL
        aux2 = aux->next;   //aux2 receives next, clears previous
        free(aux);
        aux = aux2;
    }

    sent->first = NULL;

}

void main(){
    sentence *phrase = sentenceInit();
    char string[MAX] = "C programming", string02[MAX] = "PalmeirasMuitoFoda";
    int size;

    for(int i = 0; string[i] != NULL; i++){
        addToSentence(phrase, string[i]);
    }

    size = sentenceSize(phrase);

    printSentence(phrase);
    printf("\nsize = %d",size);
    freeSentence(phrase);

    for(int i = 0; string02[i] != NULL; i++){
        addToSentence(phrase, string02[i]);
    }

    size = sentenceSize(phrase);

    printSentence(phrase);
    printf("\nsize = %d",size);

    


}