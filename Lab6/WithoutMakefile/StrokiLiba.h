#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#define MAX_INT 2147483467
#define MAX_DOUBLE 4294967296.0          ///I know that the max double is 1.7E+308 but for my purpose that's enough
#define MAX_STR_LEN 210 // not includes '\n'
#define true 1
#define false 0
#define myBool int
#define null 0

typedef struct _Node Node;
typedef struct _DblLinkedList DblLinkedList;
typedef struct _Customer Customer;
typedef struct _ShopLine ShopLine;

int RandBetween(int from, int to); // includes values as they is.

int BiggestInt(int x, int y);

time_t BiggestTime(time_t x, time_t y);

double binpow (int a, int n);

int razmer(char n[]);

int Perevodvint(char n[]);

double Perevodvdouble(char n[]);

///  FUNCTION FOR CHEKING INT INPUT.
int isint(char n[]);

///FUNCTION OF CHECKING OF DOUBLE INPUT.
int isdouble(char n[]);

int IsPositiveInt(char n[]);

void PrintArray(char** text, size_t textSize);

int LatinAlphabet(char letter);

void StringToNull(char *ourStr, int length);

int AmountOfWords(char **text, int amountOfStrings );

void InitializeArrayOfWords(char** text, char** wordsArray ,int amountOfStrings, int amountOfWords);

int AmountOfSentences(char** text, int amountOfStrings);

void InitializeArrayOfSentences(char** text, char** sentencesArray, int amountOfStrings, int amountOfSentences, int maxLengthOfSent);

char* TheLongestString(char** text, int amountOfStrings, int textLength);

int LengthOfText(char** text, int amountOfStrings);

int AmountOfStrings(char* text, int amountOfBytes);

int AmountOfComments(char* text, int totalBytes); // calculate amount of comments in bytes.

// ShopLine functions.

typedef struct _Customer{  // Node struct
    time_t creatingTime; // When it was created.
    struct _Customer *next;
    struct _Customer *prev;
    int indNumber;
} Customer;


typedef struct _ShopLine{
    size_t qsize; // amount of elements
    Customer *head;  // pointer to begining
    Customer *tail;  // pointer to ending

}ShopLine;

ShopLine* createShopLine();

void deleteShopLine(ShopLine **ourlist); // deleteShopLine(&ourlist);

time_t RemoveCustomerFront(ShopLine *ourlist); // Delete element from begin and returns its CreatingTime.

void AddCustomerBack(ShopLine *ourlist, time_t creatingTime, int *indNum); // Add element in the end.

void PrintShopLine(ShopLine *ourList);

// Some 4 lab needed functions ----------

// it removes customer and change "customerWasRemoved" if condition true
void TryRemoveCustomer(time_t removeCustomer, time_t removeCustomerFlag1, time_t removeCustomerFlag2, int *customerWasRemoved, ShopLine* ourShopLine, time_t *maxTime );

void UpdateRemoveCondition(time_t *removeCustomer, time_t *removeCustomerFlag1, time_t *removeCustomerFlag2, int *customerWasRemoved, ShopLine* ourShopLine );

void TryPrintShopLine(time_t const printTime, time_t *printFlag1, time_t *printFlag2, myBool *wasPrinted, ShopLine *ourList);
