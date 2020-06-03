#ifndef SOME_FUNCTIONS_H
#define SOME_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include "C:\Users\PC\Desktop\LabsC\SomeLibs\StrokiLiba.h"
#include "Products.h"

//#define true 1
//#define false 0
//#define myBool int
//#define null 0

typedef struct _Buyer{

    int indNumber;
    char *name;
    char *surname;
    char *patronymic; // מעקוסעגמ
    char *phoneNumber;

} Buyer;

int TruePhoneNumber(char *number);

Buyer *CreateBuyer(int *indNumber);

int GetChoice(int from, int to); /// get int in range.

void PrintAndChoiceMainMenu(int *mainChoice);

void PrintAndChoiceSubMenu(int mainChoice, int *subMainChoice);

int PrintAndChoiceProduct(ProductList *ourList, ProductList *ourBasket, int mainChoice, int submainChoice);

void PrintAndFindProductsBy(ProductList *ourList, ProductList *ourBasket, int *gotoflag);

void PrintBuyer(Buyer *ourBuyer);

void ShowBasket(ProductList *ourBasket, Buyer *ourBuyer, int *backFlag);





#endif // SOME_FUNCTIONS_H
