#include "LionBlast.h"

int main ()

{
    srand(time(NULL));
    ConsoleSize(124,44);
    Canhao A; ///Canh�o do jogador 1 (spawna do lado esquerdo)
    Canhao B; ///Canh�o do jogador 2 (spawna do lado direito)

    VetorBi sA; ///Posi��o XY do jogador 1 no mapa
    VetorBi sB; ///Posi��o XY do jogador 2 no mapa
    float vA = 0; ///Velocidade do TIRO do jogador 1
    float vB = 0; ///Velocidade do TIRO do jogador 2
    char start; ///Detecta a tecla para iniciar o gauge
    int g = 0; ///Contador do gauge

    /**Imprime o mapa */
    for (int j = 0; j < 45; j++) {
        for (int i = 0; i < 124; i++) {
            cout << mapa[j][i];
        }
    }

    A.Inicia(0, 57, "tanque.txt");
    B.Inicia(67, 57, "tanque2.txt");

    sA.x = A.S.x+2; ///Importa��o da coordenada X da posi��o do jogador 1
    sA.y = A.S.y-2; ///Importa��o da coordenada Y da posi��o do jogador 1
    sB.x = B.S.x-2; ///Importa��o da coordenada X da posi��o do jogador 2
    sB.y = B.S.y-2; ///Importa��o da coordenada Y da posi��o do jogador 2

    B.v = 0;

    while (1) {
        A.Gauge(1, false);
        vA = A.v;
        A.DisparaBala(vA, 30, sA, false);

        start = getch();

        B.Gauge(123, true);
        vB = B.v;
        B.DisparaBala(vB, 30, sB, true);
    }
}
