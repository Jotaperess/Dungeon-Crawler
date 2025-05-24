#include <stdio.h>
#include <mapa.h>




// gerador de mapa
void gerarmapa(int tamanho, char mapa[tamanho][tamanho]) {
    int x, y;

    for (x = 0; x < tamanho; x++) {
        for (y = 0; y < tamanho; y++) {
            if (x == 0 || x == tamanho - 1 || y == 0 || y == tamanho - 1)
                mapa[x][y] = '*';   
            else
                mapa[x][y] = ' ';
        }
    }
}



// printar o mapa
void printarmapa(int tamanho, char mapa[tamanho][tamanho]){
    int x, y;
    for (x = 0; x < tamanho; x++) {
        for (y = 0; y < tamanho; y++)
            printf("%c", mapa[x][y]);
        printf("\n");              
    }
}