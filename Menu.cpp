#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Menu.h"
#include "Time.h"


std::string Menu::GetName() const {
    return name;
}

void Menu::SetName(const std::string& name) {
    this->name = name;
}

double Menu::GetPrice() const {
    return price;
}

void Menu::SetPrice(const double& price) {
    this->price = price;
}

Time Menu::GetMenuTime() const {
    return menu_time;
}

void Menu::SetMenuTime(const Time& time) {
    menu_time.SetHours(time.GetHours());
    menu_time.SetMinutes(time.GetMinutes());
}

void Menu::ReadMenu(std::istream& in){
    std::string input_name;
    if (std::getline(in, input_name, ' ')) {
        this->SetName(input_name);
        double input_price;
        if (in >> input_price) {
            this->SetPrice(input_price);
            Time menu_time;
            menu_time.ReadTime(in);
            this->SetMenuTime(menu_time);
            in.ignore();
        }
    }
}

void Menu::WriteMenu(std::ostream& ost) const{
    ost << "Íàçâàíèå áëşäà: " << this->GetName() << std::endl;
    ost << "Öåíà: " << this->GetPrice() << std::endl;
    Time menu_time = this->GetMenuTime();
    menu_time.WriteTime(ost);
}

bool Menu::ValidateName(const std::string& name) {
    static const std::string alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ"
        "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß"
        "0123456789"
        "_";
    for (char ch : name) {
        if (alphabet.find(ch) == std::string::npos) {
            return false;
        }
    }
    return true;
}

void Menu::InvalidName(const std::string& name)
{
    static const std::string alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ"
        "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß"
        "0123456789"
        "_";

    if (name.empty() || !ValidateName(name) || name.find_first_not_of(alphabet) != std::string::npos) {
        throw std::runtime_error("Invalid name!");
    }
    ValidateName(name);
}

bool Menu::ValidatePrice(const double& price)
{
    if (price <= 0) {
        return false;
    }
    return true;
}

void Menu::InvalidPrice(const double& price)
{
    if (price < 0)
    {
        throw std::runtime_error("Invalid price!");
    }
    ValidatePrice(price);
}

Menu::Menu(const std::string& n, const double& p, const Time& t) : name(n), price(p), menu_time(t) {}
