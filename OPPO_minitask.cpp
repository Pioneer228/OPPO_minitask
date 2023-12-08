#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Time.h"
#include "Menu.h"
#include "Read_Print.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream in("Menu.txt");
    std::vector<Menu> arr = TxtToStruct(in);
    PrintStruct(arr);
    in.close();

}