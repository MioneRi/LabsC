#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define MAX_INT 2147483467
#define MAX_DOUBLE 4294967296.0          ///I know that the max double is 1.7E+308 but for my purpose that's enough
#define MAX_STR_LEN 210 // not includes '\n'
#define true 1
#define false 0
#define myBool int
#define null 0

double binpow (int a, int n);

int razmer(char n[]);

int Perevodvint(char n[]);

double Perevodvdouble(char n[]);

///  FUNCTION FOR CHEKING INT INPUT.
int isint(char n[]);

///FUNCTION OF CHECKING OF DOUBLE INPUT.
int isdouble(char n[]);

struct Dyn1DArray;

struct Dyn2DArray;

void PrintArray(char** text, size_t textSize);

int LatinAlphabet(char letter);

void StringToNull(char *ourStr, int length);

int AmountOfWords(char **text, int amountOfStrings );

void InitializeArrayOfWords(char** text, char** wordsArray ,int amountOfStrings, int amountOfWords);

int AmountOfSentences(char** text, int amountOfStrings);

void InitializeArrayOfSentences(char** text, char** sentencesArray, int amountOfStrings, int amountOfSentences, int maxLengthOfSent);

char* TheLongestString(char** text, int amountOfStrings, int textLength);

int LengthOfText(char** text, int amountOfStrings);
