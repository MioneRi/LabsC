#include <stdio.h>
#include <stdlib.h> //malloc(),realloc() + exit();
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <time.h>
//#include "StrokiLiba.h"
#include "dynamicStructuresLiba.h"

#ifndef DEBUG_TEST
//#define DEBUG_TEST
#endif // DEBUG_TEST

int main()
{
    printf("\t\t---------------------Lab6-------------------\n\n");

    Queue *ourQueue = CreateQueue();

//    // Initialize with values.
//    for (int i = 0; i < 10; ++i){
//        AddNodeBackQueue(ourQueue, RandBetween(0, 50));
//    }

    AddNodeBackQueue(ourQueue, 5);
    AddNodeBackQueue(ourQueue, 2);
    AddNodeBackQueue(ourQueue, 10);
    AddNodeBackQueue(ourQueue, 11);
    AddNodeBackQueue(ourQueue, 7);
    AddNodeBackQueue(ourQueue, 1);
    AddNodeBackQueue(ourQueue, 3);
    AddNodeBackQueue(ourQueue, 25);

    // Our Queue
    PrintQueue(ourQueue);
    printf("\n");

    // Make and print tree.
    printf("Our Tree : \n\n");
    Tree *ourTree = AddNodeTree(ourTree, ourQueue->head->value);
    MakeTreeFromQueue(ourTree, ourQueue);
    PrintTree(ourTree);

    // Cut and print tree.
    printf("\n\nOur Tree after cut : \n\n");
    CutTree(ourTree);
    PrintTree(ourTree);

    printf("\n");
    char a;
    scanf("%c", &a);
    // Clean memory.
    DeleteQueue(&ourQueue);
    DeleteTree(ourTree);

    return 0;
}
