#include <iostream>
#include <math.h>
#include <exception>
#include "interpolacja.h"

using namespace std;

// Szacowanie warto�ci punktu 'x' w r�wnoodleg�ym wybieraniu punkt�w na zadanym przedziale
float xp(int n, int i, float a, float b)
{
	return a + i * ((b - a) / n);
}

// Wybieranie 'n' r�wnoodleg�ych punkt�w 'x' na zadanym przedziale
float *rownoodlegleX(int n, float a, float b)
{
	if ((a < b) && (n > 0)) {
		float *tab = new float[n];

		for (int i = 0; i <= n; i++)
		{
			tab[i] = xp(n, i, a, b);
		}
		return tab;
	}
	else {
		string exc;
		if (n <= 0) {
			exc = "InsufficientNodesAmountException: n <= 0; at ";
		}
		else if (a >= b) {
			exc = "InsufficientRangeException: parameter float a <= float b; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}

// Dobieranie 'n' optymalnie odleg�ych punkt�w 'x' na zadanym przedziale
float *optymalneX(int n, float a, float b)
{
	if ((a < b) && (n > 0)) {
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
		string exc;
		if (n <= 0) {
			exc = "InsufficientNodesAmountException: n <= 0; at ";
		}
		else if (a >= b) {
			exc = "InsufficientRangeException: parameter float a <= float b; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}

// Obliczanie warto�ci omegi
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
	else {
		string exc;
		if (i <= 0) {
			exc = "InsufficientIterationValueException: i <= 0; at ";
		}
		else if (x == NULL) {
			exc = "NullPointerException: parameter float *x; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}

// Funkcja obliczaj�ca warto�� parametru 'a' we wzorze newtona
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
	else {
		string exc;
		if (n <= 0) {
			exc = "InsufficientNodesAmountException: n <= 0; at ";
		}
		else if (x == NULL) {
			exc = "NullPointerException: parameter float *x; at ";
		}
		else if (f == NULL) {
			exc = "NullPointerException: parameter float *xp; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}

// Obliczanie warto�ci funkcji 'f(x)' w punktach '*x'
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
	else {
		string exc;
		if (n <= 0) {
			exc = "InsufficientNodesAmountException: n <= 0; at ";
		}
		else if (x == NULL) {
			exc = "NullPointerException: parameter float *x; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}

// Obliczanie warto�ci funkcji 'f(x)' w punktach '*xp'
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
	else {
		string exc;
		if (np <= 0) {
			exc = "InsufficientNodesAmountException: np <= 0; at ";
		}
		else if (xp == NULL) {
			exc = "NullPointerException: parameter float *xp; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}


// Funkcja obliczaj�ca warto�ci ze wzoru Newtona
float *wypelnij_L(int n, int np, float *x, float *xp)
{
	if ((n > 0) && (np > 0) && (x != NULL) && (xp != NULL) ){
		float *L = new float[n];

		for (int i = 0; i < n; i++)
		{
			L[i] = abs(sin(L[i]));
		}
		return L;
	}
	else {
		string exc;
		if (n <= 0) {
			exc = "InsufficientNodesAmountException: n <= 0; at ";
		}
		else if (np <= 0) {
			exc = "InsufficientNodesAmountException: np <= 0; at ";
		}
		else if (x == NULL) {
			exc = "NullPointerException: parameter float *x; at ";
		}
		else if (xp == NULL) {
			exc = "NullPointerException: parameter float *xp; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}