#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

void movimentojogador(int tamanho, char mapa[tamanho][tamanho], int *x, int *y);
void movimentamonstro(int tamanho, char mapa[tamanho][tamanho], int *x, int *y);
void movimentamonstrointeligente(int tamanho, char mapa[tamanho][tamanho], int *monstrodoisX, int *monstrodoisY, int jogadorx, int jogadory);

#endif
