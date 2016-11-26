#include "todas.h"
#include "lionphys.cpp"

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
    }
    void DisparaBala(int v, int angulo, VetorBi s0) {
        bool out = false;
        bool in = false;
        int Vx;
        int Vy;
        Vx = DecompoeVetorBi(v, angulo).x;
        Vy = DecompoeVetorBi(v, angulo).y;
        for (int t = 0; !out; t+=0.1) {
            MovRetUniVariado (Vx, Vy, s0, t, 10);
            if (s0.y == _y && in) {
                out = true;
            }
            in = true;
        }
        GotoXY(s0.x, s0.y);
        cout << "*";
    }
};
