#include "LionBlast.h"

int main ()

{
    srand(time(NULL));
    ConsoleSize(124,44);
    Canhao A;
    Canhao B;

    for (int j = 0; j < 45; j++) {
        for (int i = 0; i < 124; i++) {
            cout << mapa[j][i];
        }
    }

    bool good = false;
    int xA;
    int yA;

    while (!good) {
        xA = rand()%57;
        yA = rand()%40;
        if ((mapa[yA+2][xA] != '@') && (mapa[yA+2][xA+3] != '@') && (mapa[yA+3][xA] == '@')) {
            good = true;
        }else{
            good = false;
        }
    }

    VetorBi S;

    S.x = xA+3;
    S.y = yA-3;

    float v;

    int teste;
    A.Inicia(xA-3, yA-2);
    while (1) {
        cin >> v;
        A.DisparaBala(v, 30, S);
    }
}
