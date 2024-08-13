#ifndef OPCOES_H_INCLUDED
#define OPCOES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Funcao que inicia o menu de opções do jogo
int iniciaMenu();

void novoJogo();

void carregarJogo();

void creditos();

void sair();

void salvarJogo(FilaEnc *colunas_cima[7], PilhaEnc *colunas_baixo[7], PilhaEnc *pilha_copas, PilhaEnc *pilha_ouros, PilhaEnc *pilha_paus, PilhaEnc *pilha_espadas, ListaCircEnc *baralho);




#endif