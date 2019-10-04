#include <iostream>
#include <string>
//double key = 0;
#include "funkcijos.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string base = "0";

    const int Hash_size= 64;//tikriausiai neturetu buti kintamasis

    while(true){
        std::cout<<"\nieiga maisos funkcijai: ";
        std::cin>>base;
        std::cout<<hasher(base+'0', Hash_size);
        //negali base reiksme but vienoda ir veikia,
        //net be reiksmes nes "+0"
    }
    return 0;
}
