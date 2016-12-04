#include "todas.h" /// Biblioteca de fun��es para jogos (autoria de Yorhan Modesto Rog�rio e Thiago Ken Toyomoto)
#include "lionphys.cpp" /// Biblioteca de f�sica
#include "mapa2.cpp" /// Arquivo do mapa 1

using namespace std;

/**Vetor de valores inteiros para os �ndices da matriz Mapa*/
struct VetorInt {
    int x;
    int y;
};

/**Classe do Jogador*/
class Canhao {
    int vidas = 5;
public:
    /**Vetor posi��o (armazena para usar na fun��o de TIRO)*/
    VetorInt S;
    VetorInt Defcoord;
    /**Recebe os limites da coordenada X e o nome do arquivo correspondente ao canh�o
    correto e Imprime o canh�o em uma posi��o aleat�ria dentro desse limite*/
    void Inicia(int i, int f, string arquivo) {
        bool good = false; ///booleano de condi��o de sa�da do while
        /**Gera uma posi��o aleat�ria*/
        while (!good) {
        int x = rand()%f+i;
        int y = rand()%37;
        /**Verifica se a posi��o gerada n�o est� vazia*/
        if ((mapa[y+2][x] != '@') && (mapa[y+2][x+3] != '@') && (mapa[y+3][x] == '@')) {
            good = true;
            S.x = x; ///armazena o valor X
            S.y = y; ///armazena o valor Y
        }else{
            good = false;
        }
    }
    /**O canh�o � impresso na posi��o definitiva*/
    ImprimirArquivo(arquivo, S.x-3, S.y-2);
    }

    int DefineAngulo (char tecla) {
        int angulo = 0;
        while (tecla != ' '){
            while (tecla != ' ' && angulo < 76 && angulo > -1) {
            tecla = getch();
            if (tecla == 72) {
                angulo+=15;
                if (angulo > 75) {
                    angulo = 0;
                }
            }else {
                if (tecla == 80) {
                    angulo-=15;
                    if (angulo < 0) {
                        angulo = 75;
                    }
                }
            }
            GotoXY(50, 1);
            cout << "       ";
            GotoXY(50, 1);
            cout << angulo;
            }
        }
        return angulo;
    }

    float Gauge (int x, bool menos) {
        GotoXY(0,0);
        int g = 0;
        float v;
        char start;
        start = getch();
        if (start == ' ') {
            while (!kbhit()) {
                if(g < 30) {
                    GotoXY(x,43);
                    cout << (char)219;
                    g++;
                    v+=0.1;
                    if(!menos){
                    x++;
                }else{
                    if (menos){
                    x--;
                    }
                }
                Sleep(200);
                }
            }
            return v;
        }
    }

    /**Recebe a velocidade do TIRO, o �ngulo, a posi��o inicial do canh�o e o lado do canh�o -
    !menos = lado esquerdo; menos = lado direito - e executa a trajet�ria do TIRO */
    void DisparaBala(float V, int angulo, VetorBi s0, bool menos, VetorBi v) {
        VetorBi coord; ///coordenada do canh�o
        float Vx; ///Componente X da velocidade
        float Vy; ///Componente Y da velocidade
        int Xcoord; ///Parte inteira da coordenada X (para �ndice do mapa)
        int Ycoord = 0; ///Parte inteira da coordenada Y (para �ndice do mapa)
        float vetorA[2];
        float vetorB[2];

        /**Decomp�e o vetor Velocidade em componentes X e Y*/
        vetorA[0] = DecompoeVetorBi(V, angulo).x;
        vetorA[1] = DecompoeVetorBi(V, angulo).y;

        vetorB[0] = DecompoeVetorBi(v.x, v.y).x;
        vetorB[1] = DecompoeVetorBi(v.x, v.y).y;
        Vx = SomaESubtraiVetorBi(vetorA, vetorB, false).x;
        Vy = SomaESubtraiVetorBi(vetorA, vetorB, false).y;


        /**Verifica colis�o e para o TIRO quando ele colidir com o mapa*/
        for (float t = 0; mapa[Ycoord][Xcoord] != '@';t += 0.0001) {
            if (!menos) {
            coord = MovRetUniVariado_esquerda(Vx, Vy, s0, t, 100);
            }else{
                if (menos) {
                    coord = MovRetUniVariado_direita(Vx, Vy, s0, t, 100);
                }
            }
            if (coord.x > 124 || coord.x < 0) {
                break;
            }
            /**Imprime o TIRO na coordenada atual*/
            GotoXY(coord.x, coord.y);
            cout << "*";
            GotoXY(100,0);
            cout << V;
            GotoXY(50, 0);
            Xcoord = static_cast <int> (coord.x); ///Pega a parte inteira de X
            Ycoord = static_cast <int> (coord.y); ///Pega a parte inteira de Y
            Sleep(0.4);
            /**Apaga o TIRO da coordenada anterior*/
            GotoXY(coord.x, coord.y);
            cout << mapa[Ycoord][Xcoord];
            //Defcoord.x = Xcoord;
            //Defcoord.y = Ycoord;
        }
    }

    bool Colisao(VetorBi coord, VetorBi S) {
        if (coord.x == S.x && coord.y == S.y) {
            return true;
        }else{
            return false;
        }
    }

};
