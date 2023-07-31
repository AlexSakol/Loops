#include <stdio.h>
#include <conio.h> 
#include <math.h>

double y(double x) {
	double f = pow(sin(x), 2) - x / 5 - 1;
	return (f);
}

void iter(double a1, double a2, double* eps) {
	int n = 0;
	double x1 = 0;
	double x2 = 0;
	for (a1; a1 <= a2; a1 += *eps)
	{
		x1 = a1;
		x2 = x1 + *eps;
		++n;
		if ((y(x1) * y(x2)) < 0) {
			printf("Iteration y=0 for x=%.5lf iterations %d\n", a1, n);
		}
	}

}

void delen(double& a1, double& a2, double eps) {
	int n = 0;
	for (; (a2 - a1) > eps;) {
		double a0 = (a1 + a2) / 2;
		if ((y(a0) * y(a2)) > 0) { a2 = a0; }
		if ((y(a0) * y(a1)) > 0) { a1 = a0; }
		++n;
		if ((y(a1) * y(a2)) < 0 && (a2 - a1) < eps) { printf("Delenie y=0 for x=%.5lf iterations %d\n", a1, n); }
	}
}

void main()
{
	double a, b, h, a1, a2;
	a = -4;
	b = 0;
	h = (b - a) / 20;
	double eps = pow(10, -4);
	for (a; a <= b; a += h) {
		a1 = a;
		a2 = a + h;
		if ((y(a1) * y(a2)) < 0) {
			iter(a1, a2, &eps);
			delen(a1, a2, eps);
		}

	}
	_getch();
}

