#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <chrono>
#define INT_MAX 32767


using namespace std;

class hashTable {
public:
	struct hashNode {
		int phone{};
		string name{};

		hashNode(int ph, string* nm)
			: phone{ ph }, name{ *nm } 
		{}

	private:
		hashNode* next{}; 
		friend hashTable;
	};
	private:
		size_t m_length{}; 
		vector<hashNode*> m_data{};//вектор указателей на объекты hashNode

		int hashIndex(int phone) {
			return phone % m_length; 
		}
	public:
		hashTable(size_t length) : m_length{ length } {
			m_data.resize(length); //создание экземпляра хеш-таблицы
		}

	void resize(size_t length) {
		m_length = length;   
		m_data.resize(length); 
	}

	void addhash(int phone, string name) {
		int id = hashIndex(phone);
		hashNode* p = m_data[id];
		if (!p) {
			m_data[id] = new hashNode{ phone, &name };
			return;
		}

		while (p->next) p = p->next;
		p->next = new hashNode{ phone, &name };

		return;
	}

	void deletehash(int phone) {
		int id = hashIndex(phone);
		auto el = m_data[id];

		if (el->phone == phone) {
			m_data[id] = el->next;
			delete el;
			return;
		}

		while (el->next && el->next->phone != phone) el = el->next;
		if (el->next) {
			auto temp{ el->next };
			el->next = el->next->next;
			delete temp;
		}
		cout << "Удалён";
	}

	void searchhash(int phone) {
		auto start = chrono::high_resolution_clock::now();

		int id = hashIndex(phone);
		hashNode* p = m_data[id];

		while (p && p->phone != phone)
			p = p->next;
		auto end = chrono::high_resolution_clock::now();
		cout << "Найден: " << p->name << " время: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "нс\n";
	}

	void outputtable() {
		int counter = 0;
		for (auto el : m_data) {
			counter++;
			if (!el)
				continue;

			cout << counter << " - " << el->phone << " Имя: " << el->name << '\n';
			while ((el = el->next))
				cout << "<" << el->phone << " Имя: " << el->name << ">\n";
		}
	}
};

int menu() {
	int choice;
	cout << "1. Добавить элемент\n";
	cout << "2. Удалить элемент\n";
	cout << "3. Найти элемент\n";
	cout << "4. Вывести таблицу\n";
	cout << "5. Выйти\n";
	cout << "Выбор: ";
	cin >> choice;
	return choice;
}

int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "16 или 32 \n";
	size_t size;
	cin >> size;
	hashTable table = size;

	for (;;) {
		int phone;
		int choice = menu();

		if (choice < 0 || choice > 5) { cout << "Ошибка"; continue; }

		switch (choice) {
		case 1: {
			int phone;
			cout << "\nНомер: ";
			while (true) {
				cin >> phone;
				if (phone > INT_MAX) {
					cout << "Error: incorrect phone number. Try Again.\n";
					continue;
				}
				break;
			}
			cin.ignore();
			cout << "\nИмя: ";
			string name;
			getline(cin, name);
			table.addhash(phone, name);
			break;
		}
		case 2:
			cin >> phone;
			table.deletehash(phone);
			break;
		case 3:
			cin >> phone;
			table.searchhash(phone);
			break;
		case 4:
			table.outputtable();
			break;
		case 5:
			return 0;
		}
	}
}