#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <windows.h>
#include <vector>
using namespace std;
#define PRETO BLACK
#define AZUL BLUE
#define VERDE GREEN
#define CIANO CYAN
#define VERMELHO RED
#define MAGENTA MAGENTA
#define MARROM BROWN
#define CINZA_CLARO LIGHT_GRAY
#define CINZA_ESCURO DARK_GRAY
#define AZUL_CLARO LIGHT_BLUE
#define VERDE_CLARO LIGHT_GREEN
#define CIANO_CLARO LIGHT_CYAN
#define VERMELHO_CLARO LIGHT_RED
#define MAGENTA_CLARO LIGHT_MAGENTA
#define AMARELO YELLOW
#define BRANCO WHITE
#define PI 3.1415
#define C 299792.458 ///velocidade da luz

/**\brief Recebe uma posição x e uma posição y e seta o cursor na matriz da tela */
void gotoXY (int x, int y) {
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
    }

/**\brief Gera uma letra aleatória do alfabeto (Caixa alta) */
char GeraLetra() {
char letra;
srand(time(NULL));
letra = 65+rand()%25;
return letra;
}

/**\brief Recebe um número inicial e um número final e retorna um número aleatório dentro desse intervalo */
int GeraNumero(int i, int f) {
int n;
srand(time(NULL));
n = i+rand()%f;
return n;
}

struct DATA {
    int dia;
    int mes;
    int ano;
};

/**\brief Recebe uma data e retorna: false (se a data for inválida) ou true (se a data for válida) */
bool VerificaData (DATA data) {
    if (data.mes == 2 && data.dia > 29 && data.ano % 4 == 0 && data.ano % 100 != 0) {
        return false;
        }else{
            if (data.mes == 2 && data.mes > 28) {
                return false;
            }else{
            if ((data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12) && data.dia > 31) {
                return false;
            }else{
                if ((data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) && data.dia > 30) {
                    return false;
                }else{
                    if (data.mes <= 0 || data.mes > 12) {
                        return false;
                    }else{
                        if (data.dia <= 0 || data.ano < 1900) {
                            return false;
                        }else{
                            return true;
                        }
                    }
                }
            }
        }
    }
}

enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};

void FullScreen() {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_SPACE, 0x39, 0, 0);
    keybd_event(0x58,0,0,0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_SPACE, 0x39, KEYEVENTF_KEYUP, 0);
    keybd_event(0x58,0,KEYEVENTF_KEYUP,0);
}

void CorFonte(DOS_COLORS iColor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void CorFundo(DOS_COLORS iColor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}


void FPRETO() /// FUNDO
{
    system("COLOR 0");
}

void FAZUL() /// FUNDO
{
    system("COLOR 1");
}

void FVERDE() /// FUNDO
{
    system("COLOR 2");
}

void FAQUA() /// FUNDO
{
    system("COLOR 3");
}

void FVERMELHO() /// FUNDO
{
    system("COLOR 4");
}

void FROXO() /// FUNDO
{
    system("COLOR 5");
}

void FAMARELO() /// FUNDO
{
    system("COLOR 6");
}

void FBRANCO() /// FUNDO
{
    system("COLOR 7");
}

void FCINZA() /// FUNDO
{
    system("COLOR 8");
}

void LAZUL() /// FUNDO
{
    system("COLOR 9");
}

void LVERDE()
{
    system("COLOR A");
}

void LAQUA()
{
    system("COLOR B");
}
void LVERMELHO()
{
    system("COLOR C");
}
void LROXO()
{
    system("COLOR D");
}
void LAMARELO()
{
    system("COLOR E");
}
void LBRANCO()
{
    system("COLOR F");
}

/**\brief Recebe o número do termo da série de Fibonacci e retorna seu valor */
int Fibonacci(int termo, int prox, int n, int ant) {
    prox=ant+n;
    if (termo == 0) {
        return ant;
    }else{
        return Fibonacci(termo-1, prox=n+ant, n=prox, ant=n);
    }
}

/**\brief Recebe o número do termo de uma progressão aritmética e o número de progressão e retorna o valor do termo */
int Prog_ar (int n_entrada, int n_prog, int termo, int controle) {
    if (controle == termo) {
        return n_entrada;
        }else{
            return Prog_ar(n_entrada*n_prog, n_prog, termo, controle+1);
        }
}

/** \brief Converte qualquer valor int para string.*/
string NumeroToString(int valor = 0) {
    stringstream out;
    out << valor;
    return out.str();
}

/** Muda o tamanho do console.*/
void ConsoleSize(int x, int y) {
    string str = "MODE con cols=";
    str += NumeroToString(x);
    str += " lines=";
    str += NumeroToString(y);
    system(str.c_str());
}


