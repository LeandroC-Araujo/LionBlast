#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415

struct VetorBi { ///estrutura Vetor Bidimensional
    float x;
    float y;
};

struct VetorTri { ///estrutura Vetor Tridimensional
    float x;
    float y;
    float z;
};

struct MATRIZ { ///estrutura Matriz 3x3
    float matriz[3][3];
    int valor = 0;
};

///TRIGONOMETRIA

/**\brief Recebe um ângulo em graus, retorna em radianos */
float GrausParaRadianos(float anguloGraus) {
return (anguloGraus/180)*PI;
}

/**\brief  Recebe um ângulo em radianos, retorna em graus */
float RadianosParaGraus(float anguloRadianos) {
return (anguloRadianos*180)/PI;
}

/**\brief Recebe um ângulo em graus e retorna seu seno */
float SenoGraus(float anguloGraus) {
return RadianosParaGraus(sin(GrausParaRadianos(anguloGraus)));
}

/**\brief Recebe um ângulo em graus e retorna seu cosseno */
float CossenoGraus(float anguloGraus) {
return RadianosParaGraus(cos(GrausParaRadianos(anguloGraus)));
}

/**\brief Recebe um ângulo em graus e retorna sua tangente */
float TangenteGraus(float anguloGraus) {
return RadianosParaGraus(tan(GrausParaRadianos(anguloGraus)));
}

/**\brief Recebe o seno de um ângulo e retorna o ângulo em graus */
float ArcoSenoGraus(float seno) {
return RadianosParaGraus(asin(seno));
}

/**\brief Recebe o cosseno de um ângulo e retorna o ângulo em graus */
float ArcoCossenoGraus(float cosseno) {
return RadianosParaGraus(acos(cosseno));
}

/**\brief Recebe a tangente de um ângulo e retorna o ângulo em graus */
float ArcoTangenteGraus(float tangente) {
return RadianosParaGraus(atan(tangente));
}

///CÁLCULO VETORIAL

///Bidimensional

/**\brief Recebe o módulo e o ângulo de um vetor bidimensional e o decompõe em componentes X e Y */
VetorBi DecompoeVetorBi(float modulo, float angulo) {
    VetorBi vetor;
    vetor.x = modulo*CossenoGraus(angulo);
    vetor.y = modulo*SenoGraus(angulo);
    return vetor;
}

/**\brief Recebe as componentes X e Y de um vetor e retorna seu módulo */
float ModuloVetorBi(float vetor[2]) {
    float modulo;
    modulo = sqrt((vetor[0]*vetor[0]) + (vetor[1]*vetor[1]));
    return modulo;
}

/**\brief Recebe um vetor 2D e retorna a tangente do ângulo com sua horizontal*/
float TangenteVetorHorizontalBi(float vetor[2]) {
    return vetor[1]/vetor[0];
}

/**\brief Recebe um vetor 2D e retorna o ângulo de inclinação com a horizontal do vetor em graus*/
float AnguloHorizontalGrausBi(float vetor[2]) {
    return ArcoCossenoGraus(TangenteVetorHorizontalBi(vetor));
}

/**\brief Recebe um vetor 2D e retorna o ângulo de inclinação com a horizontal do vetor em radianos*/
float AnguloHorizontalRadianosBi(float vetor[2]) {
    return GrausParaRadianos(AnguloHorizontalGrausBi(vetor));
}

/**\brief Recebe dois vetores 2D e retorna: (caso !subtracao) a soma dos dois;
(caso subtracao) a subtracao do vetor A com o B */
VetorBi SomaESubtraiVetorBi(float vetorA[2], float vetorB[2], bool subtracao) {
    VetorBi vetor;
    if (!subtracao) {
        vetor.x = vetorA[0] + vetorB[0];
        vetor.y = vetorA[1] + vetorB[1];
        return vetor;
    }else{
        if (subtracao) {
            vetor.x = vetorA[0] + (-vetorB[0]);
            vetor.y = vetorA[1] + (-vetorB[1]);
            return vetor;
        }
    }
}

///Tridimensional

