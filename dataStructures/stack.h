#ifndef _STACK_H_
#define _STACK_H_

typedef struct NODE{
    int info;
    struct NODE *next;
    struct NODE *previous;
}node;

typedef struct STACK{
    node *first;
    node *last;
    int size;
}stack;


stack* stackInit();
node* createNode(int value);
void addTostack(stack *s, int value);
void printStack(stack *s);
void removeFromStack(stack *s);

#endif