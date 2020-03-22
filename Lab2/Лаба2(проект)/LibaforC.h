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
    }

    if (Dot == 1){
        AfterDot = razmer(n) - BeforeDot - 1;
    }

    int flag = 0;
    for (int i=0;i<razmer(n);i++){

        if (n[i]==',' || n[i]=='.'){
            flag = 1;
        }
        if (flag == 0){

            chislo += binpow(10, (BeforeDot - i - 1)) * (n[i] - '0');

        }
        else if (flag == 1){

            chislo += ( (double)(1.0 / binpow(10, (i-BeforeDot) ) ) * (n[i] - '0'));

        }

    }

    return chislo;
}

int isint(char n[])              ///  FUNCTION FOR CHEKING INT INPUT
{
    if (razmer(n)>11){
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

    if (counter > 0){
        return 0;
    }
    if (Perevodvint(n)>2147483647){
        return 0;
    }
    else {
        return 1;
    }
}

int isdouble(char n[])  ///FUNCTION OF CHECKING OF DOUBLE INPUT
{
    if (razmer(n)>24){
        return 0;
    }
    if (n[0] == ',' || n[0] == '.'){
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
    }

    if (dotorcomma>1){
        return 0;
    }
    if (counter>0){
        return 0;
    }

    int flag = 0;
    i = 0;
    while (n[i]!='\0'){
        if (n[i] == '.' || n[i] == ','){
            flag = 1;
        }
        if (flag == 1 && n[i]!='\0'){
            ZnakAfterdotOrComma++;
        }
    }

    if (ZnakAfterdotOrComma>=12){
        return 0;
    }

    if (Perevodvdouble(n) > 2147483647.0){
        return 0;
    }
    else {
        return 1;
    }
}

