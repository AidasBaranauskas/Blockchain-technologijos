#ifndef ANALIZER//include guard
#define ANALIZER
//Talpina dali kodo naudojamo hasher analizei. Savarankiskai neturi viso funkcionalumo
#include <random>
#include <chrono>
#include <fstream>
#include "hasher.h"

char random_char(){

    char int_z=rand()%62;//10+26+26=62
    //10 {1,2,3...}, 26 {A,B,C...}, 26 {a,b,c...}

    return int_z+=(int_z<10)?48:
            int_z<36?55:61;
};
string random_string(int length){

    string s="";
    do{
        s+=random_char();
    }while(--length>0);
    return s;
};

void hasher_speed_test(string file_name){//isveda po hasha uz kiekviena zodi is failo

    std::ifstream in;
    string temp;//laiko dalys bus lygiuojamos ant krasto
    using namespace std::chrono;

    in.open(file_name.c_str());//atidarau faila
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    while(in >> temp){//kol nesibaige failas
        temp=hasher(temp);
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    in.close();
    std::cout<<"hashing of "<<file_name<<" duration in microseconds: "<<
        duration_cast<microseconds>(t2-t1).count()<<'\n';

};
//*
int* hasher_test(string string_raw){ //string_raw -> int_hash [0;15]

    int *int_hash=int_to_hashed_int(string_to_int(string_raw));
                   //int_hash[64] <-  int_raw   <-string_raw

    for(int* it=int_hash; it!=int_hash+64; it++){
        *it=compress_to_16(*it);//[0;10^5] -> [0;15]
        //[0;15] -> ['0';'9'] U ['a';'f]
    }
    return int_hash;
};

#endif //ANALIZER end of include guard
