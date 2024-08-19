#include "baralho.h"
#include "opcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include <math.h>

int iniciaMenu() {

    int larguraTela = 800;
    int alturaTela = 600;

    InitWindow(larguraTela, alturaTela, "Menu Principal");


    // Dimensões dos retângulos
    int rectLargura = 200;
    int rectAltura = 60;

    // Posições dos retângulos
    int rectX = larguraTela / 2 - rectLargura / 2;
    int rectY1 = alturaTela / 2 - (2 * rectAltura + 30);  // "Iniciar Jogo"
    int rectY2 = rectY1 + rectAltura + 20;                // "Carregar Jogo"
    int rectY3 = rectY2 + rectAltura + 20;                // "Créditos"
    int rectY4 = rectY3 + rectAltura + 20;                // "Sair"

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 posicaoMouse = GetMousePosition();

        DrawText("Paciência", larguraTela / 2 - MeasureText("Paciência", 40) / 2, rectY1 - 80, 40, DARKGRAY);

        // Primeiro retângulo: "Iniciar Jogo"
        Color rectColor1 = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){rectX, rectY1, rectLargura, rectAltura})) {
            rectColor1 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 1;  // Retorna 1 quando "Iniciar Jogo" é clicado
            }
        }
        DrawRectangle(rectX, rectY1, rectLargura, rectAltura, rectColor1);
        DrawText("Iniciar Jogo", rectX + (rectLargura - MeasureText("Iniciar Jogo", 20)) / 2, rectY1 + (rectAltura - 20) / 2, 20, BLACK);

        // Segundo retângulo: "Carregar Jogo"
        Color rectColor2 = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){rectX, rectY2, rectLargura, rectAltura})) {
            rectColor2 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 2;  // Retorna 2 quando "Carregar Jogo" é clicado
            }
        }
        DrawRectangle(rectX, rectY2, rectLargura, rectAltura, rectColor2);
        DrawText("Carregar Jogo", rectX + (rectLargura - MeasureText("Carregar Jogo", 20)) / 2, rectY2 + (rectAltura - 20) / 2, 20, BLACK);

        // Terceiro retângulo: "Créditos"
        Color rectColor3 = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){rectX, rectY3, rectLargura, rectAltura})) {
            rectColor3 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 3;  // Retorna 3 quando "Créditos" é clicado
            }
        }
        DrawRectangle(rectX, rectY3, rectLargura, rectAltura, rectColor3);
        DrawText("Créditos", rectX + (rectLargura - MeasureText("Créditos", 20)) / 2, rectY3 + (rectAltura - 20) / 2, 20, BLACK);

        // Quarto retângulo: "Sair"
        Color rectColor4 = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){rectX, rectY4, rectLargura, rectAltura})) {
            rectColor4 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 4;  // Retorna 4 quando "Sair" é clicado
            }
        }
        DrawRectangle(rectX, rectY4, rectLargura, rectAltura, rectColor4);
        DrawText("Sair", rectX + (rectLargura - MeasureText("Sair", 20)) / 2, rectY4 + (rectAltura - 20) / 2, 20, BLACK);

        EndDrawing();
    }

    CloseWindow(); // Fechar a janela ao terminar

    return 0; // Retorna 0 se a janela for fechada sem clicar em um retângulo
}

/// Para saber a dimenção da tela

