#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Time.h"
#include "Menu.h"
#include "Read_Print.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    setlocale(LC_ALL, "Russian");
    std::ifstream in("Menu.txt");
    std::vector<Menu> arr = TxtToStruct(in);
    PrintStruct(arr);
    in.close();
    _CrtDumpMemoryLeaks();
}