/**\brief Recebe o módulo e os ângulos theta e phi de um vetor tridimensional e o decompõe em componentes X, Y e Z */
VetorTri DecompoeVetorTri(float modulo, float theta, float phi) {
    VetorTri vetor;
    vetor.x = modulo*CossenoGraus(phi)*CossenoGraus(theta);
    vetor.y = modulo*CossenoGraus(phi)*SenoGraus(theta);
    vetor.z = modulo*SenoGraus(phi);
    return vetor;
}

/**\brief Recebe um vetor 3D e retorna seu módulo */
float ModuloVetorTri(float vetor[3]) {
    float modulo;
    modulo = sqrt(pow(vetor[0],2) + pow(vetor[1],2)+ pow(vetor[2],2));
    return modulo;
}

/**\brief Recebe dois vetores 3D e retorna o produto escalar entre eles */
float CalculoProdutoEscalar(float vetorA[3], float vetorB[3]) {
    float escalar = (vetorA[0]*vetorB[0]) + (vetorA[1]*vetorB[1]) + (vetorA[2] + vetorB[2]);
    return escalar;
}

/**\brief Recebe dois vetores 3D e retorna o produto vetorial do vetor A com o vetor B */
VetorTri CalculoProdutoVetorial(float vetorA[3], float vetorB[3]) {
    VetorTri vetorial;
    vetorial.x = vetorA[1]*vetorB[2] - vetorA[2]*vetorB[1];
    vetorial.y = vetorA[2]*vetorB[0] - vetorA[0]*vetorB[2];
    vetorial.z = vetorA[0]*vetorB[1] - vetorA[1]*vetorB[0];
    return vetorial;
}

/**\brief Recebe dois vetores 3D e retorna: (caso !subtracao) a soma dos dois;
(caso subtracao) a subtracao do vetor A com o B */
VetorTri SomaESubtraiVetorTri(float vetorA[3], float vetorB[3], bool subtracao) {
    VetorTri vetor;
    if (!subtracao) {
        vetor.x = vetorA[0] + vetorB[0];
        vetor.y = vetorA[1] + vetorB[1];
        vetor.z = vetorA[2] + vetorB[2];
        return vetor;
    }else{
        if (subtracao) {
            vetor.x = vetorA[0] + (-vetorB[0]);
            vetor.y = vetorA[1] + (-vetorB[1]);
            vetor.z = vetorA[2] + (-vetorB[2]);
            return vetor;
        }
    }
}

/**\brief Recebe dois vetores 3D e retorna o ângulo entre os dois no plano cartesiano */
float CalculoAnguloEntreDoisVetores(float vetorA[3], float vetorB[3]){
    return acos(vetorA[0]*vetorB[0] + vetorA[1]*vetorB[1] + vetorA[2]*vetorB[2]/sqrt(pow(vetorA[0],2)+pow(vetorA[1],2)+pow(vetorA[2],2))*sqrt(pow(vetorB[0],2)+pow(vetorB[1],2)+pow(vetorB[2],2)));
}

///CÁLCULO MATRICIAL

/**\brief Recebe duas matrizes 3x3 e retorna a soma das duas */
MATRIZ CalculoSomaMatrizes(float matrizA[3][3], float matrizB[3][3]) {
    MATRIZ soma;
    soma.matriz[0][0] = matrizA[0][0] + matrizB[0][0];
    soma.matriz[0][1] = matrizA[0][1] + matrizB[0][1];
    soma.matriz[0][2] = matrizA[0][2] + matrizB[0][2];
    soma.matriz[1][0] = matrizA[1][0] + matrizB[1][0];
    soma.matriz[1][1] = matrizA[1][1] + matrizB[1][1];
    soma.matriz[1][2] = matrizA[1][2] + matrizB[1][2];
    soma.matriz[2][0] = matrizA[2][0] + matrizB[2][0];
    soma.matriz[2][1] = matrizA[2][1] + matrizB[2][1];
    soma.matriz[2][2] = matrizA[2][2] + matrizB[2][2];
    return soma;
}

/**\brief Recebe uma matriz 3x3 e retorna sua transposta */
MATRIZ CalculoTranspostaMatriz(float matriz[3][3]){
    MATRIZ transposta;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposta.matriz[i][j] = matriz[j][i];
        }
    }
    return transposta;
}

