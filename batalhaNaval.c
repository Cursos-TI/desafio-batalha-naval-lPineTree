#include <stdio.h>

int main() {
    int cone[3][5] = {{0,0,1,0,0},
                      {0,1,1,1,0},
                      {1,1,1,1,1}};

    int cruz[5][5] = {{0,0,1,0,0},
                      {0,0,1,0,0},
                      {1,1,1,1,1},
                      {0,0,1,0,0},
                      {0,0,1,0,0}};

    int octaedro[5][5] = {{0,0,1,0,0},
                          {0,1,1,1,0},
                          {1,1,1,1,1},
                          {0,1,1,1,0},
                          {0,0,1,0,0}};
                         
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
    
    printf("\n Usando as habilidades!\n \n");
    //usando a habilidade cone no tabuleiro
    for (int i = 2, j = 3; i < 5; i++, j++){
        for (int k = 2, l = 2; k < j; k++, l--){
            //garantindo que a área da habilidade não sobreponha o navio
            if (tabuleiro[i][k] == 3){
                tabuleiro[i][k] = 3;
            } else {
            tabuleiro[i][k] = cone[i-2][k];}
            //garantindo que a área da habilidade não sobreponha o navio
            if (tabuleiro[i][l] == 3){
                tabuleiro[i][l] = 3;
            } else {
            tabuleiro[i][l] = cone[i-2][l];}
        }
    }
    //usando a habilidade cruz no tabuleiro
    for (int i = 2, j = 2; i < 5; i++, j--){
        //garantindo que a área da habilidade não sobreponha os navios
        if (tabuleiro[i][6] == 3){
            tabuleiro[i][6] = 3;
        } else {
        tabuleiro[i][6] = cruz[i][2];}
        //garantindo que a área da habilidade não sobreponha os navios
        if (tabuleiro[j][6] == 3){
            tabuleiro[j][6] = 3;
        } else {
        tabuleiro[j][6] = cruz[j][2];}
    }
    for(int i = 6, j = 6; i < 9 || j > 3; i++, j--){
        //garantindo que a área da habilidade não sobreponha os navios
        if (tabuleiro[2][i] == 3){
            tabuleiro[2][i] = 3;
        } else {
        tabuleiro[2][i] = cruz[2][i-4];}
        //garantindo que a área da habilidade não sobreponha os navios
        if (tabuleiro[2][j] == 3){
            tabuleiro[2][j] = 3;
        } else {
        tabuleiro[2][j] = cruz[2][j-4];}
        
    }
    //usando a habilidade octaedro
    for (int i = 7, j = 7; i < 10; i++, j--){
        for (int k = 5, l = 9; k < j+1; k++, l--){
            //garantindo que a área da habilidade não sobreponha os navios
            if (tabuleiro[i][l+j-7] == 3){
                tabuleiro[i][l+j-7] = 3;
            } else {
            tabuleiro[i][l+j-7] = octaedro[2][k-5];}
            if (tabuleiro[i][k+i-7] == 3){
                tabuleiro[i][k+i-7] = 3;
            } else {
            tabuleiro[i][k+i-7] = octaedro[2][l-7];}
            //garantindo que a área da habilidade não sobreponha os navios
            if (tabuleiro[j][l+j-7] == 3){
                tabuleiro[j][l+j-7] = 3;
            } else {
            tabuleiro[j][l+j-7] = octaedro[2][k-5];}
            if (tabuleiro[j][k+i-7] == 3){
                tabuleiro[j][k+i-7] = 3;
            } else {
            tabuleiro[j][k+i-7] = octaedro[2][l-7];}
        }
        
    }
    

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
