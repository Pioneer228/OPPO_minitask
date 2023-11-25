#pragma once


struct Time {
	int mm;
	int hh;

	void SetMinutes(int minutes);
	void SetHours(int hours);

	int GetMinutes() const;
	int GetHours() const;

	Time(const int minutes, const int hours); 
	Time() : mm(0), hh(0) {}
};

