#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10

#define LINHAS_HABILIDADES 3
#define COLUNAS_HABILIDADES 5

int main() {
    int tabuleiro[LINHAS][COLUNAS];
    int cone[LINHAS_HABILIDADES][COLUNAS_HABILIDADES];
    int cruz[LINHAS_HABILIDADES][COLUNAS_HABILIDADES];
    int octaedro[LINHAS_HABILIDADES][COLUNAS_HABILIDADES];

    char coluna[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};

    // Construindo o tabuleiro zerado

    printf("========== TABULEIRO INICIADO ==========\n\n");

    for (int i = 0; i < 11; i++) {
         printf("%c ", coluna[i]);
    }
    
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", i);

        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("========== CONE ==========\n\n");

    for (int i = 0; i < LINHAS_HABILIDADES; i++) {
        for (int j = 0; j < COLUNAS_HABILIDADES; j++) {
            cone[i][j] = 0;
        }
    }

    for (int i = 0; i < LINHAS_HABILIDADES; i++) {
        int meio = COLUNAS_HABILIDADES / 2;
        for (int j = -i; j <= i; j++) {
            int col = meio + j;
            if (col >= 0 && col < COLUNAS_HABILIDADES) {
                cone[i][col] = 5;
            }
        }
    }
    
    for (int i = 0; i < LINHAS_HABILIDADES; i++) {
        for (int j = 0; j < COLUNAS_HABILIDADES; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    } 

     printf("========== CRUZ ==========\n\n");

    for (int i = 0; i < LINHAS_HABILIDADES; i++) {
        for (int j = 0; j < COLUNAS_HABILIDADES; j++) {
            if (i == LINHAS_HABILIDADES / 2 || j == COLUNAS_HABILIDADES / 2) {
                cruz[i][j] = 5;
                printf("%d ", cruz[i][j]);
            } else {
                cruz[i][j] = 0;
                printf("%d ", cruz[i][j]);
            }
        }      

        printf("\n");
    }

     printf("========== OCTAEDRO ==========\n\n");

    for (int i = 0; i < LINHAS_HABILIDADES; i++) {
        for (int j = 0; j < COLUNAS_HABILIDADES; j++) {
            if (i == LINHAS_HABILIDADES / 2 || j == COLUNAS_HABILIDADES / 2) {
                if(j == 0 || j == COLUNAS_HABILIDADES - 1) {
                    octaedro[i][j] = 0;
                    printf("%d ", octaedro[i][j]);
                } else {
                    octaedro[i][j] = 5;
                    printf("%d ", octaedro[i][j]);
                }
            } else {
                octaedro[i][j] = 0;
                printf("%d ", octaedro[i][j]);
            }
        }      

        printf("\n");
    }



    // Posicionando o primeiro navio horizontalmente em G5

    for (int i = 6; i <= 8; i++) {
        tabuleiro[5][i] = 3;
    }

    // Posicionando o segundo navio verticalmente em D2

    for (int i = 2; i <= 4; i++) {
        tabuleiro[i][3] = 3;
    }

    // Posicionando o terceiro navio na diagonal em G6

    for (int i = 6; i <= 8; i++) {
        for (int j = 6; j <= 8; j++) {
            if (i = j) {
                tabuleiro[i][j] = 3;
            }
        }
    }

    // Posicionando o quarto navio na diagonal em C7

     for (int i = 7; i <= 9; i++) {
        for (int j = 0; j <= 2; j++) {
            if (i + j == 9) {
                tabuleiro[i][j] = 3;
            }
        }
    }

    // Posicionando o cone

     for (int i = 0; i < LINHAS_HABILIDADES; i++) {
        for (int j = 0; j < COLUNAS_HABILIDADES; j++) {
            if (2 + i < LINHAS && 4 + j < COLUNAS) {
                if (cone[i][j] != 0) {
                    tabuleiro[2 + i][4 + j] = cone[i][j];
                }
            }
        }
    }

    // Posicionando a cruz

for(int i = 0; i < LINHAS_HABILIDADES; i++) {
        for(int j = 0; j < COLUNAS_HABILIDADES; j++) {
            int x = i + 3;
            int y = j + 3;

            if(x < LINHAS && y < COLUNAS) {
                tabuleiro[x][y] = cruz[i][j];
            }
        }
    }

    // Posicionando o octaedro

    for(int i = 0; i < LINHAS_HABILIDADES; i++) {
        for(int j = 0; j < COLUNAS_HABILIDADES; j++) {
            int x = i + 3;
            int y = j + 3;

            if(x < LINHAS && y < COLUNAS) {
                tabuleiro[x][y] = octaedro[i][j];
            }
        }
    }


     printf("========== TABULEIRO COM NAVIOS ==========\n\n");

    for (int i = 0; i < 11; i++) {
         printf("%c ", coluna[i]);
    }
    
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {       
        printf("%d ", i);

        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

   



    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
