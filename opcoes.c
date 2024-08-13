#include "baralho.h"
#include "opcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"

int iniciaMenu() {
    int opcao;
    printf("INICIAR JOGO [1]\nCARREGAR JOGO [2]\nCREDITOS [3]\nSAIR DO JOGO [4]\n");
    scanf("%i", &opcao);
 
    if (opcao == 1) {
        return 1;
    }
    else if (opcao == 4) {
        return 4;
    }
    else iniciaMenu();
}

void novoJogo() {
    int opcao_res = 1, multi_res = 1;
    printf("Qual sua resolução de preferência?\n");
    printf("[1]640x400 [2]960x600 [3]1280x800 [4]1600x1000\n");
    scanf("%d", &opcao_res);

    switch(opcao_res) {
        case 1:
            printf("Resolução 640x400\n");
            multi_res = 1;
            break;
        case 2:
            printf("Resolução 960x600\n");
            multi_res = 1.5;
            break;
        case 3:
            printf("Resolução 1280x800\n");
            multi_res = 2;
            break;
        case 4:
            printf("Resolução 1600x1000\n");
            multi_res = 2.5;
            break;
        default:
            printf("Opção inválida!\n");
            novoJogo();
    }


    ListaCircEnc *baralho = cria_baralho();
    ListaCircEnc *baralho_embaralhado = embaralha_baralho(baralho);
    
    const int screenWidth = (640*multi_res);
    const int screenHeight = (400*multi_res);
    InitWindow(screenWidth, screenHeight, "Jogo Paciencia");

    //pilhas superiores (onde os naipes devem ser organizados)
    PilhaEnc *pilha_copas = criaPilhaEnc();
    PilhaEnc *pilha_ouro = criaPilhaEnc();
    PilhaEnc *pilha_paus = criaPilhaEnc();
    PilhaEnc *pilha_espadas = criaPilhaEnc();

    //colunas
    FilaEnc *colunas_cima[7];
    PilhaEnc *colunas_baixo[7];
    for (int i=0; i <= 6; i++) {
        colunas_cima[i] = criaFilaEnc();
        colunas_baixo[i] = criaPilhaEnc();
    }

    //monte de compras
    ListaCircEnc *baralho_compras = criaListaCircEnc();
    NodoLEnc *carta = baralho_embaralhado->prim;
    //inserindo cartas em cada coluna

   for (int i =0; i<28; i++) {
        if (i == 0){
            insereFilaViradoCima(colunas_cima[0], carta->info, baralho_embaralhado, NULL, NULL);
        }
        else if (i == 1) {
            inserePilhaViradoBaixo(colunas_baixo[1], carta->info, baralho_embaralhado);
        }
        else if (i == 2) {
            insereFilaViradoCima(colunas_cima[1], carta->info, baralho_embaralhado, NULL, NULL);
        }
        else if (i <= 4) {
            inserePilhaViradoBaixo(colunas_baixo[2], carta->info, baralho_embaralhado);
        }
        else if (i == 5) {
            insereFilaViradoCima(colunas_cima[2], carta->info, baralho_embaralhado, NULL, NULL);
        }
        else if (i <= 8) {
            inserePilhaViradoBaixo(colunas_baixo[3], carta->info, baralho_embaralhado);
        }
        else if (i == 9) {
            insereFilaViradoCima(colunas_cima[3], carta->info, baralho_embaralhado, NULL, NULL);
        }
        else if (i <= 13) {
            inserePilhaViradoBaixo(colunas_baixo[4], carta->info, baralho_embaralhado);
        }
        else if (i == 14) {
            insereFilaViradoCima(colunas_cima[4], carta->info, baralho_embaralhado, NULL, NULL);
        }
        else if (i <= 19) {
            inserePilhaViradoBaixo(colunas_baixo[5], carta->info, baralho_embaralhado);
        }
        else if (i == 20) {
            insereFilaViradoCima(colunas_cima[5], carta->info, baralho_embaralhado, NULL, NULL);
        }
        else if (i <= 26) {
            inserePilhaViradoBaixo(colunas_baixo[6], carta->info, baralho_embaralhado);
        }
        else insereFilaViradoCima(colunas_cima[6], carta->info, baralho_embaralhado, NULL, NULL);

        carta = carta->prox;
    }

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GREEN);

        //desenhando cartas na tela

        int numBaixo = 0; // numero de cartas virada para baixo em cada coluna

        for (int i=0; i<=6;i++) {
            numBaixo = desenhaCartasColuna(NULL, colunas_baixo[i], i+1, 0, multi_res, numBaixo);
            desenhaCartasColuna(colunas_cima[i], NULL, i+1, 1, multi_res, numBaixo);
        }
        EndDrawing();
    }
    salvarJogo(colunas_cima, colunas_baixo, pilha_copas, pilha_ouro, pilha_paus, pilha_espadas, baralho_embaralhado);

    CloseWindow();


    destroiListaCircEnc(baralho);
    destroiListaCircEnc(baralho_embaralhado);
    destroiListaCircEnc(baralho_compras);
    destroiPilhaEnc(pilha_copas);
    destroiPilhaEnc(pilha_ouro);
    destroiPilhaEnc(pilha_espadas);
    destroiPilhaEnc(pilha_paus);
    for (int i=0;i<=6;i++) {
        free(colunas_baixo[i]);
        free(colunas_cima[i]);
    }
}

