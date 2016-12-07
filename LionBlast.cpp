#include "LionBlast.h" ///Biblioteca do jogo

/** Recebe X desejado e limpa o Gauge */
int LimpaGauge(int x) {
    GotoXY(x, 43);
    cout << "                              ";
}

/** Função do vento */
VetorBi Vento() {
    srand(time(NULL));
    VetorBi v;
    int n = rand()%7;
    v.x = rand()%10 + 1; ///módulo
    v.x = v.x/100;
    if (n == 0) {
        v.y = 0; ///ângulo
    }else{
        if (n == 1) {
            v.y = 45;
        }else{
            if (n == 2) {
                v.y = 90;
            }else{
                if (n == 3) {
                    v.y = 135;
                }else{
                    if (n == 4) {
                        v.y = 180;
                    }else{
                        if (n == 5) {
                            v.y = 225;
                        }else{
                            if (n == 6) {
                                v.y = 270;
                            }else{
                                if (n == 7) {
                                    v.y = 315;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return v;
}

int main()

{
    srand(time(NULL));

    Canhao A; ///Canhão do jogador 1 (spawna do lado esquerdo)
    Canhao B; ///Canhão do jogador 2 (spawna do lado direito)

    VetorBi sA; ///Posição XY do jogador 1 no mapa
    VetorBi sB; ///Posição XY do jogador 2 no mapa
    float vA = 0; ///Velocidade do TIRO do jogador 1
    float vB = 0; ///Velocidade do TIRO do jogador 2
    char start; ///Detecta a tecla para iniciar o gauge
    int g = 0; ///Contador do gauge
    int angA = 0; ///Ângulo A
    int angB = 0; ///Ângulo B
    char teclaA; ///Tecla para ativar o Gauge do canhão A
    char teclaB; ///Tecla para ativar o Gauge do canhão B
    VetorBi vento; ///Vetor vento (armazena módulo e ângulo)
    QUADRI tanqueA; ///"Box" do tanque A
    QUADRI tanqueB; ///"Box" do tanque B
    bool win = false; ///True = adiciona ao placar e torna o win2 true
    bool win2 = false; ///True = troca de fase
    int scoreA = 0; ///placar do jogador A
    int scoreB = 0; ///placar do jogador B
    int novo;
    char menu;
    char menu2;
    char round[45][124];

    ConsoleSize(40,36); ///tamanho da tela
    srand(time(NULL));

    /** Menu inicial */
    do {
    system("cls");
    cout << "LIONBLAST" << endl;
    cout << "Aperte N para comecar um novo jogo" << endl;
    cout << "Aperte E para sair" << endl;
    cout << "Aperte A para ver os controles" << endl;
    cin >> menu;
    }while(menu != 'n' && menu != 'a' && menu != 'N' && menu != 'A' && menu != 'e' && menu != 'E');

    if (menu == 'e' || menu == 'E') {
        return 0;
    }

    else if (menu == 'a' || menu == 'A') {
        cout << "Setinha para cima: Aumenta o ângulo" << endl;
        cout << "Setinha para baixo: Diminui o ângulo" << endl;
        cout << "Barra de espaço: Inicia o contador de velocidade" << endl;
        cout << "Qualquer botão para parar o contador" << endl;
    }

    else if (menu == 'n' || menu == 'N') {
    do {
    ConsoleSize(124,44);

    /** Loop do jogo */
    while (scoreA < 5 && scoreB < 5) {
    win = false;
    win2 = false;
    system("cls");

    novo = rand()%3+1;

    /** Escolhe um mapa aleatoriamente e imprime ele na tela */

    if (novo == 1) {
        for (int j = 0; j < 45; j++) {
            for (int i = 0; i < 124; i++) {
                 round[j][i] = mapa[j][i];
                 cout << round[j][i];
            }
        }
    }else{
        if (novo == 2) {
            for (int j = 0; j < 45; j++) {
                for (int i = 0; i < 124; i++) {
                    round[j][i] = mapa2[j][i];
                    cout << round[j][i];
                }
            }
        }else{
            if (novo == 3) {
                for (int j = 0; j < 45; j++) {
                    for (int i = 0; i < 124; i++) {
                        round[j][i] = mapa3[j][i];
                        cout << round[j][i];
                    }
                }
            }
        }
    }

    GotoXY(0,0);
    cout << scoreA;
    GotoXY(122,0);
    cout << scoreB;

    /** Inicia as posições dos jogadores no campo */
    A.Inicia(0, 57, "tanque.txt", round);
    B.Inicia(67, 57, "tanque2.txt", round);

    sA.x = A.S.x; ///Importação da coordenada X da posição do jogador 1
    sA.y = A.S.y-3; ///Importação da coordenada Y da posição do jogador 1
    sB.x = B.S.x-3; ///Importação da coordenada X da posição do jogador 2
    sB.y = B.S.y-3; ///Importação da coordenada Y da posição do jogador 2


    tanqueA.x = sA.x-3; /// Lado esquerdo do tanque A
    tanqueA.y = sA.y-1; /// Lado superior do tanque A
    tanqueA.l = 3; /// Lado direito do tanque A
    tanqueA.h = 2; /// Lado inferior do tanque A
    tanqueB.x = sB.x; /// Lado esquerdo do tanque B
    tanqueB.y = sB.y-1; /// Lado superior do tanque B
    tanqueB.l = 3; /// Lado direito do tanque B
    tanqueB.h = 2; /// Lado inferior do tanque B

    /** Loop da fase */
    while (!win2) {
        win = false; ///zera o booleano de vitória
        vento = Vento();
        GotoXY(50, 0);
        cout << "                                  ";
        GotoXY(50, 0);
        cout << "Vento a " << vento.x*100 << "km/h ";
        if (vento.y == 0) {
            cout << "Para o leste";
    }else{
        if (vento.y == 45) {
            cout << "Para o sudeste";
        }else{
            if (vento.y == 90) {
                cout << "Para o sul";
            }else{
                if (vento.y == 135) {
                    cout << "Para o sudoeste";
                }else{
                    if (vento.y == 180) {
                        cout << "Para o oeste";
                    }else{
                        if (vento.y == 225) {
                            cout << "Para o noroeste";
                        }else{
                            if (vento.y == 270) {
                                cout << "Para o norte";
                            }else{
                                if (vento.y == 315) {
                                    cout << "Para o nordeste";
                                }
                            }
                        }
                    }
                }
            }
        }
    }

        angA = 0; ///zera o ângulo
        GotoXY(50, 1); ///Imprime o ângulo na tela
        cout << angA;
        teclaA = getch();
        angA = A.DefineAngulo(start);
        vA = A.Gauge(1, false);
        win = A.DisparaBala(vA, angA, sA, false, vento, tanqueB);
        if (win) {
            scoreA++;
            win2 = true;
            break;
        }
        LimpaGauge(1);

        angB = 0;
        GotoXY(50, 1);
        cout << angB;
        teclaB = getch();
        angB = B.DefineAngulo(start);
        vB = B.Gauge(122, true);
        win = B.DisparaBala(vB, angB, sB, true, vento, tanqueA);
        if (win) {
            scoreB++;
            win2 = true;
            break;
        }
        LimpaGauge(93);
    }
    }
    system("cls");

    if (scoreA == 5 && scoreB < 5) {
        cout << "Vitória do jogador 1" << endl;
    }else{
        if (scoreB == 5 && scoreA < 5) {
            cout << "Vitória do jogador 2" << endl;
        }
    }
    cout << "Pressione S para jogar de novo" << endl;
    cin >> menu2;
    }while (menu2 != 'n' && menu2 != 'N');
    }

}
