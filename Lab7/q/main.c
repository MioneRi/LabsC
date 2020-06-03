#include <stdio.h>
#include <stdlib.h> //malloc(),realloc() + exit();
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include "C:\Users\PC\Desktop\LabsC\SomeLibs\StrokiLiba.h"
#include "C:\Users\PC\Desktop\LabsC\SomeLibs\dynamicStructuresLiba.h"
#include "SomeFunctions.h"
#include "Products.h"

#ifndef DEBUG_TEST
//#define DEBUG_TEST
#endif // DEBUG_TEST

int main()
{
    printf("\t\t-------------------------------------Lab7-----------------------------\n");
    printf("\t\t\t\t\t\t   cShop.by  \n\n");

    int buyersIndNumber = 0; // Any buyer has its own indNumber;

    ProductList *ourProductList = CreateProductList();
    ProductList *ourBasket = CreateProductList();

    InitializeProducts(ourProductList); // Gets info from file "ProductsData.txt".

    while (true)
    {
        int mainChoice = 0;
        int subMainChoice = 0;
        //int indexNumberChoice = 0;
        // Create and input byer data
        Buyer *ourBuyer = CreateBuyer(&buyersIndNumber);
        system("cls");

        GOTO_Main_Menu :
        printf("Computers and accessories--------------------------------\n\n");
        PrintAndChoiceMainMenu(&mainChoice);

        switch(mainChoice)
        {
            case 1:
            case 2:
            case 3:
            case 4:
                {
                    GOTO_Submain_Menu:
                    PrintAndChoiceSubMenu(mainChoice, &subMainChoice);
                    if ( (mainChoice == 1 || mainChoice == 2 ) && subMainChoice == 3 ) goto GOTO_Main_Menu;
                    if ( (mainChoice == 3) && subMainChoice == 4 ) goto GOTO_Main_Menu;
                    if ( (mainChoice == 4) && subMainChoice == 5 ) goto GOTO_Main_Menu;

                    int submainMark = PrintAndChoiceProduct(ourProductList, ourBasket, mainChoice, subMainChoice); // "0" if wnna back.
                    if (!submainMark) goto GOTO_Submain_Menu;
                    goto GOTO_Main_Menu;
                }
                break;
            case 5:
                {
                    int gotoflag = 1;
                    PrintAndFindProductsBy(ourProductList, ourBasket, &gotoflag);
                    system("cls");
                    if (!gotoflag) goto GOTO_Main_Menu;
                    goto GOTO_Main_Menu;
                }
                break;
            case 6:
                {
                    int backFlag = false;
                    ShowBasket(ourBasket,ourBuyer, &backFlag);
                    if (backFlag == true) goto GOTO_Main_Menu;
                    goto GOTO_Main_Menu;
                }
                break;
            case 7:
                {
                    exit(0);
                }
        }

    free(ourBuyer);
    }

    DeleteProductList(&ourProductList); // Cleaning memory.
    DeleteProductList(&ourBasket);

    return 0;
}
