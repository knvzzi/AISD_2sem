#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int menufor = 1;


	while (menufor != 0) {

		char n, otvet;
		int chislo;

		cout << " 1 - Начать игру - Угадайка\n\n";
		cout << " 2 - Завершение программы\n";
		cout << "______________________________________________________\n";
		cout << "\n";
		cin >> n;
		system("cls");

		switch (n) {

		case '1': {
			cout << "  Введите промежуток значений в котором вы хоитие загадать число : \n";
			cout << "____________________________________________________________________\n\n";
			cin >> chislo;
			system("cls");
			cout << "      Загадайте в уме число из введённого Вами промежутка     \n";
			cout << "__________________________________________________________\n\n";
			system("pause");
			system("cls");

			int otvetfor = 1;
			int randomkom = chislo / 2, kolvo = 0, chast = chislo / 2;
			while (otvetfor != 2) {
				cout << "      Я думаю это число: " << randomkom << "\n";
				cout << "___________________________________\n";
				cout << " 1 - Меньше                        \n";
				cout << " 2 - Больше                        \n";
				cout << " 3 - Угадал                        \n";
				cout << "___________________________________\n\n";
				cin >> otvet;
				system("cls");
				while (otvet > '3' || otvet < '1') {
					cout << "           Вы некорректно ввели ответ!!!              \n\n\n";
					cout << "      Я думаю это число: " << randomkom << "\n";
					cout << "___________________________________\n";
					cout << " 1 - Меньше                        \n";
					cout << " 2 - Больше                        \n";
					cout << " 3 - Угадал                        \n";
					cout << "___________________________________\n\n";
					cin >> otvet;
					system("cls");
				}
				kolvo = kolvo + 1;
				if (otvet == '1') {
					if (kolvo == 1) {
						randomkom = chast - chast / 2;
						chast = chast / 2;
					}
					else {
						randomkom = randomkom - chast;
					}
					if (chast == 0) {
						randomkom = randomkom - 1;
					}
				}
				if (otvet == '2') {
					if (kolvo == 1) {
						randomkom = chast + chast / 2;
						chast = chast / 2;
					}
					else {
						randomkom = randomkom + chast;
					}
					if (chast == 0) {
						randomkom = randomkom + 1;
					}
				}
				if (otvet == '3') {
					otvetfor = 2;
				}
				chast = chast / 2;
			}
			system("cls");
			int max_shag = 0, gread = chislo;
			while (gread != 0) {
				gread = gread / 2;
				max_shag = max_shag + 1;
			}
			cout << "                    Результаты:                        \n";
			cout << "______________________________________________________\n"; \
			cout << " Вы задумали число " << randomkom << "\n\n";
			cout << " Программе понадобилось " << kolvo << " попыток \n\n";
			cout << " Максимальное количество шагов бинарного поиска =  " << max_shag << "\n\n";

			system("pause");
			system("cls");
			break;
		}

		case '2': {
			system("cls");
			cout << "Программа завершена\n";
			return 0;
			break;
		}

		default: {
			cout << "\nВы ввели некорректный вариант выполнения\t!!!!!!!\n";
			cout << "программы,и были возвращены в меню\t\t!!!!!!!\n\n\n";
			break;
		}
		}
	}

	return 0;
}