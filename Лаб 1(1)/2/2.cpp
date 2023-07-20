#include <iostream>

using namespace std;

int main() {
	//рекурсия
	setlocale(LC_ALL, "russian");

	int n, fib(int);
	
	cout << "Введите N числа последовательности Фибоначчи: ";
	cin >> n;

	int a = 0, b = 1;
	cout << "\n";

	unsigned int start = clock();

	cout << n << " элемент последовательности Фибоначчи равен " << fib(n) << "\n\n";

	unsigned int end = clock();

	unsigned int search = end - start;

	cout << "Расчетное время рекурсии: " << search << " мс.\n\n\n" << endl;

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