#include <stdio.h>
#include <stdlib.h>
#include "movimentacao.h"

// Movimenta o Jogador
void movimentojogador(int tamanho, char mapa[tamanho][tamanho], int *x, int *y) {
    char direcao;
    int xjogador = *x;
    int yjogador = *y;

    scanf(" %c", &direcao);

    switch (direcao) {
        case 'w': xjogador--; break;
        case 's': xjogador++; break;
        case 'a': yjogador--; break;
        case 'd': yjogador++; break;
        default: return;
    }

    if (mapa[xjogador][yjogador] != '*') {
        mapa[*x][*y] = ' ';
        mapa[xjogador][yjogador] = '&';
        *x = xjogador;
        *y = yjogador;
    }
}

// Movimenta o Monstro 1
void movimentamonstro(int tamanho, char mapa[tamanho][tamanho], int *x, int *y) {
    char direcoes[] = {'w', 'a', 's', 'd'};
    char direcao = direcoes[rand() % 4];
    int xmonstro = *x;
    int ymonstro = *y;

    switch (direcao) {
        case 'w': xmonstro--; break;
        case 's': xmonstro++; break;
        case 'a': ymonstro--; break;
        case 'd': ymonstro++; break;
        default: return;
    }

    if (mapa[xmonstro][ymonstro] == ' ') {
        mapa[*x][*y] = ' ';
        mapa[xmonstro][ymonstro] = 'X';
        *x = xmonstro;
        *y = ymonstro;
    }
}

// Movimenta o Monstro 2 (inteligente)
void movimentamonstrointeligente(int tamanho, char mapa[tamanho][tamanho], int *monstrodoisX, int *monstrodoisY, int jogadorx, int jogadory) {
    int novox = *monstrodoisX;
    int novoy = *monstrodoisY;

    if (*monstrodoisX < jogadorx) novox++;
    else if (*monstrodoisX > jogadorx) novox--;

    if (*monstrodoisY < jogadory) novoy++;
    else if (*monstrodoisY > jogadory) novoy--;

    if (mapa[novox][novoy] == ' ' || mapa[novox][novoy] == '&') {
        mapa[*monstrodoisX][*monstrodoisY] = ' ';
        mapa[novox][novoy] = 'X';
        *monstrodoisX = novox;
        *monstrodoisY = novoy;
    }
}
