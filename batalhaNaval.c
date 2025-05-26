#include <stdio.h>

#define Linha 10
#define Coluna 10

void especialCone(int tabuleiro[Linha][Coluna]) {
    for (int linha = 0; linha < Linha; linha++) {
        for (int coluna = 0; coluna < Coluna; coluna++) {
            if (linha == 0 && coluna == 5) tabuleiro[linha][coluna] = 3;
            if (linha == 1 && coluna >= 4 && coluna <= 6) tabuleiro[linha][coluna] = 3;
            if (linha == 2 && coluna >= 3 && coluna <= 7) tabuleiro[linha][coluna] = 3;
        }
    }
}

int main() {

    char LetrasColuna[10] = {'A','B','C','D','E','F','G','H','I','J'}; 
    int tabuleiro[Linha][Coluna];
    int index, linha, coluna;

    printf("  "); // Espaço para ajustar o cabeçalho de letras com as colunas
    for (index = 0; index < 10; index++) { 
        printf("%2c", LetrasColuna[index]); // Imprime as letras das colunas
    }
    printf("\n");

    // Preenche as posições do vetor com o número "0"
    for (linha = 0; linha < Linha; linha++) {
        for (coluna = 0; coluna < Coluna; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Chama a função especialCone para alterar algumas posições
    //especialCone(tabuleiro);

    // Posição do barco horizontal
    for (coluna = 2; coluna < 5; coluna++) {
        if (tabuleiro[9][coluna] == 0) { 
            tabuleiro[9][coluna] = 3;
        }
    }
   
    // Posição do barco vertical
    for (linha = 5; linha < 8; linha++) {
        if (tabuleiro[linha][5] == 0) { 
            tabuleiro[linha][5] = 3;
        }
    }

    // Posição do barco diagonal esquerda
    for (linha = 0; linha < 3; linha++) {
        if (tabuleiro[linha][linha] == 0) { 
            tabuleiro[linha][linha] = 3;
        }
    }

    // Posição do barco diagonal direita
    for (linha = 0; linha < 3; linha++) {
        int coluna = 9 - linha; // Ajuste correto para a diagonal direita
        if (tabuleiro[linha][coluna] == 0) { 
            tabuleiro[linha][coluna] = 3;
        }
    }

    // Imprime o tabuleiro completo
    for (linha = 0; linha < Linha; linha++) {
        printf("%2d ", linha + 1); // Imprime o número das linhas do tabuleiro
        for (coluna = 0; coluna < Coluna; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}