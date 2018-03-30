#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#define max(a,b) (a>b?a:b)

struct entry_s {
    int key;
    char value; 
};
typedef struct entry_s entry;

//tree structs
struct node {
    struct entry_s entry;
    struct node* left;
    struct node* right;
};
typedef struct node bNode;

typedef bNode* binaryTree;

//keytype
typedef int KeyType;

//protos
void inOrder(binaryTree tree);
void preOrder(binaryTree tree);

//


binaryTree btCreate()
{
    binaryTree tree = NULL; 
    return tree;
}

bNode* nodeCreate (entry key)
{
    bNode* node = malloc(sizeof(bNode));
    node->entry.key = key.key;
    node->entry.value = key.value;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}   

void btPrint(binaryTree tree)
{
   // printf("\n%d\n", tree->key);
    inOrder(tree);

}

int btHeight(binaryTree tree)
{
    if (tree == NULL)
        return 0;
        
    return max(btHeight(tree->left), btHeight(tree->right))+1;    
}

int btSize(binaryTree tree)
{
    if (tree == NULL)
        return 0;
        
    return btSize(tree->left) + btSize(tree->right)+1;    
}

void btDestroy(binaryTree* treeRef)
{
    binaryTree tree = *treeRef;
    
    if (tree != NULL){
        btDestroy(&tree->left);
        btDestroy(&tree->right);
        free(tree);
    }
    *treeRef = NULL;
}

void inOrder(binaryTree tree)
{
    if(tree != NULL){
    inOrder(tree->left);
    printf("%d\n", tree->entry.key);
    inOrder(tree->right);
    }
}

void preOrder(binaryTree tree)
{
    if(tree != NULL){
    printf("%d\n", tree->entry.key);
    preOrder(tree->left);
    preOrder(tree->right);
    }
}

void postOrder(bNode* tree)
{
    if(tree != NULL){
    postOrder(tree->left);
    postOrder(tree->right);
    printf("%d", tree->entry.key);
    }
}

bool btIsEmpty(binaryTree tree)
{
    return tree == NULL;
}

void bstInsert(binaryTree* tree, entry E)
{
    binaryTree btree = *tree;

    if(btIsEmpty(btree)){
         bNode* newNode = nodeCreate(E);
         *tree = newNode;
         return;
    }
      
    if(E.key > btree->entry.key)
        bstInsert(&btree->right, E);
        
    else
        bstInsert(&btree->left, E);
}

binaryTree btFind(binaryTree* tree, KeyType K)
{
    binaryTree btree = *tree;
    if(btIsEmpty(btree))
        return NULL;
        
    if(btree->entry.key == K)
        return btree;
    
    if(K > btree->entry.key)
        btFind(&btree->right, K);
    else
        btFind(&btree->left, K);
}

entry* eSearch(binaryTree tree, KeyType K)
{
    binaryTree node = btFind(&tree,K);
    if(node == NULL)
        return NULL;
        
    return &node->entry;
}

/*To insert a new node with key 
K, traverse the list, going right when K is larger than the 
cursor's
key, and left otherwise.  
A NULL branch
indicates
the insert location for the new leaf node.*/

void main(){
    
    KeyType K;
    
    entry e = {10,'h'};
    
    binaryTree tree = btCreate();
    assert(btIsEmpty(tree));
    assert(btHeight(tree) == 0);
    bstInsert(&tree, e);
    bstInsert(&tree, e);
    bstInsert(&tree, e);
    printf("\nTree:\n");
   /* btPrint(tree);
    assert(!btIsEmpty(tree));
    assert(btSize(tree) == 3);
    assert(btHeight(tree) == 2);
    
    bstInsert(&tree, 9);
    bstInsert(&tree, 5);
    bstInsert(&tree, 3);
    bstInsert(&tree, 11);
    bstInsert(&tree, 14);
    bstInsert(&tree, 12);
    bstInsert(&tree, 8);
    bstInsert(&tree, 4);
    bstInsert(&tree, 2);
    printf("\nTree:\n");
    btPrint(tree);
    assert(btSize(tree) == 12);
    assert(btHeight(tree) == 5);
    
    binaryTree nine = btFind(&tree,9);
    binaryTree ten = btFind(&tree, 10);
    binaryTree fourtytwo = btFind(&tree,42);
    
    assert(nine->key == 9);
    assert(ten->key == 10);
    assert(ten!=NULL);
    assert(fourtytwo== NULL);
    
    btDestroy(&tree);
    */
  /*  
    bNode* root = nodeCreate(60);
    root->right = nodeCreate(20);
    root->left = nodeCreate(10);
    //bNode* y = newNode(v);
    //bNode* z = newNode(v);
 //   assert(btIsEmpty((root)));
    
    printf("size:%d\n",btSize(root));
    printf("height:%d\n", btHeight(root));
    
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");

    destroyTree(&root);
    */
    //printf("%d\n ", sizeTree(root));
   // printNode(root);
    
    
}