/**\brief Recebe duas matrizes 3x3 e retorna o produto da matriz A com a matriz B */
MATRIZ CalculoProdutoMatrizes(float matrizA[3][3], float matrizB[3][3]){
    MATRIZ produto;
    produto.matriz[0][0] = (matrizA[0][0]*matrizB[0][0]) + (matrizA[0][1]*matrizB[1][0]) + (matrizA[0][2]*matrizB[2][0]);
    produto.matriz[0][1] = (matrizA[0][0]*matrizB[0][1]) + (matrizA[0][1]*matrizB[1][1]) + (matrizA[0][2]*matrizB[2][1]);
    produto.matriz[0][2] = (matrizA[0][0]*matrizB[0][2]) + (matrizA[0][1]*matrizB[1][2]) + (matrizA[0][2]*matrizB[2][2]);
    produto.matriz[1][0] = (matrizA[1][0]*matrizB[0][0]) + (matrizA[1][1]*matrizB[1][0]) + (matrizA[1][2]*matrizB[2][0]);
    produto.matriz[1][1] = (matrizA[1][0]*matrizB[0][1]) + (matrizA[1][1]*matrizB[1][1]) + (matrizA[1][2]*matrizB[2][1]);
    produto.matriz[1][2] = (matrizA[1][0]*matrizB[0][2]) + (matrizA[1][1]*matrizB[1][2]) + (matrizA[1][2]*matrizB[2][2]);
    produto.matriz[2][0] = (matrizA[2][0]*matrizB[0][0]) + (matrizA[2][1]*matrizB[1][0]) + (matrizA[2][2]*matrizB[2][0]);
    produto.matriz[2][1] = (matrizA[2][0]*matrizB[0][1]) + (matrizA[2][1]*matrizB[1][1]) + (matrizA[2][2]*matrizB[2][1]);
    produto.matriz[2][2] = (matrizA[2][0]*matrizB[0][2]) + (matrizA[2][1]*matrizB[1][2]) + (matrizA[2][2]*matrizB[2][2]);
    return produto;
}

/**\brief Recebe uma matriz 3x3 e retorna sua determinante */
float CalculoDeterminanteMatriz(float matriz[3][3]) {
    float positivo = (matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1]);
    float negativo = (matriz[2][0]*matriz[1][1]*matriz[0][2])+(matriz[2][1]*matriz[1][2]*matriz[0][0])+(matriz[2][2]*matriz[1][0]*matriz[0][1]);
    return positivo - negativo;
}

/**\brief Recebe uma matriz 3x3 e retorna sua inversa (A^-1)*/
MATRIZ CalculoMatrizInversa(float matriz[3][3]) {
    MATRIZ inversa;
    int valor = 0;
    float adjunta[3][3];
    float n = CalculoDeterminanteMatriz(matriz);
    if (n == 0) {
        abort();
    }else{
        if (n != 0) {
            adjunta[0][0] = (matriz[1][1]*matriz[2][2]) - (matriz[2][1]*matriz[1][2]);
            adjunta[0][1] = (matriz[1][0]*matriz[2][2]) - (matriz[2][0]*matriz[1][2]);
            adjunta[0][2] = (matriz[1][0]*matriz[2][1]) - (matriz[2][0]*matriz[1][1]);

            adjunta[1][0] = (matriz[0][1]*matriz[2][2]) - (matriz[2][1]*matriz[0][2]);
            adjunta[1][1] = (matriz[0][0]*matriz[2][2]) - (matriz[2][0]*matriz[0][2]);
            adjunta[1][2] = (matriz[0][0]*matriz[2][1]) - (matriz[2][0]*matriz[0][1]);

            adjunta[2][0] = (matriz[0][1]*matriz[1][2]) - (matriz[1][1]*matriz[0][2]);
            adjunta[2][1] = (matriz[0][0]*matriz[1][2]) - (matriz[1][0]*matriz[0][2]);
            adjunta[2][2] = (matriz[0][0]*matriz[1][1]) - (matriz[1][0]*matriz[0][1]);

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    inversa.matriz[i][j] = (adjunta[i][j]/n);
                }
            }
        }
    }
 }
