#include "StrokiLiba.h"

// I have to include all this things in .h file.
//#include <stdio.h>
//#include <stdlib.h>

const int max_Length = 119;

void StringToNull(char *ourStr, int length) // better to use function : memset()
{
    for (int i = 0; i < length ; ++i){
        *(ourStr + i) = '\0';
    }
}

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

int LatinAlphabet(char letter)
{
    int result;
    char a = letter;

    if(( a<='Z' && a>='A') || (a<='z' && a>='a')){
        result = true;
    }
    else{
        result = false;
    }

    return result;
}

int AmountOfWords(char **text, int amountOfStrings )
{
    int words = 0;
    char space = ' ';
    char nextCh;
    myBool charWordFlag;
    myBool sameWord;
    // wordBegin == true if string can be a correct word
    myBool wordBegin;

    for (int i = 0; i < amountOfStrings; i++)
    {
        sameWord = false; // Should be false.
        wordBegin = false;

        for (int j = 0; text[i][j]!='\n' && text[i][j]!='\0' ;  j++)
        {
            // About nextCh
            {
            nextCh = text[i][j+1];
            }// nextCh ends.

            // Conditions.
            if ( LatinAlphabet(text[i][j]) ){
                charWordFlag = true;
            }
            else if ( text[i][j] == space ){
                charWordFlag = false;
                sameWord = false;
            }
            else{
                charWordFlag = false;
                sameWord = true;
            }// Conditions ends.

            // Logic.
            if (charWordFlag == true && sameWord == false){
                wordBegin = true;
                sameWord = true;
            }

            if (charWordFlag == false){
                wordBegin = false;
            }

            if ( (nextCh == space || nextCh == '\n') && charWordFlag == true && sameWord == true && wordBegin == true){
                ++words;
            }
            // Logic ends.
        }
    }

    return words;
}

void InitializeArrayOfWords(char** text, char** wordsArray ,int amountOfStrings, int amountOfWords)
{
    int iWord = 0;
    int jWord = 0;
    char nextLine = '\n';
    myBool trueWord;

    char space = ' ';
    char nextCh;
    myBool charFlag;
    myBool sameWord;
    // wordBegin == true if string can be a correct word
    myBool wordBegin;

    for (int i = 0; i < amountOfStrings; i++)
    {
        char tmpArray[MAX_STR_LEN + 1];
        memset(tmpArray, 0, (MAX_STR_LEN + 1) * sizeof(char) ); // Clear it at beggining.
        // Should be false.
        sameWord = false;
        wordBegin = false;
        trueWord = false;

        for (int j = 0; text[i][j]!='\n' && text[i][j]!='\0' ;  j++)
        {
            // About nextCh
            {
            nextCh = text[i][j+1];
            }// nextCh ends.

            // Conditions.
            if ( LatinAlphabet(text[i][j]) ){
                charFlag = true;
            }
            else if ( text[i][j] == space ){
                charFlag = false;
                sameWord = false;
            }
            else{
                charFlag = false;
                sameWord = true;
            }// Conditions ends.

            // Logic text.
            if (charFlag == true && sameWord == false){
                wordBegin = true;
                sameWord = true;
            }

            if (charFlag == false){
                wordBegin = false;
            }

            if ( (nextCh == space || nextCh == '\n') && charFlag == true && sameWord == true && wordBegin == true){
                trueWord = true;
            }
            else{
                trueWord = false;
            }
            // Logic text ends.

            // Logic wordsArray.
            if (wordBegin == true)
            {
                #ifndef DEBUG_TEST
                char tmpChar1 = tmpArray[jWord];
                char tmpChar2 = text[i][j];
                printf("\ntmpChar1 = %c \ntmpChar2 = %c", tmpChar1, tmpChar2);
                #endif // DEBUG_TEST

                tmpArray[jWord] = text[i][j]; //smth new
                ++jWord;
            }
            else if (wordBegin == false)
            {
                memset(tmpArray, 0, (MAX_STR_LEN+1) * sizeof(char) ); //очистка всех эл-ов массива
                jWord = 0;
            }

            if (trueWord == true){
                tmpArray[jWord+1] = '\0';

                // Get value
                for (int itmp = 0; itmp< (jWord+1); ++itmp)
                {
                    wordsArray[iWord][itmp] = tmpArray[itmp];
                }
                // end Get value

                iWord += 1;
                memset(tmpArray, 0, (MAX_STR_LEN+1) * sizeof(char) ); //очистка всех эл-ов массива
                jWord = 0; // that's a new line
                trueWord = false;
            }

            // Logic wordsArray ends.
        }
    }

}

