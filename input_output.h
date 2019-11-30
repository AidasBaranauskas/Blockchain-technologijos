#ifndef INPUT_OUTPUT//include guard
#define INPUT_OUTPUT

#include<string>
#include<iostream>
#include<fstream>

#include "hasher.h"

using std::string;
using std::cout;

void manual_input_to_hash(){//neribotai priima rankine ivesti ir grazina hashus. Neturi stabdziu

    cout<<"\n[manual_input_to_hash] Iveskite zodzius ir bus grazinami ju hashai\n";
    string temp;
    while(true){

        std::cin>>temp;
        cout<<hasher(temp)+'\n';
    }
};
void file_to_hash(const string file_name){//isveda po hasha uz kiekviena zodi is failo

    std::ifstream in;
    in.open(file_name.c_str());//atidarau faila

    cout<<"\n[file_to_hash] hashinamos reiksmes is failo "+file_name+'\n';
    string temp;
    while(in >> temp){//kol nesibaige failas
        cout<<hasher(temp)+'\n';
    }
    in.close();
};
void string_to_file(string text_to_output,string file_name){//output string i file

    std::ofstream out;
    out.open(file_name.c_str());

    try{
    if(!out.is_open())throw "\n nepavyko atidaryti failo: "+file_name;
    }catch(char *msg){cout<<msg;}

    out<<text_to_output;

    out.close();
}

#endif // INPUT_OUTPUT end of include guard
