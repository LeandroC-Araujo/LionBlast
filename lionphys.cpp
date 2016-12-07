#include "LionMath.h"

using namespace std;

struct QUADRI {
    int x;
    int y;
    float h;
    float l;
};

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
VetorBi MovRetUniVariado_esquerda (float Vx, float Vy, VetorBi s0, float t, float a, float vetor[2]) {
    VetorBi coord;

    coord.x = s0.x + Vx*t;
    coord.y = s0.y - Vy*t + a*(t*t)/2;

    coord.x = coord.x + vetor[0]*t;
    coord.y = coord.y + vetor[1]*t;

    return coord;
}

/**\brief recebe as velocidades X e Y, o vetor posição, o tempo e a aceleração e retorna a posição
          após descrever o Movimento Retilíneo Uniformemente Variado */
VetorBi MovRetUniVariado_direita (float Vx, float Vy, VetorBi s0, float t, float a, float vetor[2]) {

    VetorBi coord;

    coord.x = s0.x - Vx*t;
    coord.y = s0.y - Vy*t + a*(t*t)/2;

    coord.x = coord.x + vetor[0]*t;
    coord.y = coord.y + vetor[1]*t;

    return coord;
}

/**\brief recebe as velocidades X e Y, o vetor posição, o tempo e a aceleração e retorna a posição
          após descrever o Movimento Oblíquo */
VetorBi MovObliquo (float Vx, float Vy, VetorBi s0, float t, float a) {
    VetorBi coord;
    float vetor[2];
    vetor[0] = 0;
    vetor[1] = 0;

    coord.x = MovRetUniforme(Vx, s0, t).x;
    coord.y = MovRetUniVariado_esquerda(Vx, Vy, s0, t, a, vetor).y;

    return coord;
}

VetorBi MovCircularUni (float w, float t, float r) {
    VetorBi coord;

    coord.x = cos(w*t)*r;
    coord.y = sin(w*t)*r;
}

bool BoundingBox (QUADRI A, QUADRI B) {
    float esquerda_A = A.x;
    float direita_A = A.x + A.l;
    float cima_A = A.y;
    float baixo_A = A.y + A.h;
    float esquerda_B = B.x;
    float direita_B = B.x + B.l;
    float cima_B = B.y;
    float baixo_B = B.y + B.h;

    if (esquerda_A > direita_B) {
        return false;
    }else{
        if (direita_A < esquerda_B) {
            return false;
        }else{
            if (cima_A > baixo_B) {
                return false;
            }else{
                if (baixo_A < cima_B) {
                    return false;
                }else {
                    return true;
                }
            }
        }
    }
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

/** Igual o Bounding Box, porém a unidade A não possui volume */
bool Colisao (VetorBi A, QUADRI B) {
    float esquerda_B = B.x;
    float direita_B = B.x + B.l;
    float cima_B = B.y;
    float baixo_B = B.y + B.h;
    if (A.x > direita_B) {
        return false;
    }else{
        if (A.x < esquerda_B) {
            return false;
        }else{
            if (A.y > baixo_B) {
                return false;
            }else{
                if (A.y < cima_B) {
                    return false;
                }else {
                    return true;
                }
            }
        }
    }
}

bool Colide_mapa (int x, int y, char mapa[45][124]) {
    if (mapa[y][x] != '@') {
        return false;
    }else{
        return true;
    }
}
