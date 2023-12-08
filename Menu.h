#pragma once

#include <iostream>
#include "Time.h"


struct Menu {
	std::string name;
	double price;
	Time menu_time;

    std::string GetName() const;

    void SetName(const std::string& name);

    double GetPrice() const;

    void SetPrice(const double& price);

    Time GetMenuTime() const;

    void SetMenuTime(const Time& time);

    void ReadMenu(std::istream& in);
    void WriteMenu() const;

    static bool ValidateName(const std::string& name);
    static void InvalidName(const std::string& name);

    static bool ValidatePrice(const double& price);
    static void InvalidPrice(const double& price);

	Menu(const std::string& name, const double& price, const Time& time);
    Menu(): name(""), price(), menu_time() {}
};