int AmountOfSentences(char** text, int amountOfStrings)
{
    int sentences = 0;
    char space = ' ';
    char dot = '.';
    char ourChar; // That'll imagine some text[i][j].
    myBool sentenceBegin = false;
    myBool charFlag = false;
    myBool upperChar = false;
    myBool sameSentence = false;

    // For words check.
    char prevChar = ' ';
    char nextCh;
    myBool charWordFlag;
    myBool sameWord;
    myBool wordBegin;//

    for (int i = 0; i < amountOfStrings; ++i)
    {
        // For words check.
        sameWord = false; // Should be false.
        wordBegin = false;//
        for (int j = 0; (text[i][j]!='\0'&&text[i][j]!='\n'); ++j)
        {
            ourChar = text[i][j];

            // Basic starts.
            if (LatinAlphabet(ourChar) || ourChar == space || ourChar == ',')
            {
                charFlag = true;

                if (ourChar<='Z' && ourChar>='A' ){
                    upperChar = true;
                }
                else{
                    upperChar = false;
                }
            }
            else{
                charFlag = false;
            }

            // Basic ends.

            // For words check. -----------------------------------------------------------------
            // About nextCh
            {
            nextCh = text[i][j+1];
            }// nextCh ends.

            // Conditions.
            if ( LatinAlphabet(text[i][j]) ){
                charWordFlag = true;
            }
            else if ( text[i][j] == space ){
                charWordFlag = false;
                sameWord = false;
            }
            else{
                charWordFlag = false;
                sameWord = true;
            }// Conditions ends.

            // Logic.
            if (charWordFlag == true && sameWord == false){
                wordBegin = true;
                sameWord = true;
            }

            if (charWordFlag == false){
                wordBegin = false;
            }

            if (charWordFlag==false && sameWord==true)
            {
                if (ourChar == ',' && (nextCh == space || nextCh == '\n') && (prevChar == space || prevChar== '\n')){
                    // Ok.
                }
                else if ( (ourChar == dot || ourChar == '!' || ourChar == '?') && (prevChar == space || prevChar== '\n') ){
                    // Ok.
                }
                else{
                    // Not Ok.
                    sentenceBegin = false; // Here i change "sentenceBegin" ++++++++++++++
                }
            }

            if ( (nextCh == space || nextCh == '\n') && charWordFlag == true && sameWord == true && wordBegin == true){
                //++words;
            }

            // Ends words check. -----------------------------------------------------------------

            // Logic begin
            if (upperChar == true && sameSentence == false)
            {
                sentenceBegin = true;
                sameSentence = true;
            }

            if (charFlag == false && ourChar != dot && ourChar != '!' && ourChar != '?')
            {
                sentenceBegin = false;
                sameSentence = true;
            }

            if ( ourChar == dot || ourChar == '!' || ourChar == '?')
            {
                if (sentenceBegin == true && (prevChar == space || prevChar== '\n')){
                    ++sentences;
                }

                sameSentence = false;
                sentenceBegin = false;
            }
            // Logic ends.

            prevChar = ourChar;
        }
    }

    return sentences;
}

