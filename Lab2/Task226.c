#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>

#define MAX_DOUBLE 4294967296.0          ///I know that the max double is 1.7E+308 but for my purpose that's enough

const double Pi = 3.1415926535897932;

int razmer(char n[])    ///THE SIZE OF ARRAY WITHOUT THE LAST ELEMENT ('\0')
{
    int i=0;
    while (n[i]!='\0'){
        i++;
    }

    return i ;
}

double binpow (int a, int n) {        /// V STEPEN
	if (n == 0)
		return 1;

    if (n<0){
        if ((-1*n) % 2 == 1)
            return binpow (a, n+1) * (1.0/a);
        else {
            double b = binpow (a, n/2);
            return b * b;
        }
    }
    if (n>0){
        if (n % 2 == 1)
            return binpow (a, n-1) * a;
        else {
            double b = binpow (a, n/2);
            return b * b;
        }
    }
}

double binfact (int n)
{
    int r = 1;

    for (int i=2; i<=n; i++)
    {
        r *= i;
    }

    return r;
}

double Perevodvdouble(char n[])
{
    double chislo = 0;
    int BeforeDot = 0;
    int AfterDot = 0;
    int Dot = 0;

    int i=0;
    while (n[i]!=',' && n[i]!='.' && n[i]!='\0'){
        BeforeDot++;
        i++;
    }
    i = 0;
    while (n[i]!='\0'){
        if (n[i]==',' || n[i]=='.'){
            Dot++;
        }
        i++;
    }

    if (Dot == 1){
        AfterDot = razmer(n) - BeforeDot - 1;
    }

    int flag = 0;
    int NumAfterDot = 0;
    i=0;
    while (n[i]!='\0'){

        if (n[i]==',' || n[i]=='.'){
            flag = 1;
        }

        if (flag == 0){
            chislo += binpow(10, (BeforeDot - i - 1)) * (n[i] - '0');
        }
        else if (flag == 1 && n[i]!='.' && n[i]!=','){
            chislo += binpow(10, (NumAfterDot) ) * (n[i] - '0');
        }

        if (flag){
            NumAfterDot--;
        }

        i++;
    }

    return chislo;
}

int isdouble(char n[])  ///FUNCTION OF CHECKING OF DOUBLE INPUT
{
    if (razmer(n)>27 || n[0] == ',' || n[0] == '.'){
        return 0;
    }

    int counter = 0;
    int dotorcomma = 0;
    int ZnakAfterdotOrComma = 0;
    int i=0;
    while (n[i]!='\0'){
        if (isdigit(n[i]) == 0){
            if (n[i]=='.' || n[i]==','){
                dotorcomma++;
            }
            else {
                counter++;
            }
        }
        i++;
    }

    if (dotorcomma>1 || counter>0){
        return 0;
    }

    int flag = 0;
    i = 0;
    while (n[i]!='\0'){
        if (flag){
            ZnakAfterdotOrComma++;
        }

        if (n[i] == '.' || n[i] == ','){
            flag = 1;
        }

        i++;
    }

    if (ZnakAfterdotOrComma>16 || Perevodvdouble(n) > MAX_DOUBLE){
        return 0;
    }
    else {
        return 1;
    }
}

int main()
{
//    double x = 0;
//    double epsilon = 0;
    double OurSin = 0;
    char x[28] = "nothing";
    char epsilon[28] = "nothing";



    printf("Enter an x : ");
    scanf("%s", x);
    //scanf("%lf", &x);
    while (isdouble(x)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", x);
    }


    printf("Enter an epsilon : ");
    scanf("%s", epsilon);
//    scanf("%lf", &epsilon);
    while (isdouble(epsilon)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", epsilon);
    }

    OurSin = sin(Perevodvdouble(x));
    printf("Sin (x) = %lf\n", OurSin);

    double OurExpression = Perevodvdouble(x) ;
    double Factor = 1;
    int n = 2;
    while ( fabs(OurExpression - OurSin) > Perevodvdouble(epsilon) )
    {
        Factor *= (n-1)*2*((n-1)*2+1);
        OurExpression += pow(-1, n-1) * ( pow( Perevodvdouble(x) ,(2*n - 1)) /  Factor );
        n++;
    }

    printf("OurExpression = %lf\n", OurExpression);
    printf("Otvet : n = %d\n", n);



    return 0;
}
