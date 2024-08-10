#include "baralho.h"
#include "raylib.h"
#include "opcoes.h"


int main(void)
{
    int opcao = iniciaMenu();

    if (opcao == 1) {
        novoJogo();
    }
    return 0;
}
