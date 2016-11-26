#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <wincon.h>
#include <winuser.h>
#include <windef.h>


#ifndef KENTECA_H_INCLUDED
#define KENTECA_H_INCLUDED



 _CONSOLE_SCREEN_BUFFER_INFO console;


/* Flechas do teclado. */

#define Y_UP    72 ///CIMA
#define Y_DOWN  80 ///BAIXO
#define Y_LEFT  75 ///ESQUERDA
#define Y_RIGHT 77 ///DIREITA

/* Virtual Key. */

#define VK_ESC VK_ESCAPE
#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A
#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
#define VK_6 0x36
#define VK_7 0x37
#define VK_8 0x38
#define VK_9 0x39


#define PI 3.1415
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

using namespace std;


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

void Limpo()
{
    system("cls");
}

 int somenores (int x){ // SOMA DE MENORES
    if (x <= 1){
        return x;
    }else{
    return x + somenores(x-1);
    }
 }

  /// NUMEROS PRIMOS
 bool primos(int n, int c){ // O a do c deve ser o a de n-1
    if(c==1||n==1){
        return true;
    }else{
        if(n%c==0){
            return false;
        }else{
            return primos(n, c-1);
        }
    }
}

 int fatorial (int x){
    if (x  <= 1){
        return x;
    }else{
    return x * fatorial(x-1);
    }
 }

  int fibo(int t, int c, int b, int a){ /// FIBONATTI

  c; // proximo
  b; // atual
  a; // anterior

 c = a+b;

    if (t == 0){
    return a;
    }else{

    return fibo(t-1, c, b = c, a = b);
    }
 }

 int pa(int y, int x, int t) /// PROGRESSAO ARITIMERICA
{
 int a = y + x;
 if (t <=1) {
     return a;
}else{
 return pa(a,x,t-1);

}
}

 /** \brief retorna  */
 int pg(int y, int x, int t)
{
 int a = y * x;
 if (t <=1) {
     return a;
}else{
 return pg(a,x,t-1);

}
}

 /** \brief retorna o valor do numero elevedo a N */
 int Poten(int y, int x) // numero, potencia
{

  if (x <=1) {
     return y;
}else{
 return y * Poten(y,x-1);

}
}

///=====================================================================================\\\
/**
///* @file KenTeca.h
///* @author Thiago Ken Toyomoto <T.K.Toyomoto@gmail.com>
///* \brief Biblioteca para uso pessoal.
///*/


/* Protótipos das funções. */

void CorFonte(DOS_COLORS iColor);
void CorFundo(DOS_COLORS iColor);
void ResetCor();

void ConsoleSize(int x, int y);
void GotoXY(unsigned x, unsigned y);
void FullScreen();

void LimparTela();
void ApagarLinha(int yInicial, int yFinal);
void LimparArea(int xInicial, int yInicial, int xFinal, int yFinal);

void TituloDoPrograma(string nome);
void VerificarArquivo(string nome);

bool TeclaPressionada(int key);
void DesligarCursor(bool off);

long NumeroRandom(long x, long y);
string GerarLetraRandomico(int qtd);
string GerarLetraRandomicoMaiuscula(int qtd);

string NumeroToString(int valor);
string NumeroToString(float valor);
string NumeroToString(double valor);

/** \brief Reseta as cores da fonte e do fundo.
* @see CorFonte
* @see CorFundo
*/
void ResetCor() {
    CorFonte(CINZA_CLARO);
    CorFundo(PRETO);
}


/** Muda o tamanho do console.*/
void ConsoleSize(int x, int y) {
    string str = "MODE con cols=";
    str += NumeroToString(x);
    str += " lines=";
    str += NumeroToString(y);
    system(str.c_str());
}

/** Posiciona o cursor nas coordenadas passadas no parâmetro.*/
void GotoXY( unsigned x, unsigned y ) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}


/** \brief Limpa a tela.
* @see LimparArea
* @see ApagarLinha
*/
void LimparTela() {
    system("cls");
}
/** \brief Apaga a(s) linha(s) passada(s) pelo parâmetro.
* @see LimparArea
* @see LimparTela
*/
void ApagarLinha(int yInicial, int yFinal) {
    for(int y = yInicial; y <= yFinal; ++y) {
        GotoXY(0,y);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo); //pega informacoes do output
        int tamLinha = consoleInfo.dwSize.X; //grava o tamanho da linha
        for(int x = 0; x < tamLinha; x++) //Substitui os caracteres da linha por um espaçamento
            cout << ' ';
    }
}
/** \brief Limpa a área passada no parâmetro.
* @see ApagarLinha
* @see LimparTela
*/
void LimparArea(int xInicial, int yInicial, int xFinal, int yFinal) {
    for(int x = xInicial; x <= xFinal; ++x) {
        for(int y = yInicial; y <= yFinal; ++y) {
            GotoXY(x,y);
            cout << " ";
        }
    }
}


