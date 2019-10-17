#include <iostream>
#include <fstream>
#include <string>
#include "hasher.h"
#include "input_output.h"


int main()
{
    std::string file_name;
    std::cout<<"iveskite isorinio txt failo kuri skaitys pavadinima. Nereikia priedo .txt: ";
    std::cin>>file_name;

    file_input(file_name+".txt");

    manual_input();//po failu hashavimo, leidziama zmogaus ivestis
    //Jei nera failu arba nevapyko ne vieno atidaryt, is kart prasides sis zingsnis
    return 0;
}

