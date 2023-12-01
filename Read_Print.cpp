#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Read_Print.h"
#include "Menu.h"


std::vector<Menu> TxtToStruct(std::ifstream& in) {
    std::vector<Menu> menu_array = Menu::read(in);
    return menu_array;
}

void PrintStruct(const std::vector<Menu>& menu_array) {
    for (const auto& dish : menu_array) {
        Menu::write(dish);
    }
}