#include "lionphys.cpp"

using namespace std;

int main()

{
    VetorBi s;
    s.x = 110;
    s.y = 37;
    int x = DecompoeVetorBi(7, 30).x;
    int y = DecompoeVetorBi(7, 30).y;
    cout << MovRetUniVariado(x, y, s, 0.01, 1000).x << endl;
    cout << MovRetUniVariado(x, y, s, 0.01, 1000).y;
}
