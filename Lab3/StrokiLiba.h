
#define MAX_INT 2147483467
#define MAX_DOUBLE 4294967296.0          ///I know that the max double is 1.7E+308 but for my purpose that's enough

const int max_Length = 119;

double binpow (int a, int n) {
	if (n == 0)
    {
        return 1;
    }
    else if (n<0)
    {
        if ((-1*n) % 2 == 1)
            return binpow (a, n+1) * (1.0/a);
        else {
            double b = binpow (a, n/2);
            return b * b;
        }
    }
    else if (n>0)
    {
        if (n % 2 == 1)
            return binpow (a, n-1) * a;
        else {
            double b = binpow (a, n/2);
            return b * b;
        }
    }
}

int AmountOfWords(char *a, int length )
{
    int n = 0;
    for (int i = 0; i < length; i++)
    {
        if ((a[i] != '\0' && a[i] != ' ' && a[i] != ',' && a[i] != '.') && (a[i + 1] == '\0' || a[i + 1] == ' ' || a[i + 1] == ',' || a[i + 1] == '.'))
        {
            ++n;
        }
    }
    return n;
}

int razmer(char n[])    ///THE SIZE OF ARRAY WITHOUT THE LAST ELEMENT ('\0')
{
    int i=0;
    while (n[i]!='\0' && n[i]!='\n'){
        ++i;
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
    if ( razmer(n)>10 || razmer(n) == 0 ){
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

int CheckIfNullOrOne( char n[] )
{
    return !( n[0]!='0' && n[0]!='1' || razmer(n)>1 ); //wow!
}

int CheckCubicRoot(int number)
{
    int flag = 0;

    for (int i = 0; i<100000; i++)
    {
        if ( i*i*i == number )
        {
            flag = 1;
        }
    }

    return flag;
}