void InitializeArrayOfSentences(char** text, char** sentArray, int amountOfStrings, int amountOfSentences, int maxLengthOfSent)
{
    char space = ' ';
    char dot = '.';
    char ourChar; // That'll imagine some text[i][j].
    myBool sentenceBegin = false;
    myBool charFlag = false;
    myBool upperChar = false;
    myBool sameSentence = false;

    // For words check.
    char prevChar = ' ';
    char nextCh;
    myBool charWordFlag;
    myBool sameWord;
    myBool wordBegin;//

    // For initialize sentArray.
    int iSent = 0;
    int jSent = 0;
    myBool trueSent = false;

    char tmpArray[maxLengthOfSent + 1];
    memset( tmpArray, 0, (maxLengthOfSent + 1) * sizeof(char) );

    for (int i = 0; i < amountOfStrings; ++i)
    {
        // For words check.
        sameWord = false; // Should be false.
        wordBegin = false;//
        for (int j = 0; (text[i][j]!='\0'&&text[i][j]!='\n'); ++j)
        {
            ourChar = text[i][j];

            // Basic starts.
            if (LatinAlphabet(ourChar) || ourChar == space || ourChar == ',')
            {
                charFlag = true;

                if (ourChar<='Z' && ourChar>='A' ){
                    upperChar = true;
                }
                else{
                    upperChar = false;
                }
            }
            else{
                charFlag = false;
            }
            // Basic ends.

            // For words check. -----------------------------------------------------------------
            // About nextCh
            {
            nextCh = text[i][j+1];
            }// nextCh ends.

            // Conditions.
            if ( LatinAlphabet(text[i][j]) ){
                charWordFlag = true;
            }
            else if ( text[i][j] == space ){
                charWordFlag = false;
                sameWord = false;
            }
            else{
                charWordFlag = false;
                sameWord = true;
            }// Conditions ends.

            // Logic.
            if (charWordFlag == true && sameWord == false){
                wordBegin = true;
                sameWord = true;
            }

            if (charWordFlag == false){
                wordBegin = false;
            }

            if (charWordFlag==false && sameWord==true)
            {
                if (ourChar == ',' && (nextCh == space || nextCh == '\n') && (prevChar == space || prevChar=='\n')){
                    // Ok.
                }
                else if ( (ourChar == dot || ourChar == '!' || ourChar == '?') && (prevChar == space || prevChar=='\n') ){
                    // Ok.
                }
                else{
                    // Not Ok.
                    sentenceBegin = false; // Here i change "sentenceBegin" ++++++++++++++
                }
            }

            if ( (nextCh == space || nextCh == '\n') && charWordFlag == true && sameWord == true && wordBegin == true){
                //++words;
            }

            // Ends words check. -----------------------------------------------------------------

            // Logic begin
            if (upperChar == true && sameSentence == false)
            {
                sentenceBegin = true;
                sameSentence = true;
            }

            if (charFlag == false && ourChar != dot && ourChar != '!' && ourChar != '?')
            {
                sentenceBegin = false;
                sameSentence = true;
            }

            if ( (ourChar == dot || ourChar == '!' || ourChar == '?') )
            {
                if (sentenceBegin == true && (prevChar == space || prevChar== '\n') ){
                    trueSent = true; // Here i change trueSent. +++++++++
                }
                else{
                    trueSent = false;
                }

                sameSentence = false;
                sentenceBegin = false;
            }
            else{ // potom.
                trueSent = false;
            }
            // Logic ends.

            // Logic sentArray. -----------------------------------------------------------------------------------------
            if ( (sentenceBegin == true) || (sentenceBegin == false && trueSent == true) )
            {
                tmpArray[jSent] = text[i][j];
                ++jSent;
            }
            else if (sentenceBegin == false)
            {
                memset(tmpArray, 0, (maxLengthOfSent+1) * sizeof(char) ); //очистка всех эл-ов массива
                jSent = 0;
            }

            if (trueSent == true){
                tmpArray[jSent+1] = '\0';

                // Get value
                for (int itmp = 0; itmp< (jSent+1); ++itmp)
                {
                    sentArray[iSent][itmp] = tmpArray[itmp];
                }
                // end Get value

                iSent += 1;
                memset(tmpArray, 0, (maxLengthOfSent+1) * sizeof(char) ); //очистка всех эл-ов массива
                jSent = 0;
                trueSent = false;
            }

            // Logic sentArray ends. -----------------------------------------------------------------------------------------

            prevChar = ourChar;
        }
    }

}

int LengthOfText(char** text, int amountOfStrings)
{
    int ourLength = 0;

    for (int i = 0; i < amountOfStrings; ++i)
    {
        ourLength += razmer(text[i]);
    }

    ++ourLength; // Becuse of the last char '\0'.
    return ourLength;
}

