#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
using namespace std;
#define gl(str)  getline(cin,str)
#define SIZE 32
bool isProved(string num, int start, int end) {
	if (num == "")
		return false;
	char nums[] = "-0123456789";
	bool isNotNum = false;
	for (int i = 0; i < num.size(); i++) {
		for (int j = 0; j < strlen(nums); j++) {
			if (num[i] == nums[j]) {
				isNotNum = false;
				if (num[i] == '-' && i != 0)
					return false;
				if (num[i] == '-' && i == 0 && num.size() == 1)
					return false;
				break;
			}
			else
				isNotNum = true;
		}
		if (isNotNum)
			return false;
	}
	if (stoi(num) < start || stoi(num) > end)
		return false;
	return true;
}
struct Information {
	int number{};
	string name;
} Inf;
struct HT {
	array <vector<Information>, SIZE> arr;
	int hash(int key) {
		return key % SIZE;
	}
	int cnt() {
		int cnt = 0;
		for (auto& i : arr)
			cnt += i.size();
		return cnt;
	}
	bool add(int number, string name) {
		if (cnt() == 32)
			return false;
		int place = hash(number);
		for (auto& i : arr[place]) {
			if (i.number == number) {
				i.name = name;
				cout << i.name << endl;
				return true;
			}
		}
		Inf = { number, name };
		arr[place].push_back(Inf);
		return true;
	}
	string operator[](int num) {
		int place = hash(num);
		for (auto& i : arr[place]) {
			if (i.number == num)
				return i.name;
		}
		return "none";
	}
	bool del(int num) {
		int place = hash(num);
		short j = 0;
		for (auto i : arr[place]) {
			if (i.number == num) {
				arr[place].erase(arr[place].begin() + j);
				return true;
			}
			j += 1;
		}
		return false;
	}
	void print() {
		for (auto i : arr) {
			for (auto j : i)
				cout << "Name: " << j.name << "\tTelephone number: " << j.number << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	HT arr;
	string check;
	string name;
	string name_2;
	int number, N;
	bool isExit = false;
	while (!isExit) {
		cout << endl;
		do {
			cout << "1) Добавить человека!\n"
				<< "2) Удалить человека!\n"
				<< "3) Поиск человека!\n"
				<< "4) Вывести таблицу!\n"
				<< "5) Выход!\n"
				<< endl
				<< "Ваш выбор: ";
			gl(check);
		} while (!isProved(check, 1, 5));
		N = stoi(check);
		switch (N) {
		case 1:
			do {
				cout << "Введите номер телефона: ";
				gl(check);
			} while (!isProved(check, 100000, 999999));
			number = stoi(check);
			cout << "Введите имя: ";
			gl(name);
			arr.add(number, name);
			break;
		case 2:
			do {
				cout << "Введите номер телефона: ";
				gl(check);
				cout << endl;
			} while (!isProved(check, 100000, 999999));
			number = stoi(check);
			if (arr.del(number))
				cout << "Удалено!\n";
			else
				cout << "Нет такого человека!\n";
			break;
		case 3:
			do {
				cout << "Введите номер телефона: ";
				gl(check);
				cout << endl;
			} while (!isProved(check, 100000, 999999));
			number = stoi(check);
			name_2 = arr[number];
			cout << name_2 << endl;
			break;
		case 4:
			arr.print();
			break;
		case 5:
			exit(0);
			break;
		}
	}
}