float mult_res(){

    int larguraTela = 800;
    int alturaTela = 600;

    InitWindow(larguraTela, alturaTela, "Menu Principal");


    // Dimensões dos retângulos
    int rectLargura = 200;
    int rectAltura = 60;

    // Posições dos retângulos
    int rectX = larguraTela / 2 - rectLargura / 2;
    int rectY1 = alturaTela / 2 - (2 * rectAltura + 30);  // "Iniciar Jogo"
    int rectY2 = rectY1 + rectAltura + 20;                // "Carregar Jogo"
    int rectY3 = rectY2 + rectAltura + 20;                // "Créditos"
    int rectY4 = rectY3 + rectAltura + 20;                // "Sair"

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 posicaoMouse = GetMousePosition();

         DrawText("Qual tamanho de tela você deseja?", larguraTela / 2 - MeasureText("Qual tamanho de tela você deseja?", 40) / 2, rectY1 - 80, 40, DARKGRAY);

        // Primeiro retângulo: "Iniciar Jogo"
        Color rectColor1 = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){rectX, rectY1, rectLargura, rectAltura})) {
            rectColor1 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 1;  // Retorna 1 quando "Iniciar Jogo" é clicado
            }
        }
        DrawRectangle(rectX, rectY1, rectLargura, rectAltura, rectColor1);
        DrawText("640x400", rectX + (rectLargura - MeasureText("640x400", 20)) / 2, rectY1 + (rectAltura - 20) / 2, 20, BLACK);

        // Segundo retângulo: "Carregar Jogo"
        Color rectColor2 = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){rectX, rectY2, rectLargura, rectAltura})) {
            rectColor2 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 1.5;  // Retorna 2 quando "Carregar Jogo" é clicado
            }
        }
        DrawRectangle(rectX, rectY2, rectLargura, rectAltura, rectColor2);
        DrawText("960x600", rectX + (rectLargura - MeasureText("1280x800", 20)) / 2, rectY2 + (rectAltura - 20) / 2, 20, BLACK);

        // Terceiro retângulo: "Créditos"
        Color rectColor3 = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){rectX, rectY3, rectLargura, rectAltura})) {
            rectColor3 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 2;  // Retorna 3 quando "Créditos" é clicado
            }
        }
        DrawRectangle(rectX, rectY3, rectLargura, rectAltura, rectColor3);
        DrawText("1280x800", rectX + (rectLargura - MeasureText("1280x800", 20)) / 2, rectY3 + (rectAltura - 20) / 2, 20, BLACK);

        // Quarto retângulo: "Sair"
        Color rectColor4 = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){rectX, rectY4, rectLargura, rectAltura})) {
            rectColor4 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return 2.5;  // Retorna 4 quando "Sair" é clicado
            }
        }
        DrawRectangle(rectX, rectY4, rectLargura, rectAltura, rectColor4);
        DrawText("1600x1000", rectX + (rectLargura - MeasureText("1600x1000", 20)) / 2, rectY4 + (rectAltura - 20) / 2, 20, BLACK);

        EndDrawing();
    }

    CloseWindow(); // Fechar a janela ao terminar

    return 0; // Retorna 0 se a janela for fechada sem clicar em um retângulo
}

/// Imprime os nomes de quem desenvolveu o jogo

void creditos(){
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Nomes com Cores Animadas");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Mudança de cor baseada no tempo
        Color color1 = (Color){ (unsigned char)(sin(GetTime() * 2.0f) * 127 + 128), 0, 0, 255 };
        Color color2 = (Color){ 0, (unsigned char)(sin(GetTime() * 2.0f + PI / 2) * 127 + 128), 0, 255 };
        Color color3 = (Color){ 0, 0, (unsigned char)(sin(GetTime() * 2.0f + PI) * 127 + 128), 255 };

        // Nomes a serem desenhados
        const char *nome1 = "Murilo Junqueira";
        const char *nome2 = "Gustavo Titow";
        const char *nome3 = "Gabriel Gonzales";

        // Tamanho da fonte
        int fontSize = 30;

        // Cálculo das posições X para centralizar os nomes
        int textX1 = (screenWidth - MeasureText(nome1, fontSize)) / 2;
        int textX2 = (screenWidth - MeasureText(nome2, fontSize)) / 2;
        int textX3 = (screenWidth - MeasureText(nome3, fontSize)) / 2;

        // Posições Y dos textos
        int textY1 = screenHeight / 2 - 100;
        int textY2 = screenHeight / 2;
        int textY3 = screenHeight / 2 + 100;

        // Desenha três nomes na tela com cores animadas e centralizados
        DrawText(nome1, textX1, textY1, fontSize, color1);
        DrawText(nome2, textX2, textY2, fontSize, color2);
        DrawText(nome3, textX3, textY3, fontSize, color3);

        EndDrawing();
    }

    CloseWindow();

}

/// Para sair

void sair(){


    CloseWindow();  // Fecha a janela e encerra o programa

}




