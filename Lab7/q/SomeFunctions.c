#include "SomeFunctions.h"

int TruePhoneNumber(char *number)
{
    int result = true;
    int amountOfDigits = 0;

    if (razmer(number) != 13) // 12 digits and '+'
    {
        return false;
    }
    if (*number!='+'){
        return false;
    }
    else{
        ++number;
    }
    while (*number != '\n' && *number != '\0')
    {
        if ( myisdigit(*number) == false ){
            return false;
        }
        else{
            ++amountOfDigits;
        }
        ++number;
    }
    if (amountOfDigits != 12){
        return false;
    }

    return result;
}

Buyer *CreateBuyer(int *indNumber)
{
    // int number can't be longer than 10 chars.
    char *name = (char*)malloc( (MAX_STR_LEN+1)*sizeof(char) );
    char *surname = (char*)malloc( (MAX_STR_LEN+1)*sizeof(char) );
    char *patronymic = (char*)malloc( (MAX_STR_LEN+1)*sizeof(char) );
    char *phoneNumber = (char*)malloc( (MAX_STR_LEN+1)*sizeof(char) );

    Buyer *ourBuyer = (Buyer*)malloc(sizeof(Buyer));
    if (!ourBuyer){
        printf("\nERROR. IN CreateByer(). MEMORY NOT FOUND...\n");
        exit(1);
    }

    printf("Input personal info : \n\n");
    printf("first name : ");

    fgets(name, MAX_STR_LEN, stdin);
    while ( (isint(name) == true) || ( HasWord(name) != true ) )
    {
        printf("You enter smth wrong.\n Try again : ");
        fgets(name, MAX_STR_LEN, stdin);
    }
    name[ razmer(name) ] = '\0';

    printf("Surname : ");

    fgets(surname, MAX_STR_LEN, stdin);
    while ( (isint(surname) == true) || ( HasWord(surname) != true ) )
    {
        printf("You enter smth wrong.\n Try again : ");
        fgets(surname, MAX_STR_LEN, stdin);
    }
    surname[ razmer(surname) ] = '\0';

    printf("Patronymic : ");

    fgets(patronymic, MAX_STR_LEN, stdin);
    while ( (isint(patronymic) == true) || ( HasWord(patronymic) != true ) )
    {
        printf("You enter smth wrong.\n Try again : ");
        fgets(patronymic, MAX_STR_LEN, stdin);
    }
    patronymic[ razmer(patronymic) ] = '\0';

    printf("Phone number (example \"+375333452331\"): ");

    fgets(phoneNumber, MAX_STR_LEN, stdin);
    while( TruePhoneNumber(phoneNumber) == false ){
        printf("You enter smth wrong.\n Try again : ");
        fgets(phoneNumber, MAX_STR_LEN, stdin);
    }
    phoneNumber[ razmer(phoneNumber) ] = '\0';

    // set values to our buyer.
    ourBuyer->name = name;
    ourBuyer->surname = surname;
    ourBuyer->patronymic = patronymic;
    ourBuyer->phoneNumber = phoneNumber;
    ourBuyer->indNumber = *indNumber;
    *indNumber++;

    return ourBuyer;
}

int GetChoice(int from, int to) /// get int in range.
{
    int result;
    char *tmp = (char*)malloc( (MAX_STR_LEN+1)*sizeof(char) );

    gets(tmp);
    while ( (isint(tmp) == false) || (isint(tmp)==true && Perevodvint(tmp)<from ) || (isint(tmp)==true && Perevodvint(tmp)>to ) )
    {
        printf("You enter smth wrong.\n Try againt : ");
        gets(tmp);
    }

    result = Perevodvint(tmp);
    free(tmp);
    return result;
}

void PrintAndChoiceMainMenu(int *mainChoice)
{
    printf("Main menu: \n");
    printf("1. Computers\n");
    printf("2. Solid-state drives\n");
    printf("3. Software\n");
    printf("4. Hardware\n");
    printf("5. Find product by\n");
    printf("6. Show your basket\n");
    printf("7. Exit. \n");
    printf("  Input : ");
    *mainChoice = GetChoice(1, 7);
    system("cls");

}

