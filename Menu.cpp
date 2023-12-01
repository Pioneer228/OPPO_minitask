#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Time.h"


std::string Menu::GetName() const {
    return name;
}

void Menu::SetName(const std::string& name) {
    this->name = name;
}

std::string Menu::GetPrice() const {
    return price;
}

void Menu::SetPrice(const std::string& price) {
    this->price = price;
}

Time Menu::GetMenuTime() const {
    return menu_time;
}

void Menu::SetMenuTime(const Time& time) {
    menu_time.SetHours(time.GetHours());
    menu_time.SetMinutes(time.GetMinutes());
}

std::vector<Menu> Menu::read(std::istream& in){
    std::string input;
    std::vector<Menu> menu_array;
    while (std::getline(in, input, ' ')) {
        Menu menu;
        menu.SetName(input);
        if (std::getline(in, input, ' ')) {
            menu.SetPrice(input);
            Time menu_time = Time::read(in);
            menu.SetMenuTime(menu_time);
            menu_array.emplace_back(menu);
            in.ignore();
        }
    }
    return menu_array;
}

void Menu::write(Menu menu){
    std::cout << "Название блюда: " << menu.GetName() << std::endl;
    std::cout << "Цена: " << menu.GetPrice() << std::endl;
    Time menu_time = menu.GetMenuTime();
    Time::write(menu_time);
}

Menu::Menu(const std::string& n, const std::string& p, const Time& t) : name(n), price(p), menu_time(t) {}
