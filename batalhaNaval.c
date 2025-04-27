#include <stdio.h>

int main() {
    int navio1 [3] = {3, 3, 3}; //Navio horizontal de tamanho 3
    int navio2 [3] = {3, 3, 3}; //Navio vertical de tamanho 3
    int tabuleiro [10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Tabuleiro do jogo
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //de batalha naval.
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    //posicionando o navio horizontal ao tabuleiro
    for (int a = 2, b = 0; a < 5; a++, b++){ 
        tabuleiro[8][a] = navio1[b];
    }
    //posicionando o navio vertical ao tabuleiro
    for (int c = 3, d = 0; c < 6; c++, d++){
        tabuleiro[c][6] = navio2[d]; 
    }
    //printando o tabuleiro do jogo com os navios já posicionados
    printf("-Tabuleiro de batalha naval- \n");
    printf ("    A B C D E F G H I J \n");
    for(int i = 0; i < 10; i++){
        //essa linha abaixo é usada para que o tabuleiro fique mais organizado.
        if(i < 9){
            printf ("  %d ", i + 1);
        } else {
            printf(" %d ", i + 1);
        }

        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
