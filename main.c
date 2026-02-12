#include <stdio.h>
#include <stdlib.h>

// Funções para validar movimentos
int moverTorre(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) return 1;
    return 0;
}

int moverBispo(int x1, int y1, int x2, int y2) {
    if (abs(x1 - x2) == abs(y1 - y2)) return 1;
    return 0;
}

int moverCavalo(int x1, int y1, int x2, int y2) {
    if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 1) ||
        (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)) return 1;
    return 0;
}

int moverRei(int x1, int y1, int x2, int y2) {
    if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) return 1;
    return 0;
}

int moverRainha(int x1, int y1, int x2, int y2) {
    if (moverTorre(x1,y1,x2,y2) || moverBispo(x1,y1,x2,y2)) return 1;
    return 0;
}

int moverPeao(int x1, int y1, int x2, int y2) {
    if (x2 == x1 - 1 && y1 == y2) return 1; // Movimento simples do peão branco
    return 0;
}

int main() {
    int opcao, x1, y1, x2, y2;

    printf("=== Movimentacao de Pecas de Xadrez ===\n");
    printf("1 - Torre\n2 - Bispo\n3 - Cavalo\n4 - Rei\n5 - Rainha\n6 - Peao\n");
    printf("Escolha a peca: ");
    scanf("%d", &opcao);

    printf("Digite a posicao inicial (linha coluna de 0 a 7): ");
    scanf("%d %d", &x1, &y1);

    printf("Digite a posicao final (linha coluna de 0 a 7): ");
    scanf("%d %d", &x2, &y2);

    int valido = 0;

    switch(opcao) {
        case 1: valido = moverTorre(x1,y1,x2,y2); break;
        case 2: valido = moverBispo(x1,y1,x2,y2); break;
        case 3: valido = moverCavalo(x1,y1,x2,y2); break;
        case 4: valido = moverRei(x1,y1,x2,y2); break;
        case 5: valido = moverRainha(x1,y1,x2,y2); break;
        case 6: valido = moverPeao(x1,y1,x2,y2); break;
        default: printf("Opcao invalida!\n"); return 0;
    }

    if (valido)
        printf("Movimento VALIDO!\n");
    else
        printf("Movimento INVALIDO!\n");

    printf("Pressione Enter para sair...");
    getchar(); getchar(); // pausa para ver o resultado

    return 0;
}