void PrintAndChoiceSubMenu(int mainChoice, int *subMainChoice)
{
    switch (mainChoice)
    {
        case 1:
            {
                printf(" Computers subsection : \n\n");
                printf(" 1. Desktop\n");
                printf(" 2. Notebook\n");
                printf(" 3. back to main menu.\n");
                printf("  Input : ");
                *subMainChoice = GetChoice(1,3);

            }
            break;
        case 2:
            {
                printf(" Solid-state drives subsection : \n\n");
                printf(" 1. SSD\n");
                printf(" 2. HDD\n");
                printf(" 3. back to main menu.\n");
                printf(" Input : ");
                *subMainChoice = GetChoice(1,3);
            }
            break;
        case 3:
            {
                printf(" Software subsection : \n\n");
                printf(" 1. OS\n");
                printf(" 2. Anti-malware\n");
                printf(" 3. Graphics\n");
                printf(" 4. back to main menu.\n");
                printf("  Input : ");
                *subMainChoice = GetChoice(1,4);
            }
            break;
        case 4:
            {
                printf(" Hardware subsection : \n\n");
                printf(" 1. Processors\n");
                printf(" 2. Motherboards\n");
                printf(" 3. Videocards\n");
                printf(" 4. RAM\n"); // оперативка
                printf(" 5. back to main menu.\n");
                printf("  Input : ");
                *subMainChoice = GetChoice(1,5);
            }
            break;
        default:
            {
                printf("EROOR. in PrintAndChoiceSubMenu(). SMTH WRONG IN PARAMETERS.\n");
            }
            break;
    }
    system("cls");
}

/// returns "0" if user wanna back into submain menu.
int PrintAndChoiceProduct(ProductList *ourList,ProductList *ourBasket, int mainChoice, int submainChoice) // Print products and add product.
{
    int individualNumber = 1;
    int result = 0;
    int amountOfProductInSubsection = 0;
    int productChoice = 0;

    Product *current = ourList->head;

    printf("    Products subsection : \n\n");
    printf("    By pattern : (name, cost, available, guarante, country) \n");
    while (current){
        if (current->info->section == mainChoice){
            if (current->info->subsection == submainChoice){
                printf("    %d. %s  %d$ (%d) (%d)  %s\n", current->info->indexNumber, current->info->name, current->info->cost,
                                                        current->info->available, current->info->guarante, current->info->country );
                ++amountOfProductInSubsection;
            }
        }
        current = current->next;
    }
    printf("    %d. back into submain menu. \n", (amountOfProductInSubsection+1) );

    printf("     Input : ");
    productChoice = GetChoice(1, amountOfProductInSubsection+1);

    current = ourList->head;
    if (productChoice <= amountOfProductInSubsection){
        // Добавить продукт в карзину.
        while (current){
            if (current->info->section == mainChoice){
                if (current->info->subsection == submainChoice){
                    if (current->info->indexNumber == productChoice){
                        AddProduct(ourBasket, current->info);
                    }
                }
            }
            current = current->next;
        }
    }
    else if (productChoice == (amountOfProductInSubsection+1)){
        result = 0;
    }
    else {
        printf("Some unknow error...\n");
        exit(1);
    }
    system("cls");

    ClearIndNumbers(ourList);
    return result;
}

void PrintAndFindProductsBy(ProductList *ourList, ProductList *ourBasket, int *gotoflag)
{
    int individualNumber = 1;
    int ourChoice = 0;
    int cost = -1;
    char *name = 0;
    char *country = 0;
    int costflag = false;
    int nameflag = false;
    int countryflag = false;
    Product *current = ourList->head;

    printf("\tFind product by : \n\n");
    printf("\t1. name\n");
    printf("\t2. cost\n");
    printf("\t3. country\n");
    printf("\t Input : ");
    ourChoice = GetChoice(1, 3);

    switch(ourChoice)
    {
    case 1:
        {
            name = (char*)malloc((MAX_STR_LEN+1) * sizeof(char));
            CheckCharMalloc(name);
            printf("\t print name : ");
            fgets(name, MAX_STR_LEN, stdin);
            while ( (isint(name) == true) || ( HasWord(name) != true ) )
            {
                printf("You enter smth wrong.\n Try again : ");
                fgets(name, MAX_STR_LEN, stdin);
            }
            name[ razmer(name) ] = '\0';
            nameflag = true;
        }
        break;
    case 2:
        {
            printf("\t print cost : ");
            cost = GetChoice(0, 1000000000); // Max cost.
            costflag = true;
        }
        break;
    case 3:
        {
            country = (char*)malloc((MAX_STR_LEN+1) * sizeof(char));
            CheckCharMalloc(country);
            printf("\t print country : ");
            fgets(country, MAX_STR_LEN, stdin);
            while ( (isint(country) == true) || ( HasWord(country) != true ) )
            {
                printf("You enter smth wrong.\n Try again : ");
                fgets(country, MAX_STR_LEN, stdin);
            }
            country[ razmer(country) ] = '\0';
            countryflag = true;
        }
        break;
    }

    printf("Products : (name, cost, available, guarante, country)\n");

    // Printing obj.
    while (current){
        if (nameflag == true){
            if (strcmp(name, current->info->name) == 0){ // если равны.
                printf("\t%d. ", individualNumber);
                PrintProduct(current);
                current->info->individualNumber = individualNumber;
                ++individualNumber;
            }
        }
        if (costflag == true){
            if (current->info->cost == cost){
                printf("\t%d. ", individualNumber);
                PrintProduct(current);
                current->info->individualNumber = individualNumber;
                ++individualNumber;
            }
        }
        if (countryflag == true){
            if (strcmp(country, current->info->country) == 0){
                printf("\t%d. ", individualNumber);
                PrintProduct(current);
                current->info->individualNumber = individualNumber;
                ++individualNumber;
            }
        }
        current = current->next;
    }

    printf("\t%d. to main menu.\n", (individualNumber+1) );
    printf("\t Input : ");
    ourChoice = GetChoice(1, individualNumber +1);

    current = ourList->head;
    while(current){
        if (current->info->individualNumber == ourChoice){
            // Добавить в карзину.
            AddProduct(ourBasket, current->info);
            break;
        }
        current = current->next;
    }
    if (ourChoice == individualNumber+1) *gotoflag = 0;

    ClearIndNumbers(ourList);
}

