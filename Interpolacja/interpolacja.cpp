#include <iostream>
#include <fstream>
#include <math.h>
#include <exception>
#include "interpolacja.h"

using namespace std;

// Szacowanie warto�ci punktu 'x' w r�wnoodleg�ym wybieraniu punkt�w na zadanym przedziale
float r_xp(int &n, int &i, float &a, float &b)
{
	return a + i * ((b - a) / n);
}

// Wybieranie 'n' r�wnoodleg�ych punkt�w 'x' na zadanym przedziale
float *rownoodlegleX(int &n, float &a, float &b)
{
	if ((a < b) && (n > 0)) {
		float *tab = new float[n+1];

		for (int i = 0; i <= n; i++)
		{
			tab[i] = r_xp(n, i, a, b);
		}
		return tab;
	}
	else {
		string exc;
		if (n <= 0) {
			exc = "InsufficientNodesAmountException: n <= 0; at ";
		}
		else if (a >= b) {
			exc = "InsufficientRangeException: parameter float &a <= float &b; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}

// Dobieranie 'n' optymalnie odleg�ych punkt�w 'x' na zadanym przedziale
float *optymalneX(int &n, float &a, float &b)
{
	if ((a < b) && (n > 0)) {
		float *tab = new float[n+1];
		float temp1, temp2;

		for (int i = 0; i <= n; i++)
		{ // Ta cz�� by�a zbyt ci�ka dla programu i nale�a�o j� rozbi� na zmienne pomocniczne
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
			exc = "InsufficientRangeException: parameter float &a <= float &b; at ";
		}
		else {
			exc = "GeneralException; at ";
		}
		throw exception(exc.append(__func__).c_str());
	}
}

// Obliczanie warto�ci omegi
float omega(int &i, float *x, float &xp)
{
	if ((i > 0) && (x != NULL)) {
		float iloczyn = 1;

		for (int j = 0; j <= i - 1; j++)
		{
			iloczyn *= xp - x[j];        //omega od x czyli dla 1 z tych 150
		}
		return iloczyn;
	}
	else if (i == 0) {
		return 1; // wynika to z definicji wielomianu czynnikowego
	}
	else {
		string exc;
		if (i < 0) {
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
float iloraz_roznicowy(int &n, float *x, float *f)
{
	if ((n >= 0) && (x != NULL) && (f != NULL)) {
		if (n == 0)
			return f[0]; // iloraz 0 rzedzu oparty na punkcie xi ma wartosc funkci w tym punkcie

		float suma = 0, iloczyn = 1;

		for (int i = 0; i <= n; i++) 
		{
			for (int j = 0; j <= n; j++)
			{
				if (j != i)
					iloczyn *= (x[i] - x[j]);
			}
			suma += f[i] / iloczyn;
			iloczyn = 1;
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
float *wypelnij_f(int &n, float *x)
{
	if ((n > 0) && (x != NULL)) {
		float *f = new float[n];

		for (int i = 0; i <= n; i++)
		{
			f[i] = abs(sin(x[i])); // f(x) = |sin(X)|
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
} // TODO: zrobi� to na wska�nikach do funkcji

// Funkcja obliczaj�ca warto�� L(x) w danym punkcie
float oblicz_L(int &n, float *x, float &xp, float *f)
{
	if ((n > 0) && (x != NULL)) {
		float temp = 0, temp1, temp2;

		for (int j = 0; j <= n; j++)        //ilosc wezlow od 2
		{
			temp1 = iloraz_roznicowy(j, x, f);
			temp2 = omega(j, x, xp);
			temp += temp1 * temp2;        //a i omega s� tego samego stopnia
		}
		return temp;
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

// Funkcja obliczaj�ca warto�ci ze wzoru Newtona
float *wypelnij_L(int &n, int &np, float *x, float *xp, float *f)
{
    if ((n > 0) && (np > 0) && (x != NULL) && (xp != NULL) ){
        float *L = new float[np];    //ta tablica ma miec 150 elementow bo to sa wartosci dla xp
        float temp = 0, temp1, temp2;

        for (int i = 0; i < np; i++) {
			// Obliczanie kolejnych warto�ci L(xp)
            L[i] = oblicz_L(n, x, xp[i], f);
			temp = 0;
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

// Funkcja pobiera dane z konsoli
void pobieranie_danych(float &a, float &b, int &n, char &metoda_uruchamiania)
{
	cout << "podaj pocz�tek przedzia�u" << endl;
	cin >> a;
	cout << "podaj koniec przedzia�u" << endl;
	cin >> b;
	cout << "podaj ilosc wezlow" << endl;
	cin >> n;
	cout << "metoda dobierania x, [o]ptymalna, [r]�wnoodleg�a" << endl;
	cin >> metoda_uruchamiania;
	if (metoda_uruchamiania != 'o')
		metoda_uruchamiania = 'r';
} // TODO: exceptions

// Funkcja zapisuje wyniki operacji do pliku
void zapisz_wyniki(char *fn, int &n, int &np, float *x,float *f, float *xp, float *fp, float *L, float &a, float &b)
{ // Zosta�o du�o nieu�ywanych parametr�w z czas�w test�w
	if ((fn != NULL) && (fn != "")) {
		ofstream plik;
		plik.open(fn);

		if (plik)
		{
			plik << n << " " << np << endl << a << " " << b << " " << endl;

			for (int i = 0; i <= n; i++)
			{
				plik << x[i] <<" "<< f[i] <<endl;
			}
			plik << endl; // Nowy wiersz

			for (int i = 0; i < np; i++)
			{
				plik << xp[i] << " ";
			}
			plik << endl; // Nowy wiersz

			for (int i = 0; i < np; i++)
			{ // Warto�ci funkcji L(x)
				plik << L[i] << " "<<xp[i]<<" "<<fp[i]<<endl;
			}

			plik.close();
		}
		else
		{
			string exc;
			if (!plik) {
				exc = "IOFileException; at ";
			}
			throw exception(exc.append(__func__).c_str());
		}
	} // TODO: rest of the exceptions
	else {
		string exc;
		exc = "FileNamingException; at ";
		throw exception(exc.append(__func__).c_str());
		// General exception
	}
}