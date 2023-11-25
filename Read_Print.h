#pragma once

#include <vector>
#include <fstream>
#include "Menu.h"


std::vector<Menu> TxtToStruct(std::ifstream& in);

void PrintStruct(const std::vector<Menu>& arr);

