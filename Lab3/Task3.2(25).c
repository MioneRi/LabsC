#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include "StrokiLiba.h"
//scanf("%s", n); // scanf is bad function for arrays!
//fflush(stdin);

//                  INCLUDE EXCEPTIONS LATER

int main()
{
    printf("--------------------------------------THE CUBE PROGRAMM---------------------------------------------------------------\n\n");

    char n[11]; //the int type cannot be longer than 10 chars ...
    int opaqueElements = 0;

    printf("Enter an n : ");
    gets(n);

    while ( !isint(n) || Perevodvint(n) == 0 )
    {
        printf("You enter smth wrong.\n Try again : ");
        gets(n);
    }

    int intN = Perevodvint(n);

    char ***mainCube = (char***)malloc( intN * sizeof(char**) ); //Initialization of array
    for (int i = 0 ; i<intN; ++i)
    {
        mainCube[i] = (char**)malloc( intN * sizeof(char*));
    }
    for (int i = 0; i<intN; ++i)
    {
        for (int j = 0; j<intN; ++j)
        {
            mainCube[i][j] = (char*)malloc( intN * sizeof(char));
        }
    }

    printf("Enter an values of small cubes : \n");
    printf("1 - opaque (ne prozracniy) \n0 - transparent (prozracniy)\n\n");
    for (int i = 0; i<intN; ++i) // input values in the mainCube
    {
        for (int j = 0; j<intN; ++j)
        {
            for (int k = 0; k<intN; ++k)
            {
                printf("a[%d][%d][%d] = ", i, j, k);

                char *testArray = (char*)malloc(5 * sizeof(char) ); // TESTARRAY FOR CHEKING AN INPUT
                gets(testArray);

                while ( !CheckIfNullOrOne(testArray) )
                {
                    printf("You enter smth wrong.\n Try again : ");
                    gets(testArray);
                }

                mainCube[i][j][k] = testArray[0];

                //mainCube[i][j][k] = '1';
                if (mainCube[i][j][k] == '1')
                {
                    ++opaqueElements;
                }

                free(testArray);
            }
        }
    }

//    int minimalElements = pow(intN, 2);
//    double temp = pow(minimalElements, 1.0/3.0);
//    printf("The amount of opaque elements : %d\n", opaqueElements );
//    printf("The amount of minimal elements : %d\n", minimalElements );
//    printf("The pow() : %lf\n", pow(minimalElements, 1.0/3.0) );
//    printf("The round(pow()) : %lf\n", round(pow(minimalElements, 1.0/3.0)) );
//    printf("The temp : %lf\n", temp );
//    printf("The round(temp) : %lf\n", round(temp) );
//    printf("The cubic root : %d\n", CheckCubicRoot(minimalElements));

    if ( (CheckCubicRoot(minimalElements) == 1 ) && opaqueElements >= minimalElements /*( temp == round(temp) ) && opaqueElements >= minimalElements*/ )
    {
        printf("\n We can do it!+++++++++++++++++++++++++++++++++++");
    }
    else
    {
        printf("We can do it!.----------------------------------------");
    }

    for (int i = 0; i<intN; ++i)      //  CLEANING MEMORY
    {
        for (int j = 0; j<intN; ++j)
        {
            free(mainCube[i][j]);
        }
    }
    for (int i = 0 ; i<intN; ++i)
    {
        free(mainCube[i]);
    }

    free(mainCube);

    return 0;
}