void carregarJogo() {

}

void creditos() {
    printf("TODOS OS DIREITOS RESERVADOS\nGABRIEL\nGUSTAVO\nMURILO");
}

void sair() {
    abort();
}

void salvarJogo(FilaEnc *colunas_cima[7], PilhaEnc *colunas_baixo[7], PilhaEnc *pilha_copas, PilhaEnc *pilha_ouros, PilhaEnc *pilha_paus, PilhaEnc *pilha_espadas, ListaCircEnc *baralho) {
    FILE *jogoSalvo;
    jogoSalvo = fopen("./jogoSalvo.txt", "w");
    NodoFEnc *coluna_cimaAux;
    NodoPEnc *coluna_baixoAux;
    NodoLEnc *baralhoAux;
    NodoPEnc *pilhasAux;

    for (int i =0; i <= 6; i++) {
        coluna_baixoAux = colunas_baixo[i]->topo;
        coluna_cimaAux = colunas_cima[i]->ini;
        
        if (coluna_baixoAux != NULL) {
            while (coluna_baixoAux != NULL) {
                fprintf(jogoSalvo ,"%d\n", coluna_baixoAux->info.chave);
                coluna_baixoAux = coluna_baixoAux->prox;
            }
        }
        fprintf(jogoSalvo, "\n");

        if (coluna_cimaAux != NULL) {
            while (coluna_cimaAux != NULL) {
                fprintf(jogoSalvo ,"%d\n", coluna_cimaAux->info.chave);
                coluna_cimaAux = coluna_cimaAux->prox;
            }
        }
        fprintf(jogoSalvo, "\n");
    }

    pilhasAux = pilha_copas->topo;
    if (pilhasAux != NULL) {
        while (pilhasAux != NULL) {
            fprintf(jogoSalvo, "%d\n", pilhasAux->info.chave);
            pilhasAux = pilhasAux->prox;
        }
    }
    fprintf(jogoSalvo, "\n");

    pilhasAux = pilha_ouros->topo;
    if (pilhasAux != NULL) {
        while (pilhasAux != NULL) {
            fprintf(jogoSalvo, "%d\n", pilhasAux->info.chave);
            pilhasAux = pilhasAux->prox;
        }
    }
    fprintf(jogoSalvo, "\n");

    pilhasAux = pilha_paus->topo;
    if (pilhasAux != NULL) {
        while (pilhasAux != NULL) {
            fprintf(jogoSalvo, "%d\n", pilhasAux->info.chave);
            pilhasAux = pilhasAux->prox;
        }
    }
    fprintf(jogoSalvo, "\n");

    pilhasAux = pilha_espadas->topo;
    if (pilhasAux != NULL) {
        while (pilhasAux != NULL) {
            fprintf(jogoSalvo, "%d\n", pilhasAux->info.chave);
            pilhasAux = pilhasAux->prox;
        }
    }
    fprintf(jogoSalvo, "\n");

    baralhoAux = baralho->prim->ant;
    int c = baralhoAux->info.chave;
    if (baralhoAux != NULL) {
        do{
            baralhoAux = baralhoAux->prox;
            fprintf(jogoSalvo, "%d\n", baralhoAux->info.chave);
        } while (baralhoAux->info.chave != c);
    }
    fprintf(jogoSalvo, "\n");
}