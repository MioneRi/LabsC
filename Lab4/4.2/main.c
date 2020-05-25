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

int main()
{
    printf("\t\t\t-------------------LAB4----------------------------\n");
    printf("\t\t@Note : commentsSize includes symbols '\\n' and '\\0' if they are there;\n");
    printf("\t\t@Warning : if there will not comments, commentLevel = 1/(all size)\n\n");

    float commentLevel = 0;
    int fileSize = 0;
    int commentsSize = 1;
    char tmpChar;
    char *fContent;

    // Open file.
    FILE *myFile;
    myFile = fopen("ProgrammFile1.txt", "r");

    if (!myFile)
    {
        printf("Error opening file.");
        return -1;
    }

    fseek(myFile, 0L, SEEK_END); // Move pointer to the end of file.
    fileSize = ftell(myFile); // Now we know the size of file.
    fseek(myFile, 0L, SEEK_SET); // Move pointer to the begin of file.

    // Reading the content.
    fContent = (char*)malloc( fileSize );
    int itmp = 0;
    fscanf(myFile ,"%c", &tmpChar );

    while(!feof(myFile))
    {
        fContent[itmp] = tmpChar;
        fscanf(myFile ,"%c", &tmpChar );
        ++itmp;
    }
    fContent[itmp] = '\0';
    fileSize = itmp; // This size includes '\n' and '\0'.
    fseek(myFile, 0L, SEEK_SET); // Move pointer to the begin of file.

    #ifdef DEBUG_TEST
    printf("Our text from file : \n");
    printf("%s", fContent);
    printf("\n");
    printf("the size of all text : %d\n\n", fileSize);
    #endif // DEBUG_TEST

    // Close file.
    fclose(myFile);

    // Calculate result.
    commentsSize = AmountOfComments(fContent, fileSize);

    #ifdef DEBUG_TEST
    printf("commentsSize = %d \n\n", commentsSize);
    #endif // DEBUG_TEST

    if (commentsSize == 0){
        commentsSize = 1;
    }

    commentLevel = (float)commentsSize / (float)fileSize ;

    printf("The commentLevel : %f  \n", commentLevel);
    printf("The commentLevel : ( %d / %d ) \t*Note. The first parametr = commentsSize, second = fileSize\n\n", commentsSize, fileSize);



    // Clear memory. ----------------------------------------------
    free(fContent);


    return 0;
}
