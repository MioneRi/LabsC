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

Tree *AddNodeTree(Tree *ourParent, int value) // ourParent - is a parent of obj. that we have to add.
{
    Tree *tmp = (Tree*)malloc(sizeof(Tree));
    tmp->key = value;
    tmp->left = tmp->right = null;

    if (ourParent == null){
        ourParent = tmp;
    }
    else{
        if (tmp->key < ourParent->key){
            ourParent->left = tmp;
        }
        else{
            ourParent->right = tmp;
        }
    }

    return tmp;
}

void MakeTreeFromQueue(Tree *ourTree, Queue *ourQueue)
{
    Node *tmp = ourQueue->head->next; // Queue element.
    Tree *ourParent = ourTree;

    while (tmp){ // while Queue - isn't end.
        ourParent = AddNodeTree(ourParent, tmp->value);
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

void CutTree(Tree *root)
{
    Tree *actualNode = root;
    int CBC = false; // CBC - "Can be cutted"

    if ( (actualNode->left != 0) && (actualNode->right != 0) ){
        CBC = true;
    }
    else if ( (actualNode->left != 0) && (actualNode->right == 0) ){
        actualNode = actualNode->left;
        CBC = false;
    }
    else if ( (actualNode->left == 0) && (actualNode->right != 0) ){
        actualNode = actualNode->right;
        CBC = false;
    }

    if ( CBC == true  ) // Если имеются 2 ребенка проверяем есть ли у них дети
    {
        if ( (HaveNode(actualNode->left) == true) && (HaveNode(actualNode->right) == false )){
            actualNode = actualNode->left;
        }
        else if ( (HaveNode(actualNode->left) == false) && (HaveNode(actualNode->right) == true ) ){
            actualNode = actualNode->right;
        }
        else if ( (HaveNode(actualNode->left) == true) && (HaveNode(actualNode->right) == true ) ){ // не знаю что делать...
            CutTree(actualNode->left);
            CutTree(actualNode->right);
        }
        else if ( (HaveNode(actualNode->left) == false) && (HaveNode(actualNode->right) == false ) ){ // free()
            CBC = false;
            free(actualNode->left); // Всегда удаляем меньший элемент.
            return;
        }
        CBC = false;
    }

}