/** \brief Muda o títulç do programa para o nome passado no parâmetro.*/
void TituloDoPrograma(string nome) {
    string str = "title ";
    str += nome;
    system(str.c_str());
}

/** \brief Verifica se o arquivo existe. Se ele não existir o programa não prossegue e é fechado.
* @see ImprimirArquivo
*/
void VerificarArquivo(string nome) {
    fstream arquivo;
    arquivo.open(nome.c_str(), ios::in);
    if(!arquivo) {
        cout << " Erro ao abrir o arquivo \"" << nome.c_str() << "\"." << std::endl;
        arquivo.close();
        _getch();
        exit(-1);
    }
    arquivo.close();
}

/** \brief Verifica e retorna se a tecla passada no parâmetro foi pressionada.*/
bool TeclaPressionada(int key) {
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}
/** \brief Desliga o cursor se passado como parâmetro TRUE.*/
void DesligarCursor(bool off = false) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(output, &cursor);
    cursor.bVisible = !off;
    SetConsoleCursorInfo(output, &cursor);
}


/** \brief Retorna um número aleatório entre o intervalo passado no parâmetro.*/
long NumeroRandom(long x, long y) {
    srand(time(0));
    long number = x + (rand()%y);
    return number;
}
/** \brief Gera uma quantidade de letras aleatórias e retorna-as.
* @see GerarLetraRandomicoMaiuscula
*/
string GerarLetraRandomico(int qtd) {
    string str = "";
    for(int a = 0; a < qtd; a++) {
        str += (NumeroRandom(0,25) + 97);
    }
    return str;
}
/** \brief Gera uma quantidade de letras maiúsculas aleatórias e retorna-as.
* @see GerarLetraRandomico
*/
string GerarLetraRandomicoMaiuscula(int qtd) {
    string str = "";
    for(int a = 0; a < qtd; a++) {
        str += (NumeroRandom(0,25) + 65);
    }
    return str;
}
/** \brief Escolhe uma palavra aleatória dentro de um arquivo.
*/
string PalavraRandomica(string nomeArquivo){
    int contadorPalavras = 0;
    string aux, palavra;
    fstream arquivo;
    arquivo.open(nomeArquivo.c_str(), ios::in);
    if(!arquivo){
        cout << " Erro ao abrir o arquivo \"" << nomeArquivo.c_str() << "\"." << std::endl;
        arquivo.close();
        _getch();
        exit(-1);
    }
    while(!arquivo.eof()){
        getline(arquivo, aux);
        contadorPalavras++;
    }
    arquivo.close();
    if(contadorPalavras == 0){
        cout << " Arquivo vazio." << endl;
        _getch();
        exit(-1);
    }else{
        arquivo.open(nomeArquivo.c_str(), ios::in);
        int numero = NumeroRandom(1,contadorPalavras);
        for(int a = 0; a < numero; a++){
            getline(arquivo,palavra);
        }
        arquivo.close();
    }
    return palavra;
}


/** \brief Converte qualquer valor int para string.*/
string NumeroToString(int valor = 0) {
    stringstream out;
    out << valor;
    return out.str();
}

/** \brief Converte qualquer valor float para string.*/
string NumeroToString(float valor = 0) {
    stringstream out;
    out << valor;
    return out.str();
}

/** \brief Converte qualquer valor double para string.*/
string NumeroToString(double valor = 0) {
    stringstream out;
    out << valor;
    return out.str();
}


_CONSOLE_SCREEN_BUFFER_INFO GetConsoleSize(){
    _CONSOLE_SCREEN_BUFFER_INFO console;
    return console;
}

void ImprimirArquivo(string nome, int x, int y) {
    fstream arquivo;
    string linha, aux;
    arquivo.open(nome.c_str(), ios::in);
    if(arquivo){
        while(!arquivo.eof()) {
            getline(arquivo,linha);
            GotoXY(x,y++);
            cout << linha;
        }
    } else{
        cout << " Erro ao abrir o arquivo \"" << nome.c_str() << "\"." << std::endl;
        arquivo.close();
        _getch();
        exit(-1);
    }
    arquivo.close();
}

#endif // KENTECA_H_INCLUDED

