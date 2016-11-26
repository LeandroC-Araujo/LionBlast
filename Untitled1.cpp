#include "lionphys.cpp"
#include "todas.h"

using namespace std;

int main()

{
    VetorBi coord;
    VetorBi s0;
    s0.x = 0;
    s0.y = 70;
    for (float t = 0; t < 10; t += 0.01) {
        coord = MovRetUniVariado(10, 20, s0, t, 5);
        GotoXY(coord.x, coord.y);
        cout << "*";
        Sleep(250);
        }
}
