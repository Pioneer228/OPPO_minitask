#pragma once

#include "Time.h"


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

Time Time::read(std::istream& in)
{
    Time time;
    int mm, hh;
    char colon =':';
    if (in >> mm >> colon >> hh) {
        time.SetMinutes(mm);
        time.SetHours(hh);
    }
    return time;
}

void Time::write(Time time){
    std::cout << "Время приготовления: " << time.GetMinutes() << ":" << time.GetHours() << std::endl;
}

Time::Time(const int minutes, const int hours) : mm(minutes), hh(hours) {}
