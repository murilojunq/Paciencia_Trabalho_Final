
#include "baralho.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include "cartas.h"



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
            printf("Chave: %d, Valor: %d, Naipe: %d\n", atual->info.chave, atual->info.valor, atual->info.naipe);
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

int removeInfoListaCircEnc(ListaCircEnc *lista, int chave) {
    if (lista->prim != NULL) {
        NodoLEnc *aux = lista->prim;

        //caso nodo seja o primeiro da lista
        if (lista->prim->info.chave == chave) {
            NodoLEnc *primeiro = lista->prim;
            primeiro->prox->ant = primeiro->ant;
            primeiro->ant->prox = primeiro->prox;
            lista->prim = lista->prim->prox; 
            free(primeiro);
        }
        else {
            NodoLEnc *aux = lista->prim;
            while(aux->info.chave != chave) {
                aux = aux->prox;
            }
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
            free(aux);
        }
    }
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
        fscanf(txtcartas, " %d %d %d %s", &carta.valor, &carta.naipe, &carta.chave, carta.imagemtxt);
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
    for(i = 0; i < QUANTIDADE_DE_CARTAS; i++)
    {
        cartas[i] = i + 1;
    }
    //algoritimo de Fisher-Yates para embaralhar os valores no vetor
    for(i = QUANTIDADE_DE_CARTAS - 1; i > 0 ; i--)
    {
        j = rand() % (i + 1);
        aux = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = aux;
    }

    //passando os valores embaralhados para o novo vetor
    for (int k=0;k<QUANTIDADE_DE_CARTAS; k++) {
        nodoAux = buscaInfoListaCircEnc(baralho, cartas[k]);
        insereInicioListaCircEnc(baralho_embaralhado, nodoAux->info);
    }

    return baralho_embaralhado;
}


int insereFilaViradoCima(FilaEnc *fila, Info info, ListaCircEnc *baralhoOrigem, PilhaEnc *pilhaOrigem, FilaEnc *filaOrigem){
    //Os parâmetros <tipo>Origem representão o lugar de onde a carta a ser adiocionada veio
    //Obviamente só um poderá ser escolhido, para os outros deve ser passado NULL;
    
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

   novo->info.sentido = 1;

   if (baralhoOrigem) removeInfoListaCircEnc(baralhoOrigem, info.chave);

   //ATENCAO: falta implementar para pilhaOrigem != NULL e filaOrigem != NULL
}

int inserePilhaViradoBaixo(PilhaEnc *pilha, Info info, ListaCircEnc *baralhoOrigem) {
    NodoPEnc *novo = (NodoPEnc*)malloc(sizeof(NodoPEnc));
   if (novo != NULL){ // Idealmente, sempre checar!
      novo->info = info;
      if (pilha->topo) {
        pilha->topo->ant = novo;
      }
      novo->ant = NULL;
      novo->prox = pilha->topo;
      pilha->topo = novo;
   }
    novo->info.sentido = 0;

   if (baralhoOrigem) removeInfoListaCircEnc(baralhoOrigem, info.chave);

}

