#include <stdio.h>
#include <stdlib.h> //malloc(),realloc() + exit();
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include "C:\Users\PC\Desktop\LabsC\SomeLibs\StrokiLiba.h"

#ifndef DEBUG_TEST
//#define DEBUG_TEST
#endif // DEBUG_TEST

int main()
{
    printf("\t\t--------------------------Lab5------------------------\n");
    printf("\t\t-----------------------SuperMarket--------------------\n");
    printf("\t\t@Note : ShopLine wiil print every 5 sec. (from \"head\" to \"tail\")\n");
    printf("\t\t @: - is a cashbox\n\n");

    // int number can't be longer than 10 chars.
    char userTimetmp[13];
    int userTime = 0;
    time_t progBeginTime;
    time_t afterCycleTime;
    time_t insertCustomerTime;
    time_t insertCustomerTimeFlag1;
    time_t insertCustomerTimeFlag2;
    time_t creatingCustomerTime;
    time_t removeCustomer;
    time_t removeCustomerFlag1;
    time_t removeCustomerFlag2;
    myBool customerWasRemoved;
    int maxAmountOfCustomers = 0;
    time_t maxTime = 0;
    time_t const printTime = 5; // frequency of printing
    time_t printFlag1;
    time_t printFlag2;
    myBool wasPrinted;
    int indCustomerNum = 0;

    srand(time(NULL)); // For different rand() results.

    printf("Input time (seconds) : ");
    gets(userTimetmp);

    while ( !(IsPositiveInt(userTimetmp)) )
    {
        printf("You enter smth wrong!\n Try again : ");
        gets(userTimetmp);
    }
    // Set time.
    userTime = Perevodvint(userTimetmp);
    progBeginTime = time(NULL);
    afterCycleTime = time(NULL);
    printFlag1 = time(0);
    printFlag2 = time(0);

    // initialize a ShopLine.
    ShopLine* ourShopLine = createShopLine();

    customerWasRemoved = true; // should be true.
    wasPrinted = true;
    PrintShopLine(ourShopLine);
    TryPrintShopLine(printTime, &printFlag1, &printFlag2, &wasPrinted, ourShopLine);
    // Time loop --------------------------------------------------------------------------------------------------------------
    while ( (int)difftime(afterCycleTime, progBeginTime) < userTime )
    {
        maxAmountOfCustomers = BiggestInt(maxAmountOfCustomers, ourShopLine->qsize );
        TryPrintShopLine(printTime, &printFlag1, &printFlag2, &wasPrinted, ourShopLine);

        // Look for remove
        TryRemoveCustomer(removeCustomer, removeCustomerFlag1, removeCustomerFlag2, &customerWasRemoved, ourShopLine, &maxTime);
        // Look for update remove
        UpdateRemoveCondition(&removeCustomer, &removeCustomerFlag1, &removeCustomerFlag2, &customerWasRemoved, ourShopLine);

        maxAmountOfCustomers = BiggestInt(maxAmountOfCustomers, ourShopLine->qsize);
        TryPrintShopLine(printTime, &printFlag1, &printFlag2, &wasPrinted, ourShopLine);

        insertCustomerTime = 1 + rand() % (10 - 1 + 1); // 1-10 sec. for adding new customer.
        insertCustomerTimeFlag1 = time(0);
        insertCustomerTimeFlag2 = time(0);

        // Time loop --------------------------------------------------------------------------------------------------------------
        do{
            maxAmountOfCustomers = BiggestInt(maxAmountOfCustomers, ourShopLine->qsize);
            TryPrintShopLine(printTime, &printFlag1, &printFlag2, &wasPrinted, ourShopLine);

            insertCustomerTimeFlag2 = time(0);
            removeCustomerFlag2 = time(0);
            afterCycleTime = time(NULL);
            printFlag2 = time(0);

            #ifdef DEBUG_TEST
            printf("lol\n");
            printf("diif time() : %f\n", difftime(insertCustomerTimeFlag2, insertCustomerTimeFlag1));
            printf("insert time : %ld\n", insertCustomerTime);
            #endif // DEBUG_TEST
            if (difftime(afterCycleTime, progBeginTime) >= userTime){
                goto TIME_LOOP_END;
            }
            #ifdef DEBUG_TEST
            printf("lol2\n");
            #endif // DEBUG_TEST

            // Look for remove
            TryRemoveCustomer(removeCustomer, removeCustomerFlag1, removeCustomerFlag2, &customerWasRemoved, ourShopLine, &maxTime);
            // Look for update remove
            UpdateRemoveCondition(&removeCustomer, &removeCustomerFlag1, &removeCustomerFlag2, &customerWasRemoved, ourShopLine);

        }while( (long int)difftime(insertCustomerTimeFlag2, insertCustomerTimeFlag1) < insertCustomerTime );
        // Time loop --------------------------------------------------------------------------------------------------------------

        // Now Time to add Customer.
        creatingCustomerTime = time(0);
        AddCustomerBack(ourShopLine, creatingCustomerTime, &indCustomerNum);
        maxAmountOfCustomers = BiggestInt(maxAmountOfCustomers, ourShopLine->qsize);
        TryPrintShopLine(printTime, &printFlag1, &printFlag2, &wasPrinted, ourShopLine);

        // Look for update remove
        UpdateRemoveCondition(&removeCustomer, &removeCustomerFlag1, &removeCustomerFlag2, &customerWasRemoved, ourShopLine);

        // Update flags.
        removeCustomerFlag2 = time(0);
        afterCycleTime = time(NULL);

    }
    // Time loop --------------------------------------------------------------------------------------------------------------
    // goto
    TIME_LOOP_END:
    TryPrintShopLine(printTime, &printFlag1, &printFlag2, &wasPrinted, ourShopLine);
    printf("\nMax amount of Costumers : %d\n", maxAmountOfCustomers);
    printf("Max time that Costumer was live : %ld\n\n", maxTime);

    deleteShopLine(&ourShopLine);

    return 0;
}
