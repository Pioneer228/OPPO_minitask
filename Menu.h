#pragma once

#include <iostream>
#include "Time.h"


struct Menu {
	std::string name;
	std::string price;
	Time menu_time;

    std::string GetName() const;

    void SetName(const std::string& name);

    std::string GetPrice() const;

    void SetPrice(const std::string& price);

    Time GetMenuTime() const;

    void SetMenuTime(const Time& time);

    static std::vector<Menu> read(std::istream& in);
    static void write(Menu menu);

	Menu(const std::string& name, const std::string& price, const Time& time);
    Menu(): name(""), price(""), menu_time() {}
};

