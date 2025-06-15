#include <stdio.h>

#define Linha 10
#define Coluna 10

//altera valores na Matriz para numero 5 pra simular desenho de um Cone 
void especialCone(int tabuleiro[Linha][Coluna]) {
    for (int linha = 0; linha < Linha; linha++) {
        for (int coluna = 0; coluna < Coluna; coluna++) {
            if (linha == 0 && coluna == 5) tabuleiro[linha][coluna] = 5;
            if (linha == 1 && coluna >= 4 && coluna <= 6) tabuleiro[linha][coluna] = 5;
            if (linha == 2 && coluna >= 3 && coluna <= 7) tabuleiro[linha][coluna] = 5;
        }
    }
}
//altera valores na Matriz para numero 5 para simular desenho de uma Cruz 
void especialCruz(int tabuleiro[Linha][Coluna]) {
    for (int j = 0; j <= 4; j++) { 
        tabuleiro[7][j] = 5;
    }
    for (int i = 5; i <= 9; i++) { 
        tabuleiro[i][2] = 5;
    }
}
void especialOcto(int tabuleiro[Linha][Coluna]){
     for (int i = 4; i <= 7; i++) {
        for (int j = 0; j <= 8; j++) {
            if ((i >= 4 && i <= 6 && j == 7) || (i == 5 && j >= 6 && j <= 8)) {
                tabuleiro[i][j] = 5; 
            }
        }
    }
}

int main() {

    char LetrasColuna[10] = {'A','B','C','D','E','F','G','H','I','J'}; // vetor para criar o indice das colunas
    int tabuleiro[Linha][Coluna];
    int index, linha, coluna;

    printf("  "); // Espaço para ajustar o cabeçalho de letras com as colunas
    for (index = 0; index < 10; index++) { 
        printf("%2c", LetrasColuna[index]); // Imprime as letras das colunas
    }
    printf("\n");

    // Preenche o vetor/matriz com o número "0"
    for (linha = 0; linha < Linha; linha++) {
        for (coluna = 0; coluna < Coluna; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // altera valores na Matriz para o numero 3 para silumar o desenho de um barco horizontal
    for (coluna = 2; coluna < 5; coluna++) {
        if (tabuleiro[9][coluna] == 0) { 
            tabuleiro[9][coluna] = 3;
        }
    }
   
    // altera valores na Matriz para o numero 3 silumar o desenho de um barco vertical
    for (linha = 5; linha < 8; linha++) {
        if (tabuleiro[linha][5] == 0) { 
            tabuleiro[linha][5] = 3;
        }
    }

    // altera valores na Matriz para numero 3 silumar o desenho de um barco diagonal esquerda
    for (linha = 0; linha < 3; linha++) {
        if (tabuleiro[linha][linha] == 0) { 
            tabuleiro[linha][linha] = 3;
        }
    }

    // altera valores na Matriz para numero 3 silumar o desenho de um barco diagonal direita
    for (linha = 0; linha < 3; linha++) {
        int coluna = 9 - linha; 
        if (tabuleiro[linha][coluna] == 0) { 
            tabuleiro[linha][coluna] = 3;
        }
    }

    especialCone(tabuleiro);
    especialCruz(tabuleiro);
    especialOcto(tabuleiro);

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