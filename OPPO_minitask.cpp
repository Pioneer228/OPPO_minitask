#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct Time {
	int MM;
	int HH;

	Time(int m, int h) : MM(m), HH(h) {}
};

struct Menu {
	string Name;
	string Price;
	Time menuTime;

	Menu(const string& n, const string& p, const Time& t)
		: Name(n), Price(p), menuTime(t) {}
};

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream in("Menu.txt");
	vector<Menu> mass;
	string input;

	while (getline(in, input, ' ')) {
		string Name = input;

		if (getline(in, input, ' ')) {
			int MM, HH;
			char colon = ':';
			string Price = input;

			if (in >> MM >> colon >> HH) {
				mass.emplace_back(Name, Price, Time(MM, HH));
				in.ignore();
			}
		}

	}

	for (Menu& dish : mass) {
		cout << "Название блюда: " << dish.Name << endl;
		cout << "Цена: " << dish.Price << endl;
		cout << "Время приготовления: " << dish.menuTime.MM << ":" << dish.menuTime.HH << endl;
	}

	in.close();


}