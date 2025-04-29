#include <stdio.h>

int main() {
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
    for (int i = 2, j = 0; i < 5; i++, j++){ 
        tabuleiro[8][i] = tabuleiro[8][i] + 3;
        //validando se as coordenadas dos navios estão em uma posição válida
        if (i >= 10 && j >= 10 || tabuleiro[8][i] > 3){
            printf("Um ou mais navios estão em uma posição inválida.\n");
        }
    }
    //posicionando o navio vertical ao tabuleiro
    for (int i = 3, j = 0; i < 6; i++, j++){
        tabuleiro[i][6] = tabuleiro[i][6] + 3;
        //validando se as coordenadas dos navios estão em uma posição válida
        if (i >= 10 && j >= 10 || tabuleiro[i][6] > 3){
            printf("Um ou mais navios estão em uma posição inválida.\n");
        }
    }
    //posicionando o primeiro navio diagonal no tabuleiro
    for (int i = 1, j = 7, k = 0; i < 4; i++, j++, k++){
        tabuleiro[i][j] = tabuleiro[i][j] + 3;
        //validando se as coordenadas dos navios estão em uma posição válida
        if (i >= 10 && j >= 10 || tabuleiro[i][j] > 3){
            printf("Um ou mais navios estão em uma posição inválida.\n");
        }
    }
    //posicionando o segundo navio diagonal no tabuleiro
    for (int i = 6, j = 0, k = 0; i > 3; i--, j++, k++){
        tabuleiro[i][j] = tabuleiro[i][j] + 3;
        //validando se as coordenadas dos navios estão em uma posição válida
        if (i >= 10 && j >= 10 || tabuleiro[i][j] > 3){
            printf("Um ou mais navios estão em uma posição inválida.");
        }
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