int desenhaCartasColuna(FilaEnc *fila, PilhaEnc *pilha, int coluna, int sentido, float multi_res, int numBaixo) {
    /* Essa funcao desenha as cartas das colunas superiores
    Quando for usada para desenhar as cartas de cabeça para baixo (pilhas), o argumento fila deve receber NULL, e vice-versa;
    O argumento coluna é referente à qual coluna estas cartas pertencem;
    O argumento sentido é referente ao sentido da carta (virado para cima ou para baixo);
    O argumento numBaixo, é o número de cartas daquela coluna que estão de cabeça para baixo (é importante apenas quando
esta funcao for usada para plotar as cartas viradas para cima, caso contrario deve receber 0)
    */ 
    NodoLEnc *carta;
    int i = 0;
    float largura = 50*multi_res;
    float altura = 70*multi_res;
    if (sentido == 0 && pilha->topo != NULL) {
        i = 0;
        carta = pilha->topo;
        while(carta->prox != NULL) {
            carta = carta->prox;
        }
        while(carta != NULL) {
            Image cartaImagem = LoadImage("cartas/card_back_red.png");
            float posX = (100 + (coluna-1)*65)*multi_res;
            float posY = 10+ i*20*multi_res;
            ImageResize(&cartaImagem, largura, altura);
            carta->info.imagem = LoadTextureFromImage(cartaImagem);
            UnloadImage(cartaImagem);

            DrawTexture(carta->info.imagem,(100 + (coluna-1)*65)*multi_res, (10+ i*20*multi_res), WHITE);


            carta->info.hitBox = (Rectangle){posX, posY, largura, altura};
            carta = carta->ant;
            i++;
        }
        return i;
    }
    else if (sentido == 1 && fila->ini != NULL) {
        carta = fila->ini;
        i=0;
        while(carta != NULL) {
            float posX = (100 + (coluna-1)*65)*multi_res;
            float posY = (10+ (numBaixo+i)*20*multi_res);
            Image cartaImagem = LoadImage(carta->info.imagemtxt);
            ImageResize(&cartaImagem, 50*multi_res, 70*multi_res);
            carta->info.imagem = LoadTextureFromImage(cartaImagem);
            UnloadImage(cartaImagem);

            DrawTexture(carta->info.imagem,(100 + (coluna-1)*65)*multi_res, (10+ (numBaixo+i)*20*multi_res), WHITE);

            carta->info.hitBox = (Rectangle){posX, posY, largura, altura};
            carta = carta->prox;
            i++;
        }
        return 0;
    }
    return 0;
}

int verificaPossibilidadeMudanca(int valor, int naipe, FilaEnc *colunaDestino, FilaEnc *colunas_cima[7]) {
    //naipes:
    // 1 -> Copas; 2 -> Ouros; 3 -> Paus; 4 -> Espadas;

    NodoLEnc *cartaBaixo = colunaDestino->fim;
    FilaEnc *filaAux;
    NodoLEnc *cartaAux;

    //verifica se uma das colunas_cima contém a carta
    for (int i=0;i<=6;i++) {
        filaAux = colunas_cima[i];
        cartaAux = filaAux->ini;
        while (cartaAux != NULL) {
            if (cartaAux->info.valor == valor && cartaAux->info.naipe == naipe) {
                if (cartaBaixo->info.valor == (valor + 1)) {
                    if (cartaBaixo->info.naipe <= 2 && naipe > 2) {
                        return i;
                    }
                    else if (cartaBaixo->info.naipe > 2 && naipe <= 2) {
                        return i;
                    }
                }

            }
        cartaAux = cartaAux->prox;
        }
    }
    return 3;
}

void mudaCartaColuna(FilaEnc *colunaOrigem, FilaEnc *colunaDestino, int valor, int naipe) {
    FilaEnc *filaAux = criaFilaEnc();
    NodoFEnc *cartaAux;
    Info cartaRemov;

    cartaAux = colunaOrigem->ini;
    while(cartaAux->info.valor != valor && cartaAux->info.naipe != naipe) {
        cartaRemov = desenfileiraFilaEnc(colunaOrigem);
        enfileiraFilaEnc(filaAux,cartaRemov);

        cartaAux = cartaAux->prox;
    }

    while (cartaAux != NULL) {
        cartaRemov = desenfileiraFilaEnc(colunaOrigem);
        enfileiraFilaEnc(colunaDestino, cartaRemov);

        cartaAux = cartaAux->prox;
    }

    cartaAux = filaAux->ini;
    while (cartaAux != NULL) {
        cartaRemov = desenfileiraFilaEnc(filaAux);
        enfileiraFilaEnc(colunaOrigem, cartaRemov);
        cartaAux = cartaAux->prox;
    }

    destroiFilaEnc(filaAux);
}

void desviraCarta(FilaEnc *coluna_cima, PilhaEnc *coluna_baixo) {
    Info cartaRemov;

    cartaRemov = desempilhaPilhaEnc(coluna_baixo);
    enfileiraFilaEnc(coluna_cima, cartaRemov);
}