#include <stdio.h>
#include <stdlib.h> //malloc(),realloc() + exit();
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include "C:\Users\PC\Desktop\LabsC\SomeLibs\StrokiLiba.h"

#ifndef DEBUG_TEST
//#define DEBUG_TEST
#endif // DEBUG_TEST

#ifndef DEBUG_TEST2
//#define DEBUG_TEST2
#endif // DEBUG_TEST2


int main()
{
    printf("\t\t -------------Lab4 programm-----------\n");

    printf("\t@The word criteria: Word can include only letters from latin alphabet\n"
                "\t@Example: \"Hello!\" - is'nt a word, \"Hello !\" - \"Hello\" is a word!\n"
           "\t@The sentence criteria:\n"
                                                "\t\t1) should inlcude at least 1 word beggining with upper latter;\n"
                                                "\t\t2) should include only words;"
                                                "\t\t3) should ends with '.' or '!' or '?' symbol;\n"
                                                "\t\t4) can include synbol ',' \n"
                                                "\t\t5) all symbols should have spaces from 2 sides\n"
                "\t@Example: \"Hello dear .\" - is a sentence, \"hello dear .\" - isn't a sentence\n"
                "\t@Warning : You can't move the word to another line\n\n");

    while (true){

    // The int type cannot be longer than 10 chars ...
    char amountOfStringsTmp[13];
    int amountOfStrings = 0;
    int userTextLength = 0;
    int amountOfWords = 0;
    int amountOfSentences = 0;

    printf("Input amount of strings in text : ");
    gets(amountOfStringsTmp);

    while (!isint(amountOfStringsTmp))
    {
        printf("You enter smth wrong!\n Try again : ");
        gets(amountOfStringsTmp);
    }

    amountOfStrings = Perevodvint(amountOfStringsTmp);

    printf("Print your text : \n");

    // Array creating.
    char **userText = (char**)malloc( amountOfStrings * sizeof(char*) );
    for (int i=0; i < amountOfStrings; ++i)
    {
        userText[i] = (char*)malloc( (MAX_STR_LEN + 1) * sizeof(char) );
    }

    // Input text.
    for (int i = 0; i<amountOfStrings; ++i)
    {
        fgets(userText[i], MAX_STR_LEN, stdin);
    }
    // Length of text.
    for (int i = 0; i<amountOfStrings; ++i )
    {
        userTextLength += (razmer( userText[i] ) + 1) ;
    }

    printf("\nOutput : \n");

    #ifdef DEBUG_TEST
    // Output text.
    printf("Your text : \n");
    PrintArray(userText, amountOfStrings);
    #endif // DEBUG_TEST

    // Amount of words.
    amountOfWords = AmountOfWords(userText, amountOfStrings);
    printf("Amount of words : %d\n", amountOfWords);

    // Array of words.
    char **wordsArray = (char**)malloc( amountOfWords * sizeof(char*) );
    for (int i = 0; i < amountOfWords; ++i)
    {
        wordsArray[i] = (char*)malloc( (MAX_STR_LEN+1) * sizeof(char) );
    }

    InitializeArrayOfWords(userText, wordsArray , amountOfStrings, amountOfWords);

    #ifdef DEBUG_TEST
    printf("Your array of Words : \n");
    PrintArray(wordsArray, amountOfWords);
    printf("\n");
    #endif // DEBUG_TEST

    // Amount of sentences.
    amountOfSentences = AmountOfSentences(userText ,amountOfStrings);
    printf("Amount of sentences : %d\n", amountOfSentences);

    // Array of sentences.
    char** sentencesArray = (char**)malloc( amountOfSentences * sizeof(char*) );
    for (int i = 0; i < amountOfSentences; ++i)
    {
        sentencesArray[i] = (char*)malloc( userTextLength * sizeof(char) );
    }

    InitializeArrayOfSentences(userText, sentencesArray, amountOfStrings, amountOfSentences, userTextLength);

    #ifdef DEBUG_TEST
    printf("Your array of Sentences : \n");
    PrintArray(sentencesArray, amountOfSentences);
    printf("\n");
    #endif // DEBUG_TEST

    int lengthOfWords = LengthOfText(wordsArray, amountOfWords);
    int lengthOfSentences = LengthOfText(sentencesArray, amountOfSentences);

    #ifdef DEBUG_TEST2
    char* exampleArray = (char*)malloc( lengthOfWords );
    exampleArray = TheLongestString(wordsArray, amountOfWords, lengthOfWords);
    #endif // DEBUG_TEST2

    // The Longer word.
    printf( "The longest word : %s\n", TheLongestString(wordsArray, amountOfWords, lengthOfWords)  );

    // The Longer sentence.
    printf( "The longer sentence : %s\n\n", TheLongestString(sentencesArray, amountOfSentences, lengthOfSentences) );

    // ------------------------------------------------------------------------------------------------------------------------
    // Memory free().
    for (int i=0;i<amountOfStrings;++i)
    {
        free(userText[i]);
    }
    free(userText);

    for (int i=0;i<amountOfWords; i++)
    {
        free(wordsArray[i]);
    }
    free(wordsArray);

    for (int i = 0; i < amountOfSentences; ++i)
    {
        free(sentencesArray[i]);
    }
    free(sentencesArray);

    #ifdef DEBUG_TEST2
    free(exampleArray);
    #endif // DEBUG_TEST2

    } // while(true) ends.

    return 0;
}
