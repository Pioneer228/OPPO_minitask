#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Read_Print.h"
#include "Menu.h"


std::vector<Menu> TxtToStruct(std::ifstream& in) {
    std::string input;
    std::vector<Menu> menu_array;
    while (in) {
        Menu menu;
        menu.ReadMenu(in);
        menu_array.emplace_back(menu);
    }
    return menu_array;
}

void PrintStruct(const std::vector<Menu>& menu_array) {
    for (const auto& dish : menu_array) {
        dish.WriteMenu();
    }
}