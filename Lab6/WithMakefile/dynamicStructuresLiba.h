#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#define null 0
#define true 1
#define false 0
#define myBool int

// Queue stuff.
typedef struct _Node{  // Node struct
    int value;
    struct _Node *next;
    struct _Node *prev;

} Node;

typedef struct _Queue{
    size_t qsize; // amount of elements
    Node *head;  // pointer to begining
    Node *tail;  // pointer to ending

} Queue;

Queue *CreateQueue();

void DeleteQueue(Queue **ourList); // DeleteQueue(&ourList) <- into main()

int RemoveNodeFront(Queue *ourList); // Deletes node from "head"

void AddNodeBackQueue(Queue *ourList, int value); // Insert el into "tail"

void PrintQueue(Queue *ourList);

// Tree stuff.

typedef struct _Tree{

    int key; // data field
    struct _Tree *left; // left child
    struct _Tree *right; // right child

} Tree;

void DeleteTree(Tree *element);

Tree *AddNodeTree(Tree *parentNode, int value);

void MakeTreeFromQueue(Tree *ourTree, Queue *ourQueue);

void preorder(Tree *root);

void postorder(Tree *root);

void inorder(Tree *root);

void PrintTree(Tree *root);

Tree *CutTree(Tree *root);
