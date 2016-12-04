#include "LionBlast.h"

int LimpaGauge(int x) {
    GotoXY(x, 43);
    cout << "                              ";
}

float Vento() {
    srand(time(NULL));
    VetorBi v;
    int n = rand()%8;
    v.x = rand()%1.0 + 0.1; ///módulo
    if (n == 0) {
        v.y = 0; ///ângulo
    }else{
        if (n == 1) {
            v.y = 40;
        }else{
            if (n == 2) {
                v.y = 80;
            }else{
                if (n == 3) {
                    v.y = 120;
                }else{
                    if (n == 4) {
                        v.y = 160;
                    }else{
                        if (n == 5) {
                            v.y = 200;
                        }else{
                            if (n == 6) {
                                v.y = 240;
                            }else{
                                if (n == 7) {
                                    v.y = 280;
                                }else{
                                    if (n == 8) {
                                        v.y == 320;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return v;
}

int main()

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
    char teclaA;
    char teclaB;
    VetorBi coord;
    VetorBi vento;
    vento.x = Vento().x;
    vento.y = Vento().y;

    /**Imprime o mapa */
    for (int j = 0; j < 45; j++) {
        for (int i = 0; i < 124; i++) {
            if (mapa[j][i] == '@') {
                CorFonte(VERDE_CLARO);
                cout << mapa[j][i];
                ResetCor();
            }else{
                if (mapa[j][i] == ' ') {
                    CorFonte(CIANO);
                    cout << mapa[j][i];
                    ResetCor();
                }
            }
        }
    }

    A.Inicia(0, 57, "tanque.txt");
    B.Inicia(67, 57, "tanque2.txt");

    sA.x = A.S.x+2; ///Importação da coordenada X da posição do jogador 1
    sA.y = A.S.y-2; ///Importação da coordenada Y da posição do jogador 1
    sB.x = B.S.x-2; ///Importação da coordenada X da posição do jogador 2
    sB.y = B.S.y-2; ///Importação da coordenada Y da posição do jogador 2

    while (1) {
        vento = Vento();
        angA = 0;
        teclaA = getch();
        angA = A.DefineAngulo(start);
        vA = A.Gauge(1, false);
        A.DisparaBala(vA, angA, sA, false,vento);
        //if (A.Colisao(sA, sB)) {
        //    abort();
        //}
        LimpaGauge(1);

        angB = 0;
        teclaB = getch();
        angB = B.DefineAngulo(start);
        vB = B.Gauge(122, true);
        B.DisparaBala(vB, angB, sB, true,vento);
        LimpaGauge(93);
    }
}
