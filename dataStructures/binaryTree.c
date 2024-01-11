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

node *addToTree(node *root, int value){

    if(root == NULL){
        printf("\nadded %d",value);
        return createNode(value);
    }

    if(root->info < value){
        root->right = addToTree(root->right,value);

    }else if(root->info > value){
        root->left = addToTree(root->left,value);
    }
    
    return root;

}
//it's working now

void printTree(node *root){     //prints tree


    if (root == NULL){
        return;
    }
    
    /*
    if (root->left == NULL && root->right == NULL){    //if node is leaf, print its data   
        printf(" %d,",root->info); 
        return;
    }

    if (root->left != NULL){   //if there is left, starts recursion
       printTree(root->left);
    }    

    if (root->right != NULL){   //if there is right, starts recursion
       printTree(root->right);
    }
    */

    printf(" %d,",root->info);
    printTree(root->left);
    printTree(root->right);

} 

void main(){

    binTree *tree = binTreeInit();
    //node *nodeArray[MAX];
    node *root = tree->first;


    srand(time(NULL));

    for(int i = 0; i<= MAX; i++){
        int r = rand()%100;
        root = addToTree(root, r);
    } 

    printf("\n\nTREE:");
    printTree(root);

}