void novoJogo() {

    float multi_res = mult_res();

    ListaCircEnc *baralho = cria_baralho();
    ListaCircEnc *baralho_embaralhado = embaralha_baralho(baralho);

    const int screenWidth = (640*multi_res);
    const int screenHeight = (400*multi_res);
    InitWindow(screenWidth, screenHeight, "Jogo Paciencia");

    //pilhas superiores (onde os naipes devem ser organizados)
    PilhaEnc *pilhas_finais[4];
    for (int i=0; i<=3; i++) {
        pilhas_finais[i] = criaPilhaEnc();
    }

    //colunas
    FilaEnc *colunas_cima[7];
    PilhaEnc *colunas_baixo[7];
    for (int i=0; i <= 6; i++) {
        colunas_cima[i] = criaFilaEnc();
        colunas_baixo[i] = criaPilhaEnc();
    }

    //monte de compras
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

    NodoLEnc *aux;
    NodoLEnc* ultimo;
    for (int i=0; i<=6; i++) {
        aux = colunas_cima[i]->ini;
        while (aux != NULL) {
            carregaImagemCarta(aux, multi_res);
            aux = aux->prox;
        }
        aux = colunas_baixo[i]->topo;
        while (aux != NULL) {
            carregaImagemCarta(aux, multi_res);
            aux = aux->prox;
        }
    }

    aux = baralho_embaralhado->prim->ant;
    ultimo = aux;
    do {
        aux = aux->prox;
        carregaImagemCarta(aux, multi_res);
    } while (aux->info.chave != ultimo->info.chave);
    

    int botaoLargura = 150*multi_res;
    int botaoAltura = 25*multi_res;
    int botaoX = 450*multi_res;
    int botaoY = 400*multi_res - 40;

    int selectedValue = 0;
    int selectedSuit = 0;
    int selectedColumn = 0;

    const char *values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const char *suits[4] = {"Copas", "Ouros", "Paus", "Espadas"};
    const char *columns[7] = {"Coluna 1", "Coluna 2", "Coluna 3", "Coluna 4", "Coluna 5", "Coluna 6", "Coluna 7"};

    Rectangle valueBox = {25*multi_res, 400*multi_res - 40, 75*multi_res, 20*multi_res};
    Rectangle suitBox = {125*multi_res, 400*multi_res - 40, 75*multi_res, 20*multi_res};
    Rectangle columnBox = {225*multi_res, 400*multi_res - 40, 75*multi_res, 20*multi_res};
    Rectangle confirmBox = {325*multi_res, 400*multi_res - 40, 60*multi_res, 20*multi_res};


    bool valueEdit = false;
    bool suitEdit = false;
    bool columnEdit = false;


    int numBaixo;
    int possibilidade = 0; //de mover uma carta

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GREEN);

        //verifica se o jogador venceu o jogo
        int pilhas_prontas = 0;
        for (int i=0; i<=3; i++) {
            if (pilhas_finais[i]->topo != NULL) {
                if (pilhas_finais[i]->topo->info.valor == 13)
                    pilhas_prontas++;
            }
        }
        if (pilhas_prontas == 4) {
            CloseWindow();
            telaUsuarioVenceu(multi_res);
        }

        //desenhando cartas na tela

        numBaixo = 0; // numero de cartas virada para baixo em cada coluna

        for (int i=0; i<=6;i++) {
            if (vaziaFilaEnc(colunas_cima[i]) && !vaziaPilhaEnc(colunas_baixo[i])) {
                desviraCarta(colunas_cima[i], colunas_baixo[i]);
            }
        }

        for (int i=0; i<=6;i++) {
            numBaixo = desenhaCartasViradoBaixo(colunas_baixo[i], i+1, multi_res);
            desenhaCartasViradoCima(colunas_cima[i], i+1, multi_res, numBaixo);
        }
        desenhaBaralhoCompras(baralho_embaralhado, 0, multi_res);
        for (int i =0; i<=3; i++) {
            desenhaPilhasFinais(pilhas_finais[i], i+1, multi_res);
        }

        Vector2 posicaoMouse = GetMousePosition();

        //confere se alguma carta foi clicada para ser adicionada às pilhas finais
        for (int i=0; i <=6; i++) {
            if (colunas_cima[i]->ini != NULL) {
                aux = colunas_cima[i]->fim;
                if (CheckCollisionPointRec(posicaoMouse, aux->info.hitBox)) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        inserePilhasFinais(aux, pilhas_finais[aux->info.naipe -1], colunas_cima[i]);
                    }
                }

            }
        }
        if (CheckCollisionPointRec(posicaoMouse, baralho_embaralhado->prim->info.hitBox)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (pilhas_finais[baralho_embaralhado->prim->info.naipe -1]->topo == NULL && baralho_embaralhado->prim->info.valor == 1) {
                    empilhaPilhaEnc(pilhas_finais[baralho_embaralhado->prim->info.naipe -1], baralho_embaralhado->prim->info);
                    removeInfoListaCircEnc(baralho_embaralhado, baralho_embaralhado->prim->info.chave);
                } else if (baralho_embaralhado->prim->info.valor == pilhas_finais[baralho_embaralhado->prim->info.naipe -1]->topo->info.valor + 1) {
                    empilhaPilhaEnc(pilhas_finais[baralho_embaralhado->prim->info.naipe -1], baralho_embaralhado->prim->info);
                    removeInfoListaCircEnc(baralho_embaralhado, baralho_embaralhado->prim->info.chave);
                }
            }
        }




        Color botaoCor = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){botaoX, botaoY, botaoLargura, botaoAltura})) {
            botaoCor = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return salvarJogo(colunas_cima, colunas_baixo, pilhas_finais[0],pilhas_finais[1],pilhas_finais[2],pilhas_finais[3], baralho_embaralhado);  // Retorna 1 quando "Iniciar Jogo" é clicado
            }
        }
        DrawRectangle(botaoX, botaoY, botaoLargura, botaoAltura, botaoCor);
        DrawText("Salvar Jogo e Sair", botaoX + 10, botaoY + 5, 15*multi_res, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), valueBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            valueEdit = true;
            suitEdit = false;
            columnEdit = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), suitBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            suitEdit = true;
            valueEdit = false;
            columnEdit = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), columnBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            columnEdit = true;
            valueEdit = false;
            suitEdit = false;
        }

        if (valueEdit) {
            if (IsKeyPressed(KEY_RIGHT)) selectedValue = (selectedValue + 1) % 13;
            if (IsKeyPressed(KEY_LEFT)) selectedValue = (selectedValue - 1 + 13) % 13;
        }

        if (suitEdit) {
            if (IsKeyPressed(KEY_RIGHT)) selectedSuit = (selectedSuit + 1) % 4;
            if (IsKeyPressed(KEY_LEFT)) selectedSuit = (selectedSuit - 1 + 4) % 4;
        }

        if (columnEdit) {
            if (IsKeyPressed(KEY_RIGHT)) selectedColumn = (selectedColumn + 1) % 7;
            if (IsKeyPressed(KEY_LEFT)) selectedColumn = (selectedColumn - 1 + 7) % 7;
        }

        if (CheckCollisionPointRec(posicaoMouse, confirmBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            possibilidade = verificaPossibilidadeMudanca(selectedValue + 1, selectedSuit +1, colunas_cima[selectedColumn], colunas_cima, baralho_embaralhado);
            if (possibilidade != -1) {
                if (possibilidade == 8) mudaCartaColuna(NULL, colunas_cima[selectedColumn], baralho_embaralhado,selectedValue +1, selectedSuit +1);
                else mudaCartaColuna(colunas_cima[possibilidade], colunas_cima[selectedColumn], NULL,selectedValue +1, selectedSuit +1);
            }
        }



        DrawRectangleRec(valueBox, valueEdit ? LIGHTGRAY : GRAY);
        DrawRectangleRec(suitBox, suitEdit ? LIGHTGRAY : GRAY);
        DrawRectangleRec(columnBox, columnEdit ? LIGHTGRAY : GRAY);
        DrawRectangleRec(confirmBox, CheckCollisionPointRec(posicaoMouse, confirmBox) ? RED : LIGHTGRAY);

        DrawText(values[selectedValue], valueBox.x + 10, valueBox.y + 5, 15*multi_res, BLACK);
        DrawText(suits[selectedSuit], suitBox.x + 10, suitBox.y + 5, 15*multi_res, BLACK);
        DrawText(columns[selectedColumn], columnBox.x + 10, columnBox.y + 5, 15*multi_res, BLACK);
        DrawText("Confirmar", confirmBox.x +10, confirmBox.y+5, 10*multi_res, BLACK);

        //pilhas laterais
        for (int i = 0; i < 4; i++) {
            int posY = 10 + i * (70*multi_res + 10);

            DrawRectangleLines(560*multi_res, posY, 50*multi_res, 70*multi_res, BLACK);

            const char *naipe;
            switch (i) {
                case 0: naipe = "Copas"; break; // Espadas
                case 1: naipe = "Ouro"; break; // Copas
                case 2: naipe = "Paus"; break; // Ouros
                case 3: naipe = "Espadas"; break; // Paus
            }
            int larguraTexto = MeasureText(naipe, 20); // Largura do texto
            DrawText(naipe, 560*multi_res + (50*multi_res / 2 - larguraTexto / 2), posY + (70*multi_res / 2 - 10), 20, BLACK);
        }

        DrawText("Use as setas esquerda/direita para selecionar valor, naipe e coluna", 35*multi_res, (400 - 70)*multi_res, 15*multi_res, BLACK);
        DrawText("Clique em uma das caixas para editar", 35*multi_res, (400 - 58)*multi_res, 15*multi_res, BLACK);
        EndDrawing();
    }
    CloseWindow();


    destroiListaCircEnc(baralho);
    destroiListaCircEnc(baralho_embaralhado);
    for (int i=0;i<=3;i++){
        destroiPilhaEnc(pilhas_finais[i]);
    }
    for (int i=0;i<=6;i++) {
        free(colunas_baixo[i]);
        free(colunas_cima[i]);
    }
}

