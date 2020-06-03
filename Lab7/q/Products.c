#include "Products.h"


ProductList* CreateProductList() {
    ProductList *tmp = (ProductList*) malloc(sizeof(ProductList));
    tmp->qsize = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void DeleteProductList(ProductList **ourlist) { // deleteProductList(&ourlist);
    Product *tmp = (*ourlist)->head;
    Product *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*ourlist);
    (*ourlist) = NULL;
}

void AddProduct(ProductList *ourlist, ProductInfo *value) { // Add element in the end.
    Product *tmp = (Product*) malloc(sizeof(Product));
    if (tmp == NULL) { // check if there is a memory for it.
        exit(3);
    }

    tmp->info = value;
    tmp->next = NULL;
    tmp->prev = ourlist->tail;

    if (ourlist->tail) { // если он не пустой.
        ourlist->tail->next = tmp;
    }
    ourlist->tail = tmp;

    if (ourlist->head == NULL) { // если пустой.
        ourlist->head = tmp;
    }
    ourlist->qsize++;

}

int InitializeProducts(ProductList *ourList)
{
    int individualNumber = 1;
    FILE *ourFile;
    ourFile = fopen("ProductsData.txt", "r");

    if (!ourFile){
        printf("Error opening file \"ProductsData.txt\"...\n");
        exit(1);
    }

    while (!feof(ourFile)){
        ProductInfo *ourInfo = (ProductInfo*)malloc(sizeof(ProductInfo));
        if (!ourInfo){
            printf("Allocation error.");
            exit(1);
        }

        int section, subsection, indexNumber, available, guarante, cost;
        char *name = (char*)malloc( (MAX_STR_LEN+1) * sizeof(char) );
        char *country = (char*)malloc( (MAX_STR_LEN+1) * sizeof(char) );

        fscanf(ourFile, "%d%d%d%s%d%d%d%s", &section, &subsection, &indexNumber, name, &cost, &available, &guarante, country);
        ourInfo->cost = cost;
        ourInfo->section = section;
        ourInfo->subsection = subsection;
        ourInfo->indexNumber = indexNumber;
        ourInfo->available = available;
        ourInfo->guarante = guarante;
        ourInfo->name = name;
        ourInfo->country = country;
        ourInfo->individualNumber = individualNumber;

        AddProduct(ourList, ourInfo);
        individualNumber = -1;
    }

    fclose(ourFile);
}

void ClearIndNumbers(ProductList *ourList)
{
    Product *current = ourList->head;

    while(current){
        current->info->individualNumber = -1;
        current = current->next;
    }
}

void PrintProduct(Product *ourProduct)
{
    printf(" %s  %d$ (%d) (%d) %s\n", ourProduct->info->name, ourProduct->info->cost, ourProduct->info->available,
                                    ourProduct->info->guarante, ourProduct->info->country);

}

