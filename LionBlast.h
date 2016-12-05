#include "todas.h" /// Biblioteca de funções para jogos (autoria de Yorhan Modesto Rogério e Thiago Ken Toyomoto)
#include "lionphys.cpp" /// Biblioteca de física
#include "mapa2.cpp" /// Arquivo do mapa 1

using namespace std;

/**Vetor de valores inteiros para os índices da matriz Mapa*/
struct VetorInt {
    int x;
    int y;
};

/**Classe do Jogador*/
class Canhao {
public:
    /**Vetor posição (armazena para usar na função de TIRO)*/
    VetorInt S;
    /**Recebe os limites da coordenada X e o nome do arquivo correspondente ao canhão
    correto e Imprime o canhão em uma posição aleatória dentro desse limite*/
    void Inicia(int i, int f, string arquivo) {
        bool good = false; ///booleano de condição de saída do while
        /**Gera uma posição aleatória*/
        while (!good) {
        int x = rand()%f+i;
        int y = rand()%37;
        /**Verifica se a posição gerada não está vazia*/
        if ((mapa[y+2][x] != '@') && (mapa[y+2][x+3] != '@') && (mapa[y+3][x] == '@')) {
            good = true;
            S.x = x; ///armazena o valor X
            S.y = y; ///armazena o valor Y
        }else{
            good = false;
        }
    }
    /**O canhão é impresso na posição definitiva*/
    ImprimirArquivo(arquivo, S.x-3, S.y-2);
    }

    /** Recebe a tecla pressionada pelo usuário. O jogador define o ângulo e
        e a função retorna seu valor numérico */
    int DefineAngulo (char tecla) {
        int angulo = 0;
        /** Função não retorna enquanto o jogador não pressionar espaço de novo */
        while (tecla != ' ') {
            /** Loop do ângulo: Não pode ser superior a 75 ou inferior a 0 */
            while (tecla != ' ' && angulo < 76 && angulo > -1) {
            tecla = getch();
            /** Caso o jogador aperte para cima: Ângulo aumenta */
            if (tecla == 72) {
                angulo+=15;
                if (angulo > 75) {
                    angulo = 0;
                }
            }else {
                /** CAso o jogador aperte para baixo: Ângulo diminui */
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

    /** Recebe uma posição X e um booleano - caso false: Jogador 1; caso true: Jogador 2 -
        imprime o Gauge na tela e retorna a velocidade do TIRO */
    float Gauge (int x, bool menos) {
        GotoXY(0,0);
        int g = 0; /// contador do gauge
        float v; /// velocidade
        char start; /// inicia o gauge
        start = getch();
        if (start == ' ') { /// Primeira tecla para iniciar o Gauge
            while (!kbhit()) { /// Segunda tecla para parar o Gauge
                if(g < 30) { /// Número máximo = 30
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

    /**Recebe a velocidade do TIRO, o ângulo, a posição inicial do canhão e o lado do canhão, -
    !menos = lado esquerdo; menos = lado direito - executa a trajetória do TIRO e retorna
    se houve colisão ou não */
    bool DisparaBala(float V, int angulo, VetorBi s0, bool menos, VetorBi v, QUADRI S) {
        VetorBi coord; ///coordenada do canhão
        float Vx; ///Componente X da velocidade
        float Vy; ///Componente Y da velocidade
        int Xcoord = 0; ///Parte inteira da coordenada X (para índice do mapa)
        int Ycoord = 0; ///Parte inteira da coordenada Y (para índice do mapa)
        float vetorA[2]; ///Vetor velocidade
        float vetorB[2]; ///Vetor vento

        /** Decompõe o vetor Velocidade em componentes X e Y*/
        Vx = DecompoeVetorBi(V, angulo).x;
        Vy = DecompoeVetorBi(V, angulo).y;

        /** Decompõe o vetor Vento em componentes X e Y*/
        vetorB[0] = DecompoeVetorBi(v.x, v.y).x;
        vetorB[1] = DecompoeVetorBi(v.x, v.y).y;

        /**Verifica colisão e para o TIRO quando ele colidir com o mapa*/
        for (float t = 0; mapa[Ycoord][Xcoord] != '@' && !Colisao(coord, S);t += 0.0001) {
            if (!menos) {
            coord = MovRetUniVariado_esquerda(Vx, Vy, s0, t, 100, vetorB);
            }else{
                if (menos) {
                    coord = MovRetUniVariado_direita(Vx, Vy, s0, t, 100, vetorB);
                }
            }

            /** Verifica se o tiro saiu da tela e para sua trajetória em caso verdadeiro */
            if (coord.x > 124 || coord.x < 0 || coord.y < 0) {
                break;
            }
            /**Imprime o TIRO na coordenada atual*/
            GotoXY(coord.x, coord.y);
            cout << "*";
            Xcoord = static_cast <int> (coord.x); ///Pega a parte inteira de X
            Ycoord = static_cast <int> (coord.y); ///Pega a parte inteira de Y
            Sleep(0.5);
            /**Apaga o TIRO da coordenada anterior*/
            GotoXY(coord.x, coord.y);
            cout << " ";
        }
        /** Verifica se a colisão ocorreu */
        if (Colisao(coord, S)) {
            return true;
        }else{
            return false;
        }
    }

};
