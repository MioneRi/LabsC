#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <ctype.h>
#include "StrokiLiba.h"

int main()
{
    FILE *myfile;

    char someStr[80][80];


    myfile = fopen("MyFile.txt", "r");

    //fscanf(myfile, "%s", someStr);  //TILL ' '
    //fgets(someStr, 50, myfile);

    while (fgets (someStr, 50, myfile) != NULL)
    {
        printf("%s", someStr);
    }


    //printf("Your text : \n%s", someStr);



    printf("\n\n");
    fclose(myfile);

    return 1;
}
