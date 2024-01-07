#ifndef _STACK_H_
#define _STACK_H_

typedef struct NODE{
    int info;
    struct NODE *next;
}node;

typedef struct STACK{
    node *first;
}stack;

#endif