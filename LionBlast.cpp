#include "LionBlast_teste.h"

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

    VetorBi sA;

    float vA;
    float vB;
    A.Inicia(sA.x-3, sA.y-2);
    sA.x = A.S.x+3;
    sA.y = A.S.y;
    while (1) {
        cin >> vA;
        A.DisparaBala(vA, 30, sA);
    }


}
