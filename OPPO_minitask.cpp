#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Time {
    int MM;
    int HH;

    Time(int m, int h) : MM(m), HH(h) {}
};

struct Menu {
    std::string Name;
    std::string Price;
    Time menuTime;

    Menu(const std::string& n, const std::string& p, const Time& t)
        : Name(n), Price(p), menuTime(t) {}
};

std::vector<Menu> txtToStruct(std::ifstream& in) {
    std::string input;
    std::vector<Menu> arr;
    while (std::getline(in, input, ' ')) {
        std::string Name = input;

        if (std::getline(in, input, ' ')) {
            int MM, HH;
            char colon = ':';
            std::string Price = input;

            if (in >> MM >> colon >> HH) {
                arr.emplace_back(Name, Price, Time(MM, HH));
                in.ignore();
            }
        }
    }
    return arr;
}

void printStruct(const std::vector<Menu>& arr) {
    for (const Menu& dish : arr) {
        std::cout << "Название блюда: " << dish.Name << std::endl;
        std::cout << "Цена: " << dish.Price << std::endl;
        std::cout << "Время приготовления: " << dish.menuTime.MM << ":" << dish.menuTime.HH << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream in("Menu.txt");
    std::vector<Menu> arr = txtToStruct(in);
    printStruct(arr);
    in.close();

}