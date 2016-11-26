#include "todas.h"
#include "lionphys.cpp"
#include "mapa2.cpp"

using namespace std;

int _x = 0;
int _y = 40;

class Canhao {
    VetorBi S;
    int vidas = 5;
public:
    void Inicia(int x, int y) {
        S.x = x;
        S.y = y;
        ImprimirArquivo("tanque.txt", S.x, S.y);
    }
    void DisparaBala(float v, int angulo, VetorBi s0) {
        VetorBi coord;
        float Vx;
        float Vy;
        int Xcoord = 0;
        int Ycoord = 0;

        Vx = DecompoeVetorBi(v, angulo).x;
        Vy = DecompoeVetorBi(v, angulo).y;

        for (float t = 0; mapa[Ycoord][Xcoord] != '@'; t += 0.1) {
            mapa[Ycoord][Xcoord] = ' ';
            coord = MovRetUniVariado(Vx, Vy, s0, t, 10);
            GotoXY(coord.x, coord.y);
            cout << "*";
            GotoXY(118,0);
            cout << coord.x << " " << coord.y;
            Xcoord = static_cast <int> (coord.x);
            Ycoord = static_cast <int> (coord.y);
            Sleep(250);

            GotoXY(coord.x, coord.y);
            cout << " ";
        }
    }


};
