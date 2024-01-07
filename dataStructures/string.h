#ifndef _STRING_H_
#define _STRING_H_
#define MAX 20
#define SEPARATOR "\n______________________________"

typedef struct ELEMENT{
    char letter;
    struct ELEMENT *next;
}element;

typedef struct SENTENCE{
    element *first;
}sentence;



#endif