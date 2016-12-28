#include <iostream>
#include <math.h>
#include "interpolacja.h"

using namespace std;

int main()
{
	try {

		rownoodlegleX(-2, -4, 1);

		int np = 150, n = 7, a = -3, b = 3;

		float *optX = optymalneX(n, a, b);

		float *x = rownoodlegleX(n, a, b);
		float *f = wypelnij_f(n, x);
		
		float *xp = rownoodlegleX(np, a, b);
		float *fp = wypelnij_fp(np, xp);

	//	float *L = wypelnij_L(); // brak

		for (int i = 0; i <= n; i++)
			cout << "f(" << x[i] << ") = " << f[i] << endl;

		for (int i = 0; i <= n; i++)
			cout << "opt x = " << optX[i] << endl;
	}
	catch (exception e)
	{
		cout << e.what();
	}
	
	cin.get();
	return 0;
}