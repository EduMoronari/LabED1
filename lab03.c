#include <stdio.h>
#include <stdlib.h>

typedef struct monomial{
    int base, exponent;
    struct monomial *next;
} monomial;

monomial *createMonomial(int base, int exponent) {
    monomial *newMonomial = (monomial *)malloc(sizeof(monomial));
    if (newMonomial == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newMonomial->base = base;
    newMonomial->exponent = exponent;
    newMonomial->next = NULL;
    return newMonomial;
}

monomial *insertMonomial(monomial *L, int base, int exponent){
    monomial *new = createMonomial(base, exponent);
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

void imprimeLista(monomial *L){
    monomial *aux = L;
    if(L == NULL) printf("Erro: Lista Vazia\n");
    else{
        while (aux != NULL)
        {
            if(aux->base > 0){
                printf("+%dx^%d ", aux->base, aux->exponent);
                aux = aux->next;
            }
            else{
                printf("%dx^%d ", aux->base, aux->exponent);
                aux = aux->next;
            }
        }
        printf("\n");
    }
}

monomial *somaPoli(monomial *result, monomial *poli1, monomial *poli2){
    monomial *aux1 = poli1, *aux2 = poli2
    while (aux1->exp != aux2->exp)
    {
        aux2
    }
    
}

int main(){
    monomial *polinomial = NULL;
    int base, exp;
    for(int i = 0; i < 3; i++){
        printf("Base: ");
        scanf("%d", &base);
        printf("Expoente: ");
        scanf("%d", &exp);

        polinomial = insertMonomial(polinomial, base, exp);
    }
    imprimeLista(polinomial);
    return 0;
}