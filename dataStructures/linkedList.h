#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_


typedef struct NODE{
    int info;
    struct NODE *next;
} node;

typedef struct LINKEDLIST{
    node *first;
} linkedList;


linkedList* listInit();
node* createNode(int value);

#endif