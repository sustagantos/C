//A binary tree is a tree-type non-linear data structure
//with a maximum of two children for each parent

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binaryTree.h"


binTree* binTreeInit(){  //allocs memory for B Tree, and first->NULL
    
    binTree *bt = (binTree *) malloc (sizeof(binTree));
    bt->first = NULL;
    //printf("\nbin tree is initiated");
    return bt;

}

node* createNode(int value){  //allocs memory for B Tree Node, and puts a value in it

    node *n = (node *) malloc (sizeof(node));  //creates node and allocs memory to it
    n->info = value;
    n->left = NULL;
    n->right = NULL;
    //printf("\nnode with value of %d created", n->info);
    return n;
    
} 

void addToTree(binTree *t, node *newNode){    //ads to tree, in order

    node *aux = t->first;

    if(aux == NULL){    //if tree is empty
        //aux = newNode;
        t->first = newNode;
        printf("\ntree was empty, so added to first place");
        return;
    }

    if(newNode->info > aux->info){  //if it's bigger, goes to right
        printf("\ngoes to right");
        addToTree(aux->right, newNode);
    }

    if(newNode->info < aux->info){  //if it's smaller, goes to left
        printf("\ngoes to left");
        addToTree(aux->left, newNode);
    }

    free(aux);

}
//this function isn't working!!!!

void main(){

    binTree *tree = binTreeInit();
    node *nodeArray[MAX];

    srand(time(NULL));

    for(int i = 0; i<= MAX; i++){
        int r = rand()%100;
        node *newNode = createNode(r);
        nodeArray[i] = newNode;
        //printf("\nnode with value of %d created", r);
        addToTree(tree, nodeArray[i]);
    } 


}

