#include <stdio.h>
#include "menu.h"

void exibirMenu() {
    printf("===== DUNGEON CRAWLER =====\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Cr�ditos\n");
    printf("3. Sair\n");
}

int lerOpcaoMenu() {
    int opcao;
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao);
    return opcao;
}
