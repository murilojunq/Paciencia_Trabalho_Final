
#include "baralho.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>



#define QUANTIDADE_DE_CARTAS 52
#define TAMANHO_DO_VETOR 51


// Funcao que cria uma fila
FilaEnc* criaFilaEnc(){
   FilaEnc *fila = (FilaEnc*)malloc(sizeof(FilaEnc));
   if (fila != NULL){ // Idealmente, sempre checar!
      fila->ini = NULL;
      fila->fim = NULL;
   }
   return fila;
}

// Funcao que destroi uma fila
void destroiFilaEnc(FilaEnc *fila){
   NodoFEnc *aux = fila->ini;
   while(aux != NULL){
       NodoFEnc *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(fila);
}

// Funcao que insere um elemento na fila
void enfileiraFilaEnc(FilaEnc *fila, Info info){
   NodoFEnc *novo = (NodoFEnc*)malloc(sizeof(NodoFEnc));
   if (fila != NULL){
      novo->info = info;
      novo->prox = NULL;
      if (fila->fim != NULL)
         fila->fim->prox = novo;
      else
         fila->ini = novo;
      fila->fim = novo;
   }
}


// Funcao que remove um elemento da fila
Info desenfileiraFilaEnc(FilaEnc *fila){
   NodoFEnc *aux = fila->ini; 
   Info info = aux->info;
   fila->ini = aux->prox;
   if (fila->ini == NULL)
      fila->fim = NULL;
   free(aux);
   return info;
}

// Funcao que determina se uma fila eh vazia
int vaziaFilaEnc(FilaEnc *fila){
   return (fila->ini == NULL);
}

// Funcao que cria uma pilha
PilhaEnc* criaPilhaEnc(){
   PilhaEnc *pilha = (PilhaEnc*)malloc(sizeof(PilhaEnc));
   if (pilha != NULL) // Idealmente, sempre checar!
      pilha->topo = NULL;
   return pilha;
}

// Funcao que destroi uma pilha
void destroiPilhaEnc(PilhaEnc *pilha){
   NodoPEnc *aux = pilha->topo;
   while(aux != NULL){
       NodoPEnc *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(pilha);
}

// Funcao que insere um elemento na pilha
void empilhaPilhaEnc(PilhaEnc *pilha, Info info){
   NodoPEnc *novo = (NodoPEnc*)malloc(sizeof(NodoPEnc));
   if (novo != NULL){ // Idealmente, sempre checar!
      novo->info = info;
      novo->prox = pilha->topo;
      pilha->topo = novo;
   }
}



// Funcao que remove um elemento da pilha
Info desempilhaPilhaEnc(PilhaEnc* pilha){
   NodoPEnc *aux = pilha->topo; 
   /* Aqui assumimos que desempilha eh 
   chamada apenas se a pilha nao eh vazia */
   Info info = aux->info;
   pilha->topo = aux->prox;
   free(aux);
   return info;
}

// Funcao que determina se uma pilha eh vazia
int vaziaPilhaEnc(PilhaEnc *pilha){
   return (pilha->topo == NULL);
}

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
    FILE *txtcartas;
    txtcartas = fopen("cartas.txt", "r");

    Carta carta;
    ListaCircEnc *baralho;
    baralho = criaListaCircEnc();
    for (int i=0; i<52; i++) {
        fscanf(txtcartas, " %d %s %d %s", &carta.valor, carta.naipe, &carta.chave, carta.imagemtxt);
        insereInicioListaCircEnc(baralho, carta);
    }

    return baralho;

}

ListaCircEnc* embaralha_baralho(ListaCircEnc* baralho)
{

    int cartas[TAMANHO_DO_VETOR];
    int cartas_embaralhadas[TAMANHO_DO_VETOR];
    int i, j, aux, menor_valor = 1;
    ListaCircEnc *baralho_embaralhado = criaListaCircEnc();
    NodoLEnc *nodoAux;

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
    for (int k=0;k<TAMANHO_DO_VETOR; k++) {
        nodoAux = buscaInfoListaCircEnc(baralho, cartas[k]);
        insereInicioListaCircEnc(baralho_embaralhado, nodoAux->info);
    }

    return baralho_embaralhado;
}



