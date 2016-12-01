#include "LionBlast.h"

int LimpaGauge(int x) {
    GotoXY(x, 43);
    cout << "                              ";
}

int main ()

{
    srand(time(NULL));
    ConsoleSize(124,44);
    Canhao A; ///Canhão do jogador 1 (spawna do lado esquerdo)
    Canhao B; ///Canhão do jogador 2 (spawna do lado direito)

    VetorBi sA; ///Posição XY do jogador 1 no mapa
    VetorBi sB; ///Posição XY do jogador 2 no mapa
    float vA = 0; ///Velocidade do TIRO do jogador 1
    float vB = 0; ///Velocidade do TIRO do jogador 2
    char start; ///Detecta a tecla para iniciar o gauge
    int g = 0; ///Contador do gauge
    int angA = 0;
    int angB = 0;

    /**Imprime o mapa */
    for (int j = 0; j < 45; j++) {
        for (int i = 0; i < 124; i++) {
            cout << mapa[j][i];
        }
    }

    A.Inicia(0, 57, "tanque.txt");
    B.Inicia(67, 57, "tanque2.txt");

    sA.x = A.S.x+2; ///Importação da coordenada X da posição do jogador 1
    sA.y = A.S.y-2; ///Importação da coordenada Y da posição do jogador 1
    sB.x = B.S.x-2; ///Importação da coordenada X da posição do jogador 2
    sB.y = B.S.y-2; ///Importação da coordenada Y da posição do jogador 2

    while (1) {
        angA = 0;
        start = getch();
        angA = A.DefineAngulo(start);
        //A.v = 0;
        //A.Gauge(1, false);
        vA = A.Gauge(1, false);
        A.DisparaBala(vA, angA, sA, false);
        LimpaGauge(1);

        angB = 0;
        start = getch();
        angB = B.DefineAngulo(start);
        //B.v = 0;
        vB = B.Gauge(122, true);
        //vB = B.v;
        B.DisparaBala(vB, angB, sB, true);
        LimpaGauge(93);
    }
}
