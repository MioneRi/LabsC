#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

char n[99999];          ///99 999

int pravilno(char n[])              ///  FUNCTION FOR CHEKING IF THERE IS A SYMBOL
{
    int counter = 0;
    int i=0;
    while (n[i]!='\0'){
        if (isdigit(n[i]) == 0){
            counter++;
        }
        i++;
    }

    if (counter > 0){
        return 0;
    }
    else {
        return 1;
    }
}

int binpow (int a, int n) {        /// V STEPEN
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}

int razmer(char n[])    ///THE SIZE OF ARRAY WITHOUT THE LAST ELEMENT ('\0')
{
    int i=0;
    while (n[i]!='\0'){
        i++;
    }

    return i ;
}

int perevodvint(char n[])
{
    int chislo = 0;

    for (int i=0,j=1; i<razmer(n); i++,j++){
        chislo += binpow(10,razmer(n)-j) * (n[i] - '0');
    }

    return chislo;
}

int perevodvint2(char n)
{
    int N = n - '0';

    return N;
}

int vozrost(char n[])
{
    for (int i=1;i<razmer(n);i++){
            if (perevodvint2(n[i-1]) > perevodvint2(n[i])){
                 return 0;
            }
    }

    return 1;
}

int ubivanie(char n[])
{
    for (int i=1;i<razmer(n);i++){
            if (perevodvint2(n[i-1]) < perevodvint2(n[i])){
                 return 0;
            }
    }

    return 1;
}

int main()
{
    printf("Enter a natural number : ");

    gets(n);

    while (pravilno(n) == 0 || razmer(n) == 0 || razmer(n)>99999){

        printf("You enter smth wrong!\n Try again: ");
        gets(n);

        if (razmer(n) == 0){
            printf("   Do you want to stop the program? \n   (0/1) : ");
            char wov[2];
            gets(wov);
            while (((razmer(wov)+1) > 2) || ((wov[0]!='0') && (wov[0]!='1')) ){
                printf("     You entered smth wrong!\n     Try again(0/1):");
                gets(wov);
            }
            if (wov[0] == '1'){
                return 0;
            }
            else {
                printf(   "Try again (print the number): ");
                gets(n);
            }
        }
    }

    ///printf("Your Size: %d\n", razmer(n));

    ///printf("Your INT : %d  comment: [ minus 2 147 483 648, +2 147 483 647]\n", perevodvint(n)); ///THE MAX NUMBER FOR CONVER: 2 147 483 647 !

    printf("Vozrostanie - %d\n", vozrost(n));
    printf("Ubivanie - %d\n", ubivanie(n));
    printf("Nichego - %d", !(vozrost(n) || ubivanie(n)));

    if (vozrost(n) == 1){
        printf("\nYour Number vozrostaet!");
    }
    else if (ubivanie(n) == 1){
        printf("\nYour Number ubivaet!");
    }
    else if ( !(vozrost(n) || ubivanie(n)) ){
        printf("\nYour Number Ne vozrostaet and Ne ubivaet!!!");
    }
    else {
        printf("\nWHAAAAAAAT...\n  Some Unexpected Exception :(");
    }

    printf("\n");
    return 0;
}
