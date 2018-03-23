#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#define max(a,b) (a>b?a:b)


struct node {
    int key;
    struct node* left;
    struct node* right;
};
typedef struct node bNode;



bNode* newNode (int key)
{
    bNode* node = malloc(sizeof(bNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}   

void printNode(bNode* node)
{
    printf("\n%d\n", node->key);
}

int sizeHeight(bNode* tree)
{
    if (tree == NULL)
        return 0;
        
    return max(sizeHeight(tree->left), sizeHeight(tree->right))+1;    
}

int sizeTree(bNode* tree)
{
    if (tree == NULL)
        return 0;
        
    return sizeTree(tree->left) + sizeTree(tree->right)+1;    
}

void destroyTree(bNode** treeRef)
{
    bNode* tree = *treeRef;
    
    if (tree != NULL){
        destroyTree(&tree->left);
        destroyTree(&tree->right);
        free(tree);
    }
    *treeRef = NULL;
}

void inOrder(bNode* tree)
{
    if(tree != NULL){
    inOrder(tree->left);
    printf("%d", tree->key);
    inOrder(tree->right);
    }
}

void preOrder(bNode* tree)
{
    if(tree != NULL){
    printf("%d", tree->key);
    preOrder(tree->left);
    preOrder(tree->right);
    }
}

void postOrder(bNode* tree)
{
    if(tree != NULL){
    postOrder(tree->left);
    postOrder(tree->right);
    printf("%d", tree->key);
    }
}


void main(){
    
    
    bNode* root = newNode(60);
    root->right = newNode(20);
    root->left = newNode(10);
    //bNode* y = newNode(v);
    //bNode* z = newNode(v);
    printf("size:%d\n",sizeTree(root));
    printf("height:%d\n", sizeHeight(root));
    
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");

    destroyTree(&root);
    
    //printf("%d\n ", sizeTree(root));
   // printNode(root);
    
    
}
