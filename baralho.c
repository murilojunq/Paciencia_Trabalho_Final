
#include "baralho.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "baralho.h"

#define QUANTIDADE_DE_CARTAS 52
#define TAMANHO_DO_VETOR 51

// Fun��o que cria uma lista
ListaCircEnc* criaListaCircEnc()
{
    ListaCircEnc *lista = (ListaCircEnc*)malloc(sizeof(ListaCircEnc));
    if (lista != NULL)
    {
        lista->prim = NULL;
    }
    return lista;
}

// Fun��o que destr�i uma lista
void destroiListaCircEnc(ListaCircEnc *lista)
{
    if (lista->prim != NULL)
    {
        NodoLEnc *atual = lista->prim;
        do
        {
            NodoLEnc *prox = atual->prox;
            free(atual);
            atual = prox;
        }
        while (atual != lista->prim);
    }
    free(lista);
}

// Fun��o que imprime todos os n�s de uma lista
void imprimeListaCircEnc(ListaCircEnc *lista)
{
    if (lista->prim != NULL)
    {
        NodoLEnc *atual = lista->prim;
        do
        {
            printf("Chave: %d, Valor: %d, Naipe: %s\n", atual->info.chave, atual->info.valor, atual->info.naipe);
            atual = atual->prox;
        }
        while (atual != lista->prim);
    }
    else
    {
        printf("Lista vazia.\n");
    }
}

// Fun��o que insere um n� no in�cio de uma lista
int insereInicioListaCircEnc(ListaCircEnc *lista, Info info)
{
    NodoLEnc *novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
    if (novo == NULL) return 0;
    novo->info = info;

    if (lista->prim == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        lista->prim = novo;
    }
    else
    {
        NodoLEnc *ultimo = lista->prim->ant;
        novo->prox = lista->prim;
        novo->ant = ultimo;
        lista->prim->ant = novo;
        ultimo->prox = novo;
        lista->prim = novo;
    }
    return 1;
}

int insereFimListaCircEnc(ListaCircEnc *lista, Info info) {
    NodoLEnc *novoNodo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
    if (!novoNodo) {
        return 0;
    }

    novoNodo->info = info;

    if (lista->prim == NULL) {
        lista->prim = novoNodo;
        novoNodo->prox = novoNodo;
        novoNodo->ant = novoNodo;
    } else {
        NodoLEnc *ultimo = lista->prim->ant;
        novoNodo->prox = lista->prim;
        novoNodo->ant = ultimo;
        ultimo->prox = novoNodo;
        lista->prim->ant = novoNodo;
    }

    return 1;
}

// Fun��o que resgata um n� com uma informa��o de uma lista
NodoLEnc* buscaInfoListaCircEnc(ListaCircEnc* lista, int chave)
{
    if (lista->prim != NULL)
    {
        NodoLEnc *atual = lista->prim;
        do
        {
            if (atual->info.chave == chave) return atual;
            atual = atual->prox;
        }
        while (atual != lista->prim);
    }
    return NULL;
}

ListaCircEnc* cria_baralho(){
    ListaCircEnc *baralho = criaListaCircEnc();
    NodoLEnc *carta;
    int i, valor_da_carta = 1, quant_cartas_mesmo_valor = 1;

    baralho->prim = carta;

    for(i = 0; i < QUANTIDADE_DE_CARTAS; i++){ //preenchendo as infos das cartas
        carta->info.chave = i+1;
        carta->info.valor = valor_da_carta;
        carta->info.sentido = 0;

        if(quant_cartas_mesmo_valor == 1){
            strcpy(carta->info.naipe, "paus");
        }
        else if(quant_cartas_mesmo_valor == 2){
            strcpy(carta->info.naipe, "ouros");
        }
        else if(quant_cartas_mesmo_valor == 3){
            strcpy(carta->info.naipe, "copas");
        }
        else if(quant_cartas_mesmo_valor == 4){
            strcpy(carta->info.naipe, "espadas");
            valor_da_carta++;
            quant_cartas_mesmo_valor = 1;  //reinicia a contagem apos 4 naipes;
        }
        quant_cartas_mesmo_valor++;
        insereFimListaCircEnc(baralho, carta->info);
        free(carta);

    }

    return baralho;

}

ListaCircEnc* embaralha_baralho()
{

    int cartas[TAMANHO_DO_VETOR];
    int cartas_embaralhadas[TAMANHO_DO_VETOR];
    int i, j, aux, menor_valor = 1;

    srand(time(NULL));

    //preenchendo o vetor de 1 a 52
    for(i = 0; i <= QUANTIDADE_DE_CARTAS; i++)
    {
        cartas[i] = i + 1;
    }
    //algoritimo de Fisher-Yates para embaralhar os valores no vetor
    for(i = TAMANHO_DO_VETOR; i >= 0 ; i--)
    {
        j = rand() % (i + 1);
        aux = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = aux;
    }

    //passando os valores embaralhados para o novo vetor
    for(i = 0; i <= TAMANHO_DO_VETOR; i++)
    {
        cartas_embaralhadas[i] = cartas[i];
    }


    for(i = 0; i <= TAMANHO_DO_VETOR; i++){

    }
}



