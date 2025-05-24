#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// menu principal
int menu() {
    int opcao;

    printf("MENU:\n");
    printf("1 - Jogar\n");
    printf("2 - Creditos\n");
    printf("3 - Sair\n");
    scanf("%d", &opcao);

    return opcao;
}



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




// verificador de fase
int verificarfase(int fase) {
    switch (fase) {
        case 1:
        return 10;
        break;

        case 2:
            return 10;
            break;

        case 3:
            return 20;
            break;

        case 4:
            return 40;
            break;

        default:
            return -1;
            break;
    }
}

//gerador de mob
 void gerarmob(int tamanho, char mapa[tamanho][tamanho], int fase){
	 int i,j;
	 
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

            mapa[34][34] = '@';  
            mapa[31][25] = 'O';  

            break;
    }
    
}
 	 //Movimenta o Jogador
	void movimentojogador(int tamanho, char mapa[tamanho][tamanho], int *x, int *y){
		
		char direcao;
		int xjogador = *x;
		int yjogador = *y;
		
		scanf(" %c", &direcao);
		
		switch(direcao)
		{
		case 'w': xjogador--;
			break;
		case 's': xjogador++;
		break;
		case 'a': yjogador--;
		break;
		case 'd': yjogador++;
		break;
		default:
			return;
			
		}
		if(mapa[xjogador][yjogador] != '*'){
			
			mapa[*x][*y] = ' ';
			mapa[xjogador][yjogador] = '&';
			*x = xjogador;
			*y = yjogador; 
			
		}
		
	}

//Movimenta o Monstro 1
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
        default: 
			return;
    }

    
    if (mapa[xmonstro][ymonstro] == ' ') {
        mapa[*x][*y] = ' ';
        mapa[xmonstro][ymonstro] = 'X';
        *x = xmonstro;
        *y = ymonstro;
    }
}	


	//Movimenta o monstro 2
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







//game
int main() {
    srand(time(NULL));
    int opcao;

    do {
        opcao = menu();

        switch (opcao) {
            case 1: {
                int fase = 1;

                while (fase <= 4) {
                    int tamanho = verificarfase(fase);
                    if (tamanho == -1) {
                        printf("gg");
                        break;
                    }
                    char mapa[tamanho][tamanho];

                    printf("fase: %d\n", fase);

                    gerarmapa(tamanho, mapa);
                    gerarmob(tamanho, mapa, fase);
                    printarmapa(tamanho, mapa);
                    
                    fase++;
                }
                break;
            }
            case 2:
                printf("Creditos!!\n");
                break;
            case 3:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 3);

    return 0;
}
