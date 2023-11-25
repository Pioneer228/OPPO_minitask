#pragma once

#include "Time.h"


void Time::SetMinutes(int minutes) { mm = minutes; }
void Time::SetHours(int hours) { hh = hours; }

int Time::GetMinutes() const { return mm; }
int Time::GetHours() const { return hh; }

Time::Time(const int minutes, const int hours) : mm(minutes), hh(hours) {}
