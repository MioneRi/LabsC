#include "dynamicStructuresLiba.h"


// Queue functions.
void PrintQueue(Queue *ourList)
{
    Node *tmp = ourList->head;
    printf("Queue : ");
    while (tmp){
        printf("(%d) ", tmp->value); // Print number
        tmp = tmp->next;
    }
    printf("\n");
}

int RemoveNodeFront(Queue *ourlist) { // Delete element from begin and returns its value.
    Node *prev;
    int tmp;
    if (ourlist->head == NULL) {// if there's no elements. // Проверку на наличие эл-ов делать до вызова этой ф-ии!
        exit(2);
    }

    prev = ourlist->head;
    ourlist->head = ourlist->head->next; // перекинули голову на след эл-т
    if (ourlist->head) {// если след эл-т существует
        ourlist->head->prev = NULL; // то говорим что у него уже нет предыдущего
    }
    if (prev == ourlist->tail){ // если удаляыемый эл-т последний
        ourlist->tail = NULL;
    }// сохраняем знаение удале=яемого эл-а для последующего вывода
    tmp = prev->value;
    free(prev);
    ourlist->qsize--;
    return tmp;
}

void AddNodeBackQueue(Queue *ourlist, int value) { // Add element in the end.
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) { // check if there is a memory for it.
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = ourlist->tail;

    if (ourlist->tail) { // если он не пустой.
        ourlist->tail->next = tmp;
    }
    ourlist->tail = tmp;

    if (ourlist->head == NULL) { // если пустой.
        ourlist->head = tmp;
    }
    ourlist->qsize++;
}

Queue* CreateQueue() {
    Queue *tmp = (Queue*) malloc(sizeof(Queue));
    tmp->qsize = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void DeleteQueue(Queue **ourlist) { // deleteQueue(&ourlist);
    Node *tmp = (*ourlist)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*ourlist);
    (*ourlist) = NULL;
}

// Tree functions.

void DeleteTree(Tree *element)
{
    if (element != null){
        DeleteTree(element->left);
        DeleteTree(element->right);
        free(element);
    }
    else{
        return;
    }
}

Tree *AddNodeTree(Tree *ourTree, int value) // ourParent - is a parent of obj. that we have to add.
{
    if (ourTree == null){
        Tree *tmp = (Tree*)malloc(sizeof(Tree));
        tmp->key = value;
        tmp->left = tmp->right = null;
        ourTree = tmp;
    }
    else{
        if (value < ourTree->key){
            ourTree->left = AddNodeTree(ourTree->left, value);
        }
        else{
            ourTree->right = AddNodeTree(ourTree->right, value);
        }
    }

    return ourTree;
}

void MakeTreeFromQueue(Tree *ourTree, Queue *ourQueue)
{
    Node *tmp = ourQueue->head->next; // Queue element.
//    Tree *ourParent = ourTree;

    while (tmp){ // while Queue - isn't end.
        AddNodeTree(ourTree, tmp->value);
        tmp = tmp->next; // Change Queue element.
    }

}

void preorder(Tree *root)
{
    if (root == null){
        return;
    }
    else{
        printf("(%d) ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Tree *root)
{
    if (root == null){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf("(%d) ", root->key);
    }
}

void inorder(Tree *root)
{
    if (root == null){
        return;
    }
    else{
        inorder(root->left);
        printf("(%d) ", root->key);
        inorder(root->right);
    }
}

void PrintTree(Tree *root)
{
    printf("In preorder form : \n");
    preorder(root);
    printf("\nIn postorder form : \n");
    postorder(root);
    printf("\nIn inorder form : \n");
    inorder(root);
}

int HaveNode(Tree *element) // is 1 if there is at least one child.
{
    myBool result = false;
    if ( (element->left != null) || (element->right != null) ){
        result = true;
    }
    return result;
}

Tree *CutTree(Tree *ourNode) // можно возвращать значения
{
    int CBC = false; // CBC - "Can be cutted"

    if ( (ourNode->left != 0) && (ourNode->right != 0) ){
        CBC = true;
    }
    else if ( (ourNode->left != 0) && (ourNode->right == 0) ){
        ourNode->left = CutTree(ourNode->left);
        CBC = false;
    }
    else if ( (ourNode->left == 0) && (ourNode->right != 0) ){
        ourNode->right = CutTree(ourNode->right);
        CBC = false;
    }

    if ( CBC == true  ) // Если имеются 2 ребенка проверяем есть ли у них дети
    {
        if ( (HaveNode(ourNode->left) == true) && (HaveNode(ourNode->right) == false )){
            ourNode->left = CutTree(ourNode->left);
        }
        else if ( (HaveNode(ourNode->left) == false) && (HaveNode(ourNode->right) == true ) ){
            ourNode->right = CutTree(ourNode->right);
        }
        else if ( (HaveNode(ourNode->left) == true) && (HaveNode(ourNode->right) == true ) ){ // не знаю что делать...
            ourNode->left = CutTree(ourNode->left);
            ourNode->right = CutTree(ourNode->right);
        }
        else if ( (HaveNode(ourNode->left) == false) && (HaveNode(ourNode->right) == false ) ){ // free()
            CBC = false;
            free(ourNode->left); // Всегда удаляем меньший элемент.
            ourNode->left = 0;
        }
        CBC = false;
    }

    return ourNode;
}
