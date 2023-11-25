#pragma once

#include <iostream>
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
Menu::Menu(const std::string& n, const std::string& p, const Time& t) : name(n), price(p), menu_time(t) {}
