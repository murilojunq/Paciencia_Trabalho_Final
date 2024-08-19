#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED


#include <raylib.h>

#define NOME_NAIPE 10
#define TAMANHO_NOME_IMAGEM 30

typedef struct{
    int chave;
    int valor;
    int naipe;
    char imagemtxt[35];
    Texture2D imagem;
    Texture2D imagemBaixo;
    Rectangle hitBox;
    int sentido; //de costas (0) ou de frente (1);
}Carta;

typedef Carta Info;

#endif