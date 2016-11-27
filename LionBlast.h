#include "todas.h"
#include "lionphys.cpp" ///Biblioteca de f�sica
#include "mapa2.cpp" ///arquivo do mapa 1

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
    /**Recebe a velocidade do TIRO, o �ngulo, a posi��o inicial do canh�o e o lado do canh�o -
    !menos = lado esquerdo; menos = lado direito - e executa a trajet�ria do TIRO */
    void DisparaBala(float v, int angulo, VetorBi s0, bool menos) {
        VetorBi coord; ///coordenada do canh�o
        float Vx; ///Componente X da velocidade
        float Vy; ///Componente Y da velocidade
        int Xcoord = 0; ///Parte inteira da coordenada X (para �ndice do mapa)
        int Ycoord = 0; ///Parte inteira da coordenada Y (para �ndice do mapa)

        /**Decomp�e o vetor Velocidade em componentes X e Y*/
        Vx = DecompoeVetorBi(v, angulo).x;
        Vy = DecompoeVetorBi(v, angulo).y;

        /**Verifica colis�o e para
        for (float t = 0; mapa[Ycoord][Xcoord] != '@'; t += 0.01) {
            if (!menos) {
            coord = MovRetUniVariado(Vx, Vy, s0, t, 1000);
            }else{
                if (menos) {
                    coord = MovRetUniVariado(-1*Vx, Vy, s0, t, 1000);
                }
            }
            /**Imprime o TIRO na coordenada atual*/
            GotoXY(coord.x, coord.y);
            cout << "*";
            GotoXY(118,0);
            cout << coord.x << " " << coord.y;
            Xcoord = static_cast <int> (coord.x); ///Pega a parte inteira de X
            Ycoord = static_cast <int> (coord.y); ///Pega a parte inteira de Y
            Sleep(250);
            /**Apaga o TIRO da coordenada anterior*/
            GotoXY(coord.x, coord.y);
            cout << " ";
        }
    }


};
