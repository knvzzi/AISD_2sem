#include <iostream>
#include <ctime>
using namespace std;

int main() 
{
	//цикл
	setlocale(LC_ALL, "russian");

	int n, fib(int);
	
	cout << "Введите N числа последовательности Фибоначчи: ";
	cin >> n;
	cout << "\n";
	int a = 0, b = 1, c;

	unsigned int start = clock();

	if (n <= 2) {
		if (n == 1) {
			cout << n << " элемент последовательности Фибоначчи равен " << a << "\n\n\n";
		}
		if (n == 2) {
			cout << n << " элемент последовательности Фибоначчи равен " << b << "\n\n\n";
		}
	}
	else {
		for (int i = 3; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		cout << n << " элемент последовательности Фибоначчи равен " << b << "\n\n";
	}
	unsigned int end = clock();
	unsigned int result = end - start;

	cout << "Расчетное время цикла: " << result << " мс.\n\n\n" << endl;
	cout << "=====================================================================" <<"\n\n\n" << endl;

	//рекурсия

	unsigned int start_r = clock();

	fib(n);

	unsigned int end_r = clock();

	cout << n << " элемент последовательности Фибоначчи равен " << fib(n) << "\n\n";

	unsigned int result_r = end_r - start_r;

	cout << "Расчетное время рекурсии: " << result_r << " мс.\n\n\n" << endl;

	return 0;
}

int fib(int n) {
	if (n <= 2) {
		if (n == 2) {
			return 1;
		}
		if (n == 1) {
			return 0;
		}
	}
	return fib(n - 1) + fib(n - 2);
}