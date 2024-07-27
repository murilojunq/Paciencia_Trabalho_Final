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

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GREEN);

        NodoLEnc *carta = baralho_embaralhado->prim;
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

}

void carregarJogo() {

}

void creditos() {
    printf("TODOS OS DIREITOS RESERVADOS\nGABRIEL\nGUSTAVO\nMURILO");
}

void sair() {
    abort();
}