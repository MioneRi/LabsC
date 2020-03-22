#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <ctype.h>

#define MAX_INT 2147483467
#define MAX_DOUBLE 4294967296.0          ///I know that the max double is 1.7E+308 but for my purpose that's enough


///INCLUDE ONE MORE LIBRUARY WITH MANY LABRIORIRES THERE (IT WAS ON LECTURE)

const double height = 2.6;                ///Height of room
const double squareofwindow = 2.15 * 1.5; ///3.225
const double squareofdoor = 0.9 * 2.05;   ///1.845
const double widthtube = 0.5;             ///Width of one tube
const double costgluepack = 2.5;          ///Cost of one glue pack

/// binpow makes a v stepeni n.
double binpow (int a, int n) {
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

int razmer(char n[])    ///THE SIZE OF ARRAY WITHOUT THE LAST ELEMENT ('\0')
{
    int i=0;
    while (n[i]!='\0'){
        i++;
    }

    return i ;
}

int Perevodvint(char n[])
{
    int chislo = 0;

    for (int i=0,j=1; i<razmer(n); i++,j++){
        chislo += binpow(10,razmer(n)-j) * (n[i] - '0');
    }

    return chislo;
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

int isint(char n[])              ///  FUNCTION FOR CHEKING INT INPUT
{
    if ( razmer(n)>10 ){
        return 0;
    }

    int counter = 0;
    int i=0;
    while (n[i]!='\0'){
        if (isdigit(n[i]) == 0){
            counter++;
        }
        i++;
    }

    if ( counter > 0 || Perevodvint(n) > MAX_INT ){
        return 0;
    }
    else {
        return 1;
    }
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
    setlocale(LC_ALL, "");

    //For calculation:
        int amountoftubes, amountofgluepacks;
        double squareall, squareneed, squareonetube, totalcost;
    ///Temporuary:
        double temp1, temp2;

    // NOTE: 28 chars for double because of 10 max + 16 after Dot. + '\0' + '.'
    ///For INPUT:
        char windows[11] = "nothing", doors[11] = "nothing"; ///(int)
        char length[28] = "nothing", width[28] = "nothing", costonetube[28] = "nothing", lengthtube[28] = "nothing"; ///(double)

    while (1){
        printf("1. Ввод длины и ширины комнаты(м).\n");
        printf("2. Ввод количества окон.\n");
        printf("3. Ввод количества дверных проемов.\n");
        printf("4. Ввод стоимости обойной трубки($).\n");
        printf("5. Ввод длины обоев в обойной трубке(м).\n");              ///I ADD THIS ONE CUS IT'S NECESSARY (commonly it's about 10.5 m)
        printf("6. Расчет площади оклейки(кв. м).\n");
        printf("7. Расчет необходимого количества обойных трубок.\n");
        printf("8. Расчет стоимости поклейки (с учетом клея).\n");
        printf("9. Выход из программы.\n");

        printf("\nВвыберите пункт: ");

        char choice[2];
        //int choice;
        scanf("%s", choice);
        while (isint(choice) == 0)
        {
            printf("You have to enter a number (0-9)\n");
            printf("Try againt : ");
            scanf("%s", choice);

        }

        switch (Perevodvint(choice))
        {
        case 1:
            printf("Введите длину(м): ");
            scanf("%s", length);

            while (isdouble(length)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", length);
            }

            printf("Введите ширину(м): ");
            scanf("%s", width);                           ///NOTE : use "%lf" in scanf() for double type!

            while (isdouble(width)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", width);
            }

            squareall = 2*height*(Perevodvdouble(length) + Perevodvdouble(width));                                ///ALL SQUARE
            printf("\n");
            break;
        case 2:
            printf("Введите кол-во окон: ");
            scanf("%s", windows);

            while (isint(windows)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", windows);
            }

            printf("\n");
            break;
        case 3:
            printf("Введите кол-во дверных проемов: ");
            scanf("%s", doors);

            while (isint(doors)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", doors);
            }

            printf("\n");
            break;
        case 4:
            printf("Ввведите стоимость обойной трубки($): ");
            scanf("%s", costonetube);

            while (isdouble(costonetube)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", costonetube);
            }

            printf("\n");
            break;
        case 5:
            printf("Введите длину обоев : ");
            scanf("%s", lengthtube);

            while (isdouble(lengthtube)==0){
                printf("you enter smth wrong! possibly problems: 1. the max number is 2 147 483 647 or double it for double\n       ");
                printf("                                  2. there should be only numbers (not other symbols)\n                     ");
                printf("                    3. if it's a double type there should be max 16 chars after dot or comma  \n  Try again: ");
                scanf("%s", lengthtube);
            }

            printf("\n");
            break;
        case 6:

            if ( length[0]!='n' && width[0]!='n' && windows[0]!='n' && doors[0]!='n' &&
                                ((Perevodvdouble(length)*Perevodvdouble(width)) >= (Perevodvint(windows)*squareofwindow + Perevodvint(doors)*squareofdoor)))
            {

                squareneed = squareall - ( Perevodvint(windows) *squareofwindow + Perevodvint(doors) *squareofdoor);
                printf("Площадь оклейки составляет: %lf", squareneed);
                printf("\n\n");

            }
            else
            {
                printf("   There is a problem!\n    possibly you have not some needed data or there's a logic problem there\n   Please add the necessary data and try again!\n");
            }
            break;
        case 7:
            if (lengthtube[0]!='n' && length[0]!='n' && width[0]!='n' && windows[0]!='n' && doors[0]!='n' &&
                                ( (Perevodvdouble(length)*Perevodvdouble(width)) >= (Perevodvint(windows)*squareofwindow + Perevodvint(doors)*squareofdoor)) )
            {

                squareonetube = widthtube* Perevodvdouble(lengthtube) ;  ///SQUARE OF ONE TUBE
                temp1 = (squareall - ( Perevodvint(windows) *squareofwindow + Perevodvint(doors) *squareofdoor)) / squareonetube; /// squareneed = squareall - ( Perevodvint(windows) *squareofwindow + Perevodvint(doors) *squareofdoor);
                amountoftubes = temp1>(int)temp1 ? (int)temp1+1 : (int)temp1;       ///AMOUNT OF TUBES
                printf("Необходимое кло-во обойных трубок : %d", amountoftubes);

                temp2 = (double)amountoftubes / 5.0;                       ///AMOUNT OF GLAY PACKS
                amountofgluepacks = temp2>(int)temp2 ? (int)temp2+1 : (int)temp2;
                printf("\n\n");

            }
            else
            {
                printf("   There is a problem!\n    possibly you have not some needed data\n   Please add the necessary data and try again!\n");
            }
            break;
        case 8:
            if (lengthtube[0]!='n' && length[0]!='n' && width[0]!='n' && windows[0]!='n' && doors[0]!='n' &&
                                ( (Perevodvdouble(length)*Perevodvdouble(width)) >= (Perevodvint(windows)*squareofwindow + Perevodvint(doors)*squareofdoor)))
            {

                totalcost = amountoftubes* Perevodvdouble(costonetube) + amountofgluepacks*costgluepack;
                printf("Итоговая стоимость поклейки : %lf", totalcost);
                printf("\n\n");

            }
            else
            {
                printf("   There is a problem!\n    possibly you have not some needed data\n   Please add the necessary data and try again!\n");
            }
            break;
        case 9:
            return 0;
            break;
        default:
            printf("You have to enter the number (0-9) !\n");
        }
    }

    printf("\n");
    return 0;
}
