#include "LionMath.h"

using namespace std;

/**\brief recebe a velocidade, posição inicial e tempo do movimento do corpo e
          retorna sua posição após descrever o Movimento Retilíneo Uniforme */
VetorBi MovRetUniforme (float v, VetorBi s0, float t) {
    VetorBi coord;
    coord.x = s0.x + v*t;
    coord.y = s0.y + v*t;
    return coord;
}

/**\brief recebe as velocidades X e Y, o vetor posição, o tempo e a aceleração e retorna a posição
          após descrever o Movimento Retilíneo Uniformemente Variado */
VetorBi MovRetUniVariado (float Vx, float Vy, VetorBi s0, float t, float a) {
    VetorBi coord;
    coord.x = s0.x + Vx*t;
    coord.y = s0.y - Vy*t + (a*(t*t))/2;

    return coord;
}

VetorBi MovCircularUni (float w, float t) {

}

/**\brief -Recebe as coordenadas X e Y das circunferências A e B e o raio de cada uma
          -Retorna true se houve colisão e false se não houve */
bool ColideCirculo (VetorBi A, VetorBi B, float rA, float rB) {
    float d;
    d = sqrt(pow(A.x + B.x, 2) + pow(A.y + B.y, 2));
    if (d <= (rA + rB)) {
        return true;
    }else{
        return false;
    }
}