void ShowBasket(ProductList *ourBasket, Buyer *ourBuyer, int *backFlag)
{
    int Choice = 0;
    int itmp = 1;
    int totalCost = 0;
    int totalFileCost = 0;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    Product *current = ourBasket->head;

    printf("Your basket : \n\n");
    while (current){

        printf("\t%d. ", itmp);
        PrintProduct(current);

        totalCost += current->info->cost;
        current = current->next;
        ++itmp;
    }
    if (itmp == 1) {
        printf("\nThere is no products!\n");
        return;
    }
    current = ourBasket->head;

    printf("\t Total Cost : %d ($)\n\n", totalCost);
    printf("\t1. Buy this\n");
    printf("\t2. To main menu.\n");
    printf("\t Input : ");
    Choice = GetChoice(1, 2);

    switch (Choice)
    {
    case 1:
        {
            // добавить в список покупателей.
            FILE *ourBuyerFile;
            FILE *ourProductHistoryFile;
            FILE *ourTotalCostFile;
            ourBuyerFile = fopen("BuyersData.txt", "a");
            ourProductHistoryFile = fopen("ProductHistoryData.txt", "a");
            ourTotalCostFile = fopen("TotalBuy.txt", "r");
            if (!ourBuyerFile || !ourProductHistoryFile || !ourTotalCostFile){
                printf("Erpro\n");
                exit(1);
            }

            if (feof(ourTotalCostFile)){

            }
            else{
                fscanf( ourTotalCostFile, "%d", &totalFileCost);
            }
            totalFileCost += totalCost;
            fclose(ourTotalCostFile);
            ourTotalCostFile = fopen("TotalBuy.txt", "w");

            fprintf(ourBuyerFile, "%s  %s  %s   %s\n", ourBuyer->name, ourBuyer->surname, ourBuyer->patronymic, ourBuyer->phoneNumber);
            fprintf(ourProductHistoryFile, asctime(tm));
            fprintf(ourProductHistoryFile, " : \n");
            while (current){
                fprintf( ourBuyerFile, "    %s  %d$ (%d) (%d) %s\n", current->info->name, current->info->cost, current->info->available,
                                    current->info->guarante, current->info->country);
                fprintf( ourProductHistoryFile, "    %s  %d$ (%d) (%d) %s\n", current->info->name, current->info->cost, current->info->available,
                                    current->info->guarante, current->info->country);
                current = current->next;
            }
            fprintf(ourTotalCostFile, "%d ($)", totalFileCost);

            fclose(ourBuyerFile);
            fclose(ourProductHistoryFile);
            fclose(ourTotalCostFile);
            exit(0);
        }
        break;
    case 2:
        {
            *backFlag = true;
        }
        break;
    }
    system("cls");
}

void PrintBuyer(Buyer *ourBuyer)
{
    printf("  %s  %s  %s   %s\n", ourBuyer->name, ourBuyer->surname, ourBuyer->patronymic, ourBuyer->phoneNumber);
}

