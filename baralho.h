#ifndef BARALHO_H_INCLUDED
#define BARALHO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NOME_NAIPE 10

typedef struct{
    int chave;
    int valor;
    char naipe[NOME_NAIPE];
    char imagem[22];
    int sentido; //de costas (0) ou de frente (1);
}Carta;

typedef Carta Info;

typedef struct nodoLEnc{
    Info info;
    struct nodoLEnc *prox;
    struct nodoLEnc *ant;
}NodoLEnc;

typedef struct{
    struct nodoLEnc *prim;
}ListaCircEnc;

// Funcao que cria uma lista
ListaCircEnc* criaListaCircEnc();

// Funcao que destroi uma lista
void destroiListaCircEnc(ListaCircEnc *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaCircEnc(ListaCircEnc *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaCircEnc(ListaCircEnc *lista, Info info);

// Fun��o que insere um nodo no fim de uma lista
int insereFimListaCircEnc(ListaCircEnc *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc* buscaInfoListaCircEnc(ListaCircEnc* lista, int chave);

ListaCircEnc cria_baralho();

ListaCircEnc embaralha_baralho();




#endif // BARALHO_H_INCLUDED
