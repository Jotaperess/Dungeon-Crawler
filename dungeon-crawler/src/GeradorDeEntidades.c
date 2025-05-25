#include "ent.h"

// gerador de entidades
void gerarentidade(int tamanho, char mapa[tamanho][tamanho], int fase){
    int i, j;
    
    switch (fase) {
        case 1:  
            mapa[1][1] = '&';  
            mapa[2][2] = 'P';        
            mapa[2][7] = 'P';    
            mapa[5][5] = '@';   
            mapa[0][5] = 'D';   
            break;

        case 2:  
            mapa[1][1] = '&';     
            mapa[8][8] = '@';    
            mapa[9][5] = 'D';     

            mapa[3][3] = '*';
            mapa[4][3] = '*';
            mapa[5][3] = '*';
            mapa[5][4] = '*';
            mapa[5][5] = '*';
            break;

        case 3:  
            mapa[1][1] = '&';       
            mapa[18][18] = '@';    
            mapa[0][10] = 'D';      
            mapa[10][10] = 'O';     
            mapa[15][15] = 'X';     

            for (i = 5; i < 15; i++) {
                if (i % 2 == 0) {
                    mapa[i][8] = '#';
                    mapa[i][12] = '#';
                }
            }
            for (j = 8; j <= 12; j++) {
                mapa[10][j] = ' ';
            }
            break;

        case 4:  
            mapa[2][2] = '&';        
            mapa[30][39] = 'D';       
            mapa[5][35] = '>';
            mapa[35][5] = '>';
            mapa[30][10] = 'V';      
            mapa[12][10] = 'X';
			mapa[34][34] = '@';  
            mapa[31][25] = 'O';      

            for (i = 20; i < 36; i++) {
                for (j = 20; j < 36; j++) {
                    mapa[i][j] = '#';
                }
            }

            for (i = 20; i < 36; i++) {
                mapa[i][27] = ' ';
                if (i % 4 == 0)
                    mapa[i][30] = ' ';
            }
            for (j = 20; j < 36; j++) {
                mapa[28][j] = ' ';
                if (j % 5 == 0)
                    mapa[32][j] = ' ';
            }

              

            break;
    }
}
