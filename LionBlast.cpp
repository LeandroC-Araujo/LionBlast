#include "LionBlast.h"

int main ()

{
    srand(time(NULL));
    ConsoleSize(180,50);
    Canhao A;
    Canhao B;
    int xA;
    int yA;
    int xB;
    int yB;
    ImprimirArquivo("fase1.txt", 0, 0);
    ifstream mapa;
    string _mapa[50];
    mapa.open("fase1.txt");
    if(mapa.is_open() && mapa.good()) {
        for (int j = 0; j < 50; j++) {
            getline(mapa, _mapa[j], '\n');
        }
    }

    for (int j = 0; j < 50; j++) {
        mapa >> _mapa[j];
    }

    xA = rand()%85;
    yA = rand()%50;

    ImprimirArquivo("tanque.txt", xA, yA);
}
