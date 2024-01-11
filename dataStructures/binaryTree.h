#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#define MAX 7

typedef struct NODE{
    int info;
    struct NODE *left;
    struct NODE *right;
}node;

typedef struct BINTREE{
    node *first;
}binTree;


void printTree(node *root);
node* addToTree(node *root, int value);
node* createNode(int value);
binTree* binTreeInit();


#endif