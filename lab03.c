#include <stdio.h>
#include <stdlib.h>

typedef struct monomial{
    int coeficient, exponent;
    struct monomial *next;
} monomial;

monomial *createMonomial(int coeficient, int exponent) {
    monomial *newMonomial = (monomial *)malloc(sizeof(monomial));
    if (newMonomial == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newMonomial->coeficient = coeficient;
    newMonomial->exponent = exponent;
    newMonomial->next = NULL;
    return newMonomial;
}

monomial *insertMonomial(monomial *L, int coeficient, int exponent){
    monomial *new = createMonomial(coeficient, exponent);
    monomial *aux = L, *pred = NULL;
    if (L == NULL) L = new;
    else{
        while (aux != NULL && exponent < aux->exponent)
        {
            pred = aux;
            aux = aux->next;
        }
        if (pred == NULL){
            new->next = aux;
            L = new;
        }
        else{
            new->next = aux;
            pred->next = new;
        }
    }
    return L;
}

monomial *insetInvertMonomial(monomial *L, int coeficient, int exponent){
    monomial *new = createMonomial(coeficient, exponent);
    monomial *aux = L, *pred = NULL;
    if (L == NULL) L = new;
    else{
        while (aux != NULL && exponent > aux->exponent)
        {
            pred = aux;
            aux = aux->next;
        }
        if (pred == NULL){
            new->next = aux;
            L = new;
        }
        else{
            new->next = aux;
            pred->next = new;
        }
    }
    return L;
}

void imprimeLista(monomial *L){
    monomial *aux = L;
    if(L == NULL) printf("Erro: Lista Vazia\n");
    else{
        while (aux != NULL)
        {
            if(aux->coeficient > 0){
                printf("+%dx^%d ", aux->coeficient, aux->exponent);
                aux = aux->next;
            }
            else{
                printf("%dx^%d ", aux->coeficient, aux->exponent);
                aux = aux->next;
            }
        }
        printf("\n");
    }
}

monomial *somaPoli(monomial *result, monomial *poli1, monomial *poli2){
    monomial *aux1 = poli1, *aux2 = poli2;aux1 = aux1->next;
            aux2 = aux2->next;
    while (aux1 != NULL && aux2 != NULL)
    {
        if(aux1->exponent == aux2->exponent){
            result = insertMonomial(result, aux1->coeficient + aux2->coeficient, aux1->exponent);
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
        if(aux1->exponent < aux2->exponent){
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
        else if(aux1->exponent > aux2->exponent){
            result = insertMonomial(result, aux2->coeficient, aux2->exponent);
            aux2 = aux2->next;
        }
    }
    
}

monomial *invertPoli(monomial *poli){
    monomial *result = NULL, *aux = poli;
    while (aux != NULL)
    {
        result = insetInvertMonomial(result, aux->coeficient, aux->exponent);
        aux = aux->next;
    }
    return result;
    
}
void freeMonomial(monomial *L){
    monomial *aux;
    while (L != NULL)
    {
        aux = L;
        L = L->next;
        free(aux);
    }
}

int main(){
    monomial *polinomial1 = NULL, *polinomial2 = NULL, *polinomial3 = NULL;
    int coeficient, exp;
    for(int i = 0; i < 3; i++){
        printf("coeficient: ");
        scanf("%d", &coeficient);
        printf("Expoente: ");
        scanf("%d", &exp);

        polinomial1 = insertMonomial(polinomial1, coeficient, exp);
    }

    
    polinomial2 = invertPoli(polinomial1);
    polinomial3 = somaPoli(polinomial3, polinomial1, polinomial2);

    imprimeLista(polinomial1);
    imprimeLista(polinomial2);
    imprimeLista(polinomial3);

    freeMonomial(polinomial1);
    freeMonomial(polinomial2);
    freeMonomial(polinomial3);
    return 0;
}