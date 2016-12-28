#include <iostream>
#include <math.h>
#include <exception>
#include "interpolacja.h"


using namespace std;

// Szacowanie wartoœci punktu 'x' w równoodleg³ym wybieraniu punktów na zadanym przedziale
float xp(int n, int i, float a, float b)
{
	return a + i * ((b - a) / n);
}

// Wybieranie 'n' równoodleg³ych punktów 'x' na zadanym przedziale
float *rownoodlegleX(int n, float a, float b)
{
	if (a < b) {
		float *tab = new float[n];

		for (int i = 0; i <= n; i++)
		{
			tab[i] = xp(n, i, a, b);
		}
		return tab;
	}
	else {
		throw exception("Insufficient range");
	}
}

// Dobieranie 'n' optymalnie odleg³ych punktów 'x' na zadanym przedziale
float *optymalneX(int n, float a, float b)
{
	if (a < b) {
		float *tab = new float[n];
		float temp1, temp2;

		for (int i = 0; i <= n; i++)
		{
			temp1 = (2 * i) + 1;
			temp2 = (2 * n) + 2;
			temp1 /= temp2;
			temp1 *= PI;
			tab[i] = 0.5*(a + b) - (0.5*(b - a))*(cos(temp1));
		}
		return tab;
	}
	else {
		throw exception("Insufficient range");
	}
}

// Obliczanie wartoœci omegi
float omega(int i, float xp, float *x)
{
	if ((i > 0) && (x != NULL)) {
		float iloczyn = 1;
		for (int j = 0; j < i - 1; j++)
		{
			iloczyn *= (xp - x[j]);
		}
		return iloczyn;
	}
	else
	{
		// Jak coœ posz³o nie tak z parametrami, wyrzuæ wyj¹tek z nazw¹ funkcji.
		throw exception(__func__);
	}
}

//
float iloraz_roznicowy(int n, float *x, float *f)
{
	if ((n > 0) && (x != NULL) && (f != NULL)) {
		float suma = 0, iloczyn = 1;
		for (int i = 0; i < n; i++) // suma
		{
			for (int j = 0; (j < n) && (j != i); j++)
			{
				iloczyn *= (x[i] - x[j]);
			}
			suma += f[i] / iloczyn;
		}
		return suma;
	}
	else
	{
		throw exception(__func__);
	}
}

// Obliczanie wartoœci funkcji 'f(x)' w '*x' punktach
float *wypelnij_f(int n, float *x)
{
	if ((n > 0) && (x != NULL)) {
		float *f = new float[n];

		for (int i = 0; i < n; i++)
		{
			f[i] = abs(sin(x[i]));
		}
		return f;
	}
	else if (x == NULL) {
		throw exception("NullPointerException: parameter float *x");
	}
	else if (n <= 0) {
		throw exception("Insufficient amount of nodes: n <= 0");
	}
	else {
		throw exception(__func__);
	}
}

float *wypelnij_fp(int np, float *xp)
{
	if ((np > 0) && (xp != NULL)) {
		float *fp = new float[np];

		for (int i = 0; i < np; i++)
		{
			fp[i] = abs(sin(xp[i]));
		}
		return fp;
	}
	else if (xp == NULL) {
		throw exception("NullPointerException: parameter float *xp");
	}
	else if (np <= 0) {
		throw exception("Insufficient amount of nodes: np <= 0");
	}
	else {
		throw exception(__func__);
	}
}

float *wypelnij_L()
{
	return new float(PI);
}