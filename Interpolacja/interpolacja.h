#include <iostream>
#include <math.h>
#include <exception>

#pragma once

#define PI 3.14159265358979323846

/*
Szacowanie warto�ci punktu 'x' w r�wnoodleg�ym wybieraniu punkt�w na zadanym przedziale

int n - wielko�� zbioru danych
int i - parametr iteracyjny
float a - pocz�tek przedzia�u
float b - koniec przedzia�u
*/
float xp(int n, int i, float a, float b);

/*
Wybieranie 'n' r�wnoodleg�ych punkt�w 'x' na zadanym przedziale

int n - liczba w�z��w
float a - pocz�tek przedzia�u
float b - koniec przedzia�u
*/
float *rownoodlegleX(int n, float a, float b);

/*
Dobieranie 'n' optymalnie odleg�ych punkt�w 'x' na zadanym przedziale

int n - liczba w�z��w
float a - pocz�tek przedzia�u
float b - koniec przedzia�u
*/
float *optymalneX(int n, float a, float b);

/*
Obliczanie warto�ci omegi

int i - warto�� iteracyjna
float xp - czynnik iloczynu
float *x - lista czynnik�w do iloczynu
*/
float omega(int i, float xp, float *x);

/*


int n - liczba punkt�w
float *x - punkty
float *f - warto�ci funkcji w '*x' punktach
*/
float iloraz_roznicowy(int n, float *x, float *f);

/*
Obliczanie warto�ci funkcji interpolowanej f(x) w '*x' punktach

int n - liczba punkt�w
float *x - punkty
*/
float *wypelnij_f(int n, float *x);

/*
Obliczanie warto�ci funkcji interpolowanej f(x) w '*xp' punktach 

int np - liczba punkt�w
float *xp - punkty
*/
float *wypelnij_fp(int np, float *xp);

/* */
float *wypelnij_L();