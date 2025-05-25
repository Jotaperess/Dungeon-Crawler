#ifndef INTERACOES_H
#define INTERACOES_H

void interagir_chave_dano(int tamanho, char mapa[tamanho][tamanho], int *x, int *y, int *chave, int *fase, int *vidas, char tecla);
void interagir_npc(int x, int y, char tecla);
void interagir_botao(int tamanho, char mapa[tamanho][tamanho], int x, int y, char tecla);

#endif