void carregarJogo() {

    float multi_res = mult_res();
    const int screenWidth = (640*multi_res);
    const int screenHeight = (400*multi_res);
    InitWindow(screenWidth, screenHeight, "Jogo Paciencia");

    ListaCircEnc *baralho = cria_baralho(multi_res);

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

    ListaCircEnc *baralho_embaralhado = criaListaCircEnc();

    FILE *jogoSalvo;
    jogoSalvo = fopen("./jogoSalvo.txt", "r");

    int aux;
    NodoLEnc *cartaAux;
    for (int i = 0; i<=6; i++) {
        aux = 1;
        while (aux!=0){
            fscanf(jogoSalvo, "%d", &aux);
            if (aux != 0) {
                cartaAux = buscaInfoListaCircEnc(baralho, aux);
                inserePilhaViradoBaixo(colunas_baixo[i], cartaAux->info, NULL);
            }
        }
    }

    for (int i = 0; i<=6; i++) {
        aux = 1;
        while (aux!=0){
            fscanf(jogoSalvo, "%d", &aux);
            if (aux != 0) {
                cartaAux = buscaInfoListaCircEnc(baralho, aux);
                insereFilaViradoCima(colunas_cima[i], cartaAux->info, NULL, NULL, NULL);
            }
        }
    }

    aux = 1;
    while (aux!=0){
        fscanf(jogoSalvo, "%d", &aux);
        if (aux != 0) {
            cartaAux = buscaInfoListaCircEnc(baralho, aux);
            empilhaPilhaEnc(pilha_copas, cartaAux->info);
            cartaAux->info.sentido = 1;
        }
    }

    aux = 1;
    while (aux!=0){
        fscanf(jogoSalvo, "%d", &aux);
        if (aux != 0) {
            cartaAux = buscaInfoListaCircEnc(baralho, aux);
            empilhaPilhaEnc(pilha_ouro, cartaAux->info);
            cartaAux->info.sentido = 1;
        }
    }

    aux = 1;
    while (aux!=0){
        fscanf(jogoSalvo, "%d", &aux);
        if (aux != 0) {
            cartaAux = buscaInfoListaCircEnc(baralho, aux);
            empilhaPilhaEnc(pilha_paus, cartaAux->info);
            cartaAux->info.sentido = 1;
        }
    }

    aux = 1;
    while (aux!=0){
        fscanf(jogoSalvo, "%d", &aux);
        if (aux != 0) {
            cartaAux = buscaInfoListaCircEnc(baralho, aux);
            empilhaPilhaEnc(pilha_espadas, cartaAux->info);

        }
    }

    aux = 1;
    while (aux!=0){
        fscanf(jogoSalvo, "%d", &aux);
        if (aux != 0) {
            cartaAux = buscaInfoListaCircEnc(baralho, aux);
            insereInicioListaCircEnc(baralho_embaralhado, cartaAux->info);
            cartaAux->info.sentido = 1;
        }
    }

    NodoLEnc* ultimo;
    for (int i=0; i<=6; i++) {
        cartaAux = colunas_cima[i]->ini;
        while (cartaAux != NULL) {
            carregaImagemCarta(cartaAux, multi_res);
            cartaAux = cartaAux->prox;
        }
        cartaAux = colunas_baixo[i]->topo;
        while (cartaAux != NULL) {
            carregaImagemCarta(cartaAux, multi_res);
            cartaAux = cartaAux->prox;
        }
    }

    cartaAux = baralho_embaralhado->prim->ant;
    ultimo = cartaAux;
    do {
        cartaAux = cartaAux->prox;
        carregaImagemCarta(cartaAux, multi_res);
    } while (cartaAux->info.chave != ultimo->info.chave);



    //para implementar o baralho, talvez salvar em uma pilha e depois passar para o baralho para garantir a ordem
    int botaoLargura = 150*multi_res;
    int botaoAltura = 25*multi_res;
    int botaoX = 450*multi_res;
    int botaoY = 400*multi_res - 40;

    int selectedValue = 0;
    int selectedSuit = 0;
    int selectedColumn = 0;

    const char *values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const char *suits[4] = {"Copas", "Ouros", "Paus", "Espadas"};
    const char *columns[7] = {"Coluna 1", "Coluna 2", "Coluna 3", "Coluna 4", "Coluna 5", "Coluna 6", "Coluna 7"};

    Rectangle valueBox = {25*multi_res, 400*multi_res - 40, 75*multi_res, 20*multi_res};
    Rectangle suitBox = {125*multi_res, 400*multi_res - 40, 75*multi_res, 20*multi_res};
    Rectangle columnBox = {225*multi_res, 400*multi_res - 40, 75*multi_res, 20*multi_res};
    Rectangle confirmBox = {325*multi_res, 400*multi_res - 40, 60*multi_res, 20*multi_res};


    bool valueEdit = false;
    bool suitEdit = false;
    bool columnEdit = false;


    int numBaixo;
    int possibilidade = 0; //de mover uma carta

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GREEN);

        //desenhando cartas na tela

        numBaixo = 0; // numero de cartas virada para baixo em cada coluna

        for (int i=0; i<=6;i++) {
            if (vaziaFilaEnc(colunas_cima[i]) && !vaziaPilhaEnc(colunas_baixo[i])) {
                desviraCarta(colunas_cima[i], colunas_baixo[i]);

                //RESOLVER BUG DE MOVER MAIS DE UMA VEZ A MESMA CARTA
                //AS CARTAS DE BAIXO NÃO VÃO JUNTO
            }
        }

        for (int i=0; i<=6;i++) {
            numBaixo = desenhaCartasViradoBaixo(colunas_baixo[i], i+1, multi_res);
            desenhaCartasViradoCima(colunas_cima[i], i+1, multi_res, numBaixo);
        }
        desenhaBaralhoCompras(baralho_embaralhado, 0, multi_res);
        Vector2 posicaoMouse = GetMousePosition();

        Color botaoCor = LIGHTGRAY;
        if (CheckCollisionPointRec(posicaoMouse, (Rectangle){botaoX, botaoY, botaoLargura, botaoAltura})) {
            botaoCor = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return salvarJogo(colunas_cima, colunas_baixo, pilha_copas, pilha_ouro, pilha_paus, pilha_espadas, baralho_embaralhado);  // Retorna 1 quando "Iniciar Jogo" é clicado
            }
        }
        DrawRectangle(botaoX, botaoY, botaoLargura, botaoAltura, botaoCor);
        DrawText("Salvar Jogo e Sair", botaoX + 10, botaoY + 5, 15*multi_res, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), valueBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            valueEdit = true;
            suitEdit = false;
            columnEdit = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), suitBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            suitEdit = true;
            valueEdit = false;
            columnEdit = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), columnBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            columnEdit = true;
            valueEdit = false;
            suitEdit = false;
        }

        if (valueEdit) {
            if (IsKeyPressed(KEY_RIGHT)) selectedValue = (selectedValue + 1) % 13;
            if (IsKeyPressed(KEY_LEFT)) selectedValue = (selectedValue - 1 + 13) % 13;
        }

        if (suitEdit) {
            if (IsKeyPressed(KEY_RIGHT)) selectedSuit = (selectedSuit + 1) % 4;
            if (IsKeyPressed(KEY_LEFT)) selectedSuit = (selectedSuit - 1 + 4) % 4;
        }

        if (columnEdit) {
            if (IsKeyPressed(KEY_RIGHT)) selectedColumn = (selectedColumn + 1) % 7;
            if (IsKeyPressed(KEY_LEFT)) selectedColumn = (selectedColumn - 1 + 7) % 7;
        }

        if (CheckCollisionPointRec(posicaoMouse, confirmBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            possibilidade = verificaPossibilidadeMudanca(selectedValue + 1, selectedSuit +1, colunas_cima[selectedColumn], colunas_cima, baralho_embaralhado);
            if (possibilidade != -1) {
                if (possibilidade == 8) mudaCartaColuna(NULL, colunas_cima[selectedColumn], baralho_embaralhado,selectedValue +1, selectedSuit +1);
                else mudaCartaColuna(colunas_cima[possibilidade], colunas_cima[selectedColumn], NULL,selectedValue +1, selectedSuit +1);
            }
        }



        DrawRectangleRec(valueBox, valueEdit ? LIGHTGRAY : GRAY);
        DrawRectangleRec(suitBox, suitEdit ? LIGHTGRAY : GRAY);
        DrawRectangleRec(columnBox, columnEdit ? LIGHTGRAY : GRAY);
        DrawRectangleRec(confirmBox, CheckCollisionPointRec(posicaoMouse, confirmBox) ? RED : LIGHTGRAY);

        DrawText(values[selectedValue], valueBox.x + 10, valueBox.y + 5, 15*multi_res, BLACK);
        DrawText(suits[selectedSuit], suitBox.x + 10, suitBox.y + 5, 15*multi_res, BLACK);
        DrawText(columns[selectedColumn], columnBox.x + 10, columnBox.y + 5, 15*multi_res, BLACK);
        DrawText("Confirmar", confirmBox.x +10, confirmBox.y+5, 10*multi_res, BLACK);

        DrawText("Use as setas esquerda/direita para selecionar valor, naipe e coluna", 35*multi_res, (400 - 70)*multi_res, 15*multi_res, BLACK);
        DrawText("Clique em uma das caixas para editar", 35*multi_res, (400 - 58)*multi_res, 15*multi_res, BLACK);
        EndDrawing();
    }
    CloseWindow();


    destroiListaCircEnc(baralho);
    destroiListaCircEnc(baralho_embaralhado);
    destroiPilhaEnc(pilha_copas);
    destroiPilhaEnc(pilha_ouro);
    destroiPilhaEnc(pilha_espadas);
    destroiPilhaEnc(pilha_paus);
    for (int i=0;i<=6;i++) {
        free(colunas_baixo[i]);
        free(colunas_cima[i]);
    }



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

        if (coluna_baixoAux != NULL) {
            while (coluna_baixoAux != NULL) {
                fprintf(jogoSalvo ,"%d\n", coluna_baixoAux->info.chave);
                coluna_baixoAux = coluna_baixoAux->prox;
            }
        }
        fprintf(jogoSalvo, "%d\n", 0);

    }
    for (int i=0; i<=6;i++) {
        coluna_cimaAux = colunas_cima[i]->ini;

        if (coluna_cimaAux != NULL) {
            while (coluna_cimaAux != NULL) {
                fprintf(jogoSalvo ,"%d\n", coluna_cimaAux->info.chave);
                coluna_cimaAux = coluna_cimaAux->prox;
            }
        }
        fprintf(jogoSalvo, "%d\n", 0);
    }

    pilhasAux = pilha_copas->topo;
    if (pilhasAux != NULL) {
        while (pilhasAux != NULL) {
            fprintf(jogoSalvo, "%d\n", pilhasAux->info.chave);
            pilhasAux = pilhasAux->prox;
        }
    }
    fprintf(jogoSalvo, "%d\n", 0);

    pilhasAux = pilha_ouros->topo;
    if (pilhasAux != NULL) {
        while (pilhasAux != NULL) {
            fprintf(jogoSalvo, "%d\n", pilhasAux->info.chave);
            pilhasAux = pilhasAux->prox;
        }
    }
    fprintf(jogoSalvo, "%d\n", 0);

    pilhasAux = pilha_paus->topo;
    if (pilhasAux != NULL) {
        while (pilhasAux != NULL) {
            fprintf(jogoSalvo, "%d\n", pilhasAux->info.chave);
            pilhasAux = pilhasAux->prox;
        }
    }
    fprintf(jogoSalvo, "%d\n", 0);

    pilhasAux = pilha_espadas->topo;
    if (pilhasAux != NULL) {
        while (pilhasAux != NULL) {
            fprintf(jogoSalvo, "%d\n", pilhasAux->info.chave);
            pilhasAux = pilhasAux->prox;
        }
    }
    fprintf(jogoSalvo, "%d\n", 0);

    baralhoAux = baralho->prim->ant;
    int c = baralhoAux->info.chave;
    if (baralhoAux != NULL) {
        do{
            baralhoAux = baralhoAux->prox;
            fprintf(jogoSalvo, "%d\n", baralhoAux->info.chave);
        } while (baralhoAux->info.chave != c);
    }
    fprintf(jogoSalvo, "%d\n", 0);
}


