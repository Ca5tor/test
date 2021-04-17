#include <iostream>

double f(double x) {
	return (5 * x * sin(x + 1) + 2 * cos(x));
}

double Rectangle(double a, double b, int n) {
	double h = (b - a) / n, s = 0, x;

	for (int i = 0; i != (n - 1); i++) {
		x = a + (h / 2) + (i * h);
		s += f(x);
	}
	s *= h;

	return s;
}

double Runge(double a, double b, double E) {
	int n = 1;
	double s = Rectangle(a, b, n), s1, d, k = 2;

	do {
		s1 = s;
		n *= 2;
		s = Rectangle(a, b, n);
		d = abs(s - s1) / k;

	} while (d >= E);

	return s;
}

int main() {
	double a = 1, b = 2, E = 0.0001;
	double s = Runge(a, b, E);
		std::cout << "Otvet: " << s << std::endl;
	system("pause");
	return 0;
}