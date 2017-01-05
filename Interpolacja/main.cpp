#include <iostream>
#include <math.h>
#include "interpolacja.h"

using namespace std;

int main()
{
	try {
		int np = 150, n; // np=150 wynika z polecenia
		float a, b, *x;
		char metoda_uruchamiania;

		pobieranie_danych(a, b, n, metoda_uruchamiania);

		(metoda_uruchamiania == 'r')?
			x = rownoodlegleX(n, a, b):
			x = optymalneX(n, a, b);
		
		float *f = wypelnij_f(n, x);
		float *xp = rownoodlegleX(np, a, b); // Punkty xp zawsze musz¹ byæ dobierane równoodlegle
		float *fp = wypelnij_f(np, xp);
		float *L = wypelnij_L(n, np, x, xp, f);

		for (int i = 0; i <= n; i++)
			cout << "f(" << x[i] << ") = " << f[i] << endl;

		for (int i = 0; i < np; i++)
			cout << "L(" << x[i] << ")\t = " << L[i] << endl;

		zapisz_wyniki("wynik.txt", n, np, x, f, xp, fp, L, a, b);

	}
	catch (exception e)
	{
		cout << e.what();
	}
	
	cin.get();
	return 0;
}