void telaUsuarioVenceu(float multi_res){
    const int screenWidth = (640*multi_res);
    const int screenHeight = (400*multi_res);
    InitWindow(screenWidth, screenHeight, "Jogo Paciencia");

    int largura_botao = 100*multi_res;
    int altura_botao = 30*multi_res;
    float posX = screenWidth / 2 - largura_botao / 2;

    Rectangle jogarNovo = (Rectangle){posX, screenHeight / 2 - altura_botao -5, largura_botao, altura_botao};
    Rectangle sairJogo = (Rectangle){posX, screenHeight / 2 + altura_botao + 5, largura_botao, altura_botao};
    Color botaoCor1;
    Color botaoCor2;
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GREEN);

        Vector2 posMouse = GetMousePosition();
        botaoCor1 = LIGHTGRAY;
        botaoCor2 = LIGHTGRAY;

        if (CheckCollisionPointRec(posMouse, jogarNovo)) {
            botaoCor1 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                novoJogo();
            }
        }
        if (CheckCollisionPointRec(posMouse, sairJogo)) {
            botaoCor2 = RED;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
            }
        }
        DrawRectangle(jogarNovo.x, jogarNovo.y, jogarNovo.width, jogarNovo.height, botaoCor1);
        DrawRectangle(sairJogo.x, sairJogo.y, sairJogo.width, sairJogo.height, botaoCor2);

        DrawText("PARABÉNS VOCÊ VENCEU!!", posX + posX / 4 - MeasureText("PARABÉNS VOCÊ VENCEU!!", 30) / 2, 120*multi_res, 30, RED);
        DrawText("Novo Jogo", jogarNovo.x  + (jogarNovo.x / 3 - MeasureText("Novo Jogo", 20)), jogarNovo.y + 5, 20, BLACK);
        DrawText("Sair do Jogo", sairJogo.x + (sairJogo.x/3 - MeasureText("Sair do Jogo", 20)), sairJogo.y + 5, 20, BLACK);

        EndDrawing();




    }
    CloseWindow();
}