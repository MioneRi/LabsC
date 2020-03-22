#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <ctype.h>
#include "StrokiLiba.h"

//                                       ADD THE EXCEPTIONS LATER

                        //NOTE: const int max_Length = 119; // Because of size of console window

int main()
{
    int strings = 0;
    char temp;

    printf("Print the amount of strings : ");
    scanf("%d", &strings);
    fflush(stdin);         //for cleaning the cash!

    char **myText = (char**)malloc( strings * sizeof(char*) ); //Initialization of array ...
    int *lengthOfStrings = (int*)malloc( max_Length * sizeof(int) );

    for (int i=0;i<strings;++i)
    {
        myText[i] = (char*)malloc(max_Length * sizeof(char));

        fgets(myText[i], max_Length, stdin);
        fflush(stdin);
        lengthOfStrings[i] = razmer(myText[i]); //length with '\0'

        while (lengthOfStrings[i] == 0 )
        {
            printf("You have to enter smth in this string!\n Try again: ");
            fgets(myText[i], max_Length, stdin);
            fflush(stdin);
            lengthOfStrings[i] = razmer(myText[i]);
        }
        while ( lengthOfStrings[i] > max_Length )
        {
            printf("You have to enter less symbols!\n Try again: ");
            fgets(myText[i], max_Length, stdin);
            fflush(stdin);
            lengthOfStrings[i] = razmer(myText[i]);
        }

    }

    printf("\n");
    for (int i=0;i<strings;++i)
    {
        printf("Length [%d]: %d\n", i, lengthOfStrings[i]);
    }

    printf("Amount of Words : %d\n\n", AmountOfWords(myText, strings));
    printf("\nThe amount of sentences : %d\n\n", AmountOfSentences(myText, strings));

    printf("Our longer word is : ");
    PrintLongerWord( myText, strings, lengthOfStrings );


    for (int i = 0; i < strings; ++i) //Cleaning memory ...
    {
        free(myText[i]);
    }
    free(myText);
    free(lengthOfStrings);

    return 0;
}
