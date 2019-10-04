#include <iostream>
#include <fstream>
#include <string>
#include "hasher.h"
#include "input.h"

using std::string;
using std::cout;

int main()
{
    string file_name = "input.txt";//duodant reiksme bus naudojamas automatic o ne manual

    if(file_name.size()>0)automatic_input(file_name);
    manual_input();
    //pirmiau skaito file_name, po to laukia command line ivesties
    //jei nepavyko atidaryt, pasakys, kad nepavyko ir praleis tokia ivesti
    return 0;
}