char* TheLongestString(char** text, int amountOfStrings, int textLength)
{
    char* tmpArray = (char*)malloc( (textLength+1) * sizeof(char) );
    memset( tmpArray, 0, (textLength+1) * sizeof(char) );

    tmpArray = text[0];

    for (int i = 0; i < ( amountOfStrings - 1 ) ; ++i)
    {
        if ( razmer(tmpArray) < razmer(text[i+1]) )
        {
            tmpArray = text[i+1];
        }
    }

    return tmpArray;
}

int razmer(char n[])    ///THE SIZE OF ARRAY WITHOUT THE LAST ELEMENT ('\0')
{
    int i=0;
    while (n[i]!='\0' && n[i]!='\n'){
        ++i;
    }

    return i ;
}

int AmountOfStrings(char* text, int amountOfBytes)
{
    int ourStrings = 0;
    int i = 0;

    for (int i = 0; i < amountOfBytes; ++i)
    {
        if (text[i] == '\n')
        {
            ++ourStrings;
        }
        else if (text[i] == '\0'){
            ++ourStrings;
            break;
        }
    }

    return ourStrings;
}

int AmountOfComments(char* text, int totalBytes) // calculate amount of comments in bytes.
{
    int commentBytes = 0;
    int tmpBytes = 0; // For storing potential bytes.
    char sCom = '/';
    char nextLine = '\n';
    myBool singleCommentCanBegin = false;
    myBool singleCommentBegin = false;

    myBool multiCommentBegin = false;
    myBool multiCommentCanBegin1 = false;
    myBool multiCommentEnd = false;

    myBool hooksOpen = false; // hooks means ""

    for (int i = 0; i < (totalBytes ); ++i) // That wiil not read '\0' element
    {
        if (hooksOpen == false)
        {
            if (singleCommentBegin == false && multiCommentBegin == false)
            {
                if (text[i] == sCom)
                {
                    if (singleCommentCanBegin == false && multiCommentCanBegin1 == false){
                        singleCommentCanBegin = true;
                        multiCommentCanBegin1 = true;
                    }
                    else if (singleCommentCanBegin == true ){
                        singleCommentBegin = true;
                        multiCommentCanBegin1 = false;
                        singleCommentCanBegin = false;
                    }
                }
                else if (text[i] == '*')
                {
                    if (multiCommentCanBegin1 == true){
                        multiCommentBegin = true;
                        multiCommentCanBegin1 = false;
                        singleCommentCanBegin = false;
                    }
                }
                else{
                    multiCommentCanBegin1 = false;
                    singleCommentCanBegin = false;
                }
            }
            else if (singleCommentBegin == true && multiCommentBegin == false)
            {
                if (text[i] != nextLine && text[i] != '\0' ){
                    ++commentBytes;
                }
                else if (text[i] == nextLine || text[i] == '\0'){
                    ++commentBytes;
                    singleCommentBegin = false;
                }
            }
            else if (multiCommentBegin == true && singleCommentBegin == false)
            {
                if (text[i] == '*' && text[i+1] != sCom){
                    multiCommentEnd = false;
                    ++commentBytes;
                }
                else if (text[i] == '*' && text[i+1] == sCom){
                    multiCommentEnd = true;
                }
                else if (text[i] == '\0'){
                    ++commentBytes;
                    multiCommentEnd = true;
                }
                else{
                    ++commentBytes;
                    multiCommentEnd = false;
                }
            }
            else{
                return -1;
            }
        }
        else if (hooksOpen == true)
        {
            if (text[i] == '"' || text[i] == '\n' || text[i] == '\0'){
                hooksOpen = false;
            }
        }
    }

    return commentBytes;
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
    if (razmer(n)>10){
        return 0;
    }

    if (n[0]=='\0'){
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

    if (n[0]=='\0'){
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

void PrintArray(char** text, size_t amountOfStrings) // Correct this!!!!!!
{
    for (int i = 0; i<amountOfStrings; i++)
    {
            printf("%s", text[i]);
            printf("\n");
    }
}

typedef struct
{
    int *elements;
    int size;
    int capacity;

}DynArray;


