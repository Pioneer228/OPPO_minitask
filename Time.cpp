#pragma once

#include "Time.h"
#include <sstream>

void Time::SetMinutes(int minutes) {
	mm = minutes;
}

void Time::SetHours(int hours) {
	hh = hours;
}

int Time::GetMinutes() const {
	return mm;
}

int Time::GetHours() const {
	return hh;
}

void Time::ReadTime(std::istream& in)
{
    int mm, hh;
    char colon =':';
    if (in >> hh >> colon >> mm) {
        this->SetMinutes(mm);
        this->SetHours(hh);
    }
}

void Time::WriteTime() const{
    std::cout << "Время приготовления: " << this->GetHours() << ":" << this->GetMinutes() << std::endl;
}

bool Time::ValidateTime(const std::string& time) {
    std::istringstream in(time);
    int mm, hh;
    char colon = ':';
    in >> hh >> colon >> mm;
    if (in.fail() || hh < 0 || hh > 23 || mm < 0 || mm > 60) {
        return false;
    }
    return true;
}

void Time::InvalidTime(const std::string& time)
{
    if (time.empty() || !ValidateTime(time)) {
        throw std::runtime_error("Invalid time!");
    }
    ValidateTime(time);
}

Time::Time(const int minutes, const int hours) : mm(minutes), hh(hours) {}
