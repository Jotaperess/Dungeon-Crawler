
#include <stdio.h>
#include "interacoes.h"

void interagir_chave_dano(int tamanho, char mapa[tamanho][tamanho], int *x, int *y, int *chave, int *fase, int *vidas, char tecla) {
    char posicao = mapa[*x][*y];

    // Pega a chave
    if (posicao == '@' && tecla == 'i') {
        *chave = 1;
        mapa[*x][*y] = ' ';
    }

    // Avança de fase se tiver chave
    if (posicao == 'D' && *chave) {
        mapa[*x][*y] = '=';
        (*fase)++;
    }

    // Toma dano de monstros ou espinhos
    if (posicao == 'X' || posicao == '#' || posicao == 'V') {
        (*vidas)--;
        *x = 1;
        *y = 1;
    }
}

void interagir_npc(int x, int y, char tecla) {
    if (tecla == 'i') {
        if (x == 2 && y == 2) {
            printf("\n[ NPC ] Pegue a chave (@) e pressione 'i' para usá-la na porta (D).\n");
        } else if (x == 2 && y == 7) {
            printf("\n[ NPC ] Cuidado com monstros (X/V) e espinhos (#), eles causam dano!\n");
        }
    }
}

void interagir_botao(int tamanho, char mapa[tamanho][tamanho], int x, int y, char tecla) {
    if (tecla == 'i' && mapa[x][y] == 'O') {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < tamanho && ny >= 0 && ny < tamanho) {
                mapa[nx][ny] = '#';
            }
        }
    }
}
