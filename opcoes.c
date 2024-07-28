#include "baralho.h"
#include "opcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"

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
    ListaCircEnc *baralho = cria_baralho();
    ListaCircEnc *baralho_embaralhado = embaralha_baralho(baralho);
    
    const int screenWidth = 1000;
    const int screenHeight =650;
    InitWindow(screenWidth, screenHeight, "Jogo Paciencia");

    //pilhas superiores (onde os naipes devem ser organizados)
    PilhaEnc *pilha_copas = criaPilhaEnc();
    PilhaEnc *pilha_ouro = criaPilhaEnc();
    PilhaEnc *pilha_paus = criaPilhaEnc();
    PilhaEnc *pilha_espadas = criaPilhaEnc();

    //colunas
    FilaEnc *coluna1_cima = criaFilaEnc();

    FilaEnc *coluna2_cima = criaFilaEnc();
    PilhaEnc *coluna2_baixo = criaPilhaEnc();

    FilaEnc *coluna3_cima = criaFilaEnc();
    PilhaEnc *coluna3_baixo = criaPilhaEnc();

    FilaEnc *coluna4_cima = criaFilaEnc();
    PilhaEnc *coluna4_baixo = criaPilhaEnc();

    FilaEnc *coluna5_cima = criaFilaEnc();
    PilhaEnc *coluna5_baixo = criaPilhaEnc();

    FilaEnc *coluna6_cima = criaFilaEnc();
    PilhaEnc *coluna6_baixo = criaPilhaEnc();

    FilaEnc *coluna7_cima = criaFilaEnc();
    PilhaEnc *coluna7_baixo = criaPilhaEnc();

    //monte de compras
    ListaCircEnc *baralho_compras = criaListaCircEnc();
    NodoLEnc *carta = baralho_embaralhado->prim;
    //inserindo cartas em cada coluna
    for (int i =0; i<28; i++) {
        if (i == 0){
            insereFilaViradoCima(coluna1_cima, carta->info);
        }
        else if (i == 1) {
            inserePilhaViradoBaixo(coluna2_baixo, carta->info);
        }
        else if (i == 2) {
            insereFilaViradoCima(coluna2_cima, carta->info);
        }
        else if (i <= 4) {
            inserePilhaViradoBaixo(coluna3_baixo, carta->info);
        }
        else if (i == 5) {
            insereFilaViradoCima(coluna3_cima, carta->info);
        }
        else if (i <= 8) {
            inserePilhaViradoBaixo(coluna4_baixo, carta->info);
        }
        else if (i == 9) {
            insereFilaViradoCima(coluna4_cima, carta->info);
        }
        else if (i <= 13) {
            inserePilhaViradoBaixo(coluna5_baixo, carta->info);
        }
        else if (i == 14) {
            insereFilaViradoCima(coluna5_cima, carta->info);
        }
        else if (i <= 19) {
            inserePilhaViradoBaixo(coluna6_baixo, carta->info);
        }
        else if (i == 20) {
            insereFilaViradoCima(coluna6_cima, carta->info);
        }
        else if (i <= 26) {
            inserePilhaViradoBaixo(coluna7_baixo, carta->info);
        }
        else insereFilaViradoCima(coluna7_cima, carta->info);

        carta = carta->prox;
    }

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GREEN);

        carta = baralho_embaralhado->prim;
        for (int i=0; i<52; i++) {
            Image cartaImagem = LoadImage(carta->info.imagemtxt);
            ImageResize(&cartaImagem, (cartaImagem.width - cartaImagem.width * 0.8), (cartaImagem.height - cartaImagem.height * 0.8));
            carta->info.imagem = LoadTextureFromImage(cartaImagem);
            UnloadImage(cartaImagem);

            DrawTexture(carta->info.imagem, 20 + i*15, 20 + i*15, WHITE);
            carta = carta->prox;
        }
        DrawText("Jogo Paciencia", 190, 200, 20, RED);

        EndDrawing();
    }

    CloseWindow();


    destroiListaCircEnc(baralho);
    destroiListaCircEnc(baralho_embaralhado);
    destroiListaCircEnc(baralho_compras);
    destroiPilhaEnc(pilha_copas);
    destroiPilhaEnc(pilha_ouro);
    destroiPilhaEnc(pilha_espadas);
    destroiPilhaEnc(pilha_paus);
    destroiPilhaEnc(coluna2_baixo);
    destroiPilhaEnc(coluna3_baixo);
    destroiPilhaEnc(coluna4_baixo);
    destroiPilhaEnc(coluna5_baixo);
    destroiPilhaEnc(coluna6_baixo);
    destroiPilhaEnc(coluna7_baixo);
    destroiFilaEnc(coluna1_cima);
    destroiFilaEnc(coluna2_cima);
    destroiFilaEnc(coluna3_cima);
    destroiFilaEnc(coluna4_cima);
    destroiFilaEnc(coluna5_cima);
    destroiFilaEnc(coluna6_cima);
    destroiFilaEnc(coluna7_cima);
}

void carregarJogo() {

}

void creditos() {
    printf("TODOS OS DIREITOS RESERVADOS\nGABRIEL\nGUSTAVO\nMURILO");
}

void sair() {
    abort();
}