#include "baralho.h"
#include "opcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void iniciaMenu() {
    int opcao;
    printf("INICIAR JOGO [1]\nCARREGAR JOGO [2]\nCREDITOS [3]\nSAIR DO JOGO [4]\n");
    scanf("%i", &opcao);

    if (opcao == 1) {
        novoJogo();
    }
    else if (opcao == 4) {
        sair();
    }
    else iniciaMenu();
}

void novoJogo() {
    cria_baralho();
}

void carregarJogo() {

}

void creditos() {
    printf("TODOS OS DIREITOS RESERVADOS\nGABRIEL\nGUSTAVO\nMURILO");
}

void sair() {
    abort();
}