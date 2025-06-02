#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;
}no;

no *criaNo(int valor){
    no *novo = (no*)malloc(sizeof(no));
    if(novo == NULL){
        printf("ERRO: falha na alocacao de memoria");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;

    return novo;
}

no *insereNoInicio(no *L, int valor){
    no *novo = criaNo(valor);
    novo->prox = L;
    L = novo;
    return L;
}

no *insereNoFim(no *L, int valor){
    no *novo = criaNo(valor);
    no *aux = L;
    if (L == NULL) L = novo;
    else{
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }
    return L;
}

void imprimeLista(no *L){
    no *aux = L;
    if(L == NULL) printf("Erro: Lista Vazia\n");
    else{
        while (aux != NULL)
        {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void imprimeListaRec(no *L){
    if(L == NULL) return;
    printf("%d ", L->dado);
    imprimeListaRec(L->prox);
}

no *inverterLista(no *L1){
    no *L2;
    L2 = inserenoInicio(L1);

}

int numNos(no* L, int valor){
    no *aux = L;
    int cont = 1;

    if(L == NULL){
        printf("Erro: Lista Vazia\n");
        return -1;
    }

    while (aux != NULL && aux->dado != valor){
        cont++;
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("Valor %d não encontrado na lista.\n", valor);
        return -1; // ou outro valor para indicar ausência
    }

    return cont;
}



int main(){
    no* L = NULL;
    int valor, busca, valBusca;
    printf("Digite um valor: ");
    scanf("%d", &valor);

    for(int i = 1; i <= valor; i++){
        L = insereNoFim(L,i);
    }     

    imprimeLista(L);
    imprimeListaRec(L);
    printf("\n");
    printf("digite um valor para busca: ");
    scanf("%d", &busca);
    valBusca = numNos(L, busca);
    printf("%d\n", valBusca);

    no *aux;
    while (L != NULL)
    {
        aux = L;
        L = L->prox;
        free(aux);
    }
    
    return 0;
}
