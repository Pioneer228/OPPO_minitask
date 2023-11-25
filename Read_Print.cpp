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
    while (std::getline(in, input, ' ')) {
        Menu menu;
        menu.SetName(input);
        if (std::getline(in, input, ' ')) {
            int mm, hh;
            char colon = ':';
            menu.SetPrice(input);
            Time menu_time;
            if (in >> mm >> colon >> hh) {
                menu_time.SetMinutes(mm);
                menu_time.SetHours(hh);
                menu.SetMenuTime(menu_time);
                menu_array.emplace_back(menu);
                in.ignore();
            }
        }
    }
    return menu_array;
}

void PrintStruct(const std::vector<Menu>& menu_array) {
    for (const auto& dish : menu_array) {
        Time menu_time = dish.GetMenuTime();
        std::cout << "Название блюда: " << dish.GetName() << std::endl;
        std::cout << "Цена: " << dish.GetPrice() << std::endl;
        std::cout << "Время приготовления: " << menu_time.GetMinutes() << ":" << menu_time.GetHours() << std::endl;
    }
}