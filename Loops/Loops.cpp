#include <stdio.h>
#include <conio.h> 
#include <math.h>

void main()
{
	const double pi = 3.141592;
	double a, b, h, x, y, s, delta;
	int n, k;
	printf("Enter a, b, h, n\n");
	scanf_s("%lf%lf%lf%d", &a, &b, &h, &n);
	printf("   x  |   Y(x)  |  S(x)  |    Y(x)-S(x)  |\n");
	printf("------------------------------------------\n");
	for (x = a; x <= b; x += h)
	{
		y = (pow(x, 2) - pow(pi, 2) / 3) * 1. / 4;
		s = 0;
		for (k = 1; k <= n; k++)
		{
			s += pow(-1, k) * cos(k * x) / pow(k, 2);
		}
		delta = fabs(y - s);
		printf("\n %.2lf | %.4lf | %.4lf|    %.4lf    | \n", x, y, s, delta);
	}
	_getch();
}