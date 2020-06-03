#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include "C:\Users\PC\Desktop\LabsC\SomeLibs\StrokiLiba.h"

typedef struct _ProductInfo{
    int section;
    int subsection;
    int indexNumber; // Displays under which number it will be displayed.
    char *name;
    int cost;
    int available;
    int guarante;
    char *country;
    int individualNumber;

} ProductInfo;

typedef struct _Product{

    ProductInfo* info;
    struct _Product *next;
    struct _Product *prev;

} Product;

typedef struct _ProductList{
    size_t qsize; // amount of elements
    Product *head;  // pointer to begining
    Product *tail;  // pointer to ending

} ProductList;

ProductList* CreateProductList();

void DeleteProductList(ProductList **ourlist);

void AddProduct(ProductList *ourlist, ProductInfo *value);

int InitializeProducts(ProductList *ourList);

void ClearIndNumbers(ProductList *ourList);

void PrintProduct(Product *ourProduct);



#endif // PRODUCTS_H
