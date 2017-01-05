#include <iostream>
#include <math.h>
#include <exception>

#pragma once

// Nie dzia³a³y nam 'w³¹czniki' math.h wiêc skopiowaliœmy definicjê.
#define PI 3.14159265358979323846

/*
Szacowanie wartoœci punktu 'x' w równoodleg³ym wybieraniu punktów na zadanym przedziale

int &n - wielkoœæ zbioru danych
int &i - parametr iteracyjny
float &a - pocz¹tek przedzia³u
float &b - koniec przedzia³u
*/
float r_xp(int &n, int &i, float &a, float &b);

/*
Wybieranie 'n' równoodleg³ych punktów 'x' na zadanym przedziale

int &n - liczba wêz³ów
float &a - pocz¹tek przedzia³u
float &b - koniec przedzia³u
*/
float *rownoodlegleX(int &n, float &a, float &b);

/*
Dobieranie 'n' optymalnie odleg³ych punktów 'x' na zadanym przedziale

int &n - liczba wêz³ów
float &a - pocz¹tek przedzia³u
float b - koniec przedzia³u
*/
float *optymalneX(int &n, float &a, float &b);

/*
Obliczanie wartoœci omegi

int &i - wartoœæ iteracyjna
float &xp - czynnik iloczynu
float *x - lista czynników do iloczynu
*/
float omega(int &i, float *x, float &xp);

/*
Funkcja obliczaj¹ca wartoœæ parametru 'a' we wzorze newtona

int &n - liczba punktów
float *x - punkty
float *f - wartoœci funkcji w '*x' punktach
*/
float iloraz_roznicowy(int &n, float *x, float *f);

/*
Obliczanie wartoœci funkcji interpolowanej f(x) w punktach '*x'

int &n - liczba punktów
float *x - punkty
*/
float *wypelnij_f(int &n, float *x);

/*
Funkcja obliczaj¹ca wartoœæ L(x) w danym punkcie

int &n - liczba punktów
int &np - liczba punktów
float *x - punkty
float &xp - wybrany punkt
float *f - wartoœci funkcji interpolowanej
*/
float oblicz_L(int &n, float *x, float &xp, float *f);

/*
Funkcja obliczaj¹ca wartoœci ze wzoru Newtona

int &n - liczba punktów
int &np - liczba punktów
float *x - punkty
float *xp - punkty
float *f - wartoœci funkcji interpolowanej
*/
float *wypelnij_L( int &n, int &np, float *x, float *xp, float *f );

/*
Funkcja pobiera dane z konsoli

float &a - poczatek przedzialu
float &b - koniec przedzialu
int &n - ilosc weslow interpolacji
char &metoda_uruchamiania - sposób dobierania wêz³ów (optymalny lub równoodleg³y)
*/
void pobieranie_danych(float &a, float &b, int &n, char &metoda_uruchamiania);

/*
Funkcja zapisuje wyniki operacji do pliku

string fn - nazwa pliku
int &n - liczba punktów
int &np - liczba punktów
float *x - punkty
float *f - wartosci dla x
float *xp - punkty
float *fp - wartoœci funkcji interpolowanej
float &a - pocz¹tek przedzia³u
float &b - koniec przedzia³u
*/
void zapisz_wyniki(char *fn, int &n, int &np, float *x, float *f, float *xp, float *fp, float *L, float &a, float &b);