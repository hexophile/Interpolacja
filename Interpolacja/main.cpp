#include <iostream>
#include <math.h>
#include "interpolacja.h"

using namespace std;

int main()
{
	try {
		int np = 150, n = 7, a = -3, b = 3;

		float *optX = optymalneX(n, a, b);

		float *x = rownoodlegleX(n, a, b);
		float *f = wypelnij_f(n, x);
		
		float *xp = rownoodlegleX(np, a, b);
		float *fp = wypelnij_fp(np, xp);

		float *L = wypelnij_L(n, np, x, xp, f); // brak

		for (int i = 0; i <= n; i++)
			cout << "f(" << x[i] << ") = " << ((i<n)?f[i]:0.0) << endl;

		for (int i = 0; i <= n; i++)
			cout << "optX[" << i << "] = " << optX[i] << endl;

		for (int i = 0; i < n; i++)
			cout << "L(" << x[i] << ")\t = " << L[i] << endl;
	}
	catch (exception e)
	{
		cout << e.what();
	}
	
	cin.get();
	return 0;
}