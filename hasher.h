#ifndef HASHER//include guard
#define HASHER

#include <iostream>
#include <string>

using std::string;

#define Hash_size 64


int compress_to_64(int x){ //panaikina x'o dali visijancia "limit"

    if(x<0)x=-x+8;//panaikinu minusa, atsitiktinumas++

    x+=x/Hash_size;//atsitiktinumas++

    return x%=Hash_size;//panaikina pertekliu
};
int compress_to_16(int x){

    x+=x/16;

    return x%=16;//panaikina pertekliu
}
void int_randomize(int *hash_i, int hash_iz, int hash_prev, int raw_j, int i, int j){// h_i, ... -> random h_1

    *hash_i+=(hash_iz+  //kol kas cia tik kelios paprasta sudetis, bet tai efektyvu...
              hash_prev+ hash_prev*(raw_j)+
              raw_j+
              i+
              j
                );
    if(*hash_i>200000)*hash_i%=50000;/*vengiu overflow
    taip pat negaliu leist h_i, h_base ir panasioms reiksmes isaukt per daug,
    nes tada jos nusvers kitu pridedamu kintamuju svarba*/
};
int* string_to_int(const string string_raw){ //string raw -> int raw[]

    int *int_raw = new int [string_raw.size()+1] {string_raw.size()+1};
//pirma reiksme bus masyvo dydis; masyvas bus vienu didesnis
    for(int i=1; i<int_raw[0]; i++){
        int_raw[i]=(int)string_raw[i-1];//perkeliamos reiksmes
    }
    return int_raw;
};
string int_to_hex_string(int *int_hash){// int_hash[64] -> string_hash

    string string_hash;
    char char_z;//laikina reiksme
    for(int i=0; i<Hash_size; i++){
        char_z=compress_to_16(int_hash[i]);//[0;10^5] -> [0;15]
        char_z+=(char_z<10?48:87);//[0;15] -> ['0';'9'] U ['a';'f] //U reiskia aibiu sudeti
        string_hash+=char_z;
    }

    delete[] int_hash;//atlaisvinu atminti
    return string_hash;
};
int* int_to_hashed_int(int *int_raw){//int raw[] -> int hash[64]

    /*int_raw[0] = int_raw.size()
    Pirmai string_to_int funkcijoje prailginau int_raw masyva vienu,
    ir naujame elemente raw_size[0] talpinau ilgi+1 (kadangi katik prailginau masyva, jo dydis padideju vienu*/
    int *int_hash = new int [Hash_size];//sio masyvo vertes bus konvertuotos i hash. Hash size = 64

    for(int i=0; i<Hash_size; i++)
        int_hash[i]=i;//pradines reiksmes

    const int minimum_n = 300;//koks maziausas turi buti n
    int n=2*(int_raw[0]>minimum_n? int_raw[0]: minimum_n),//n=2* max( int_raw.size(), minimum_n )
        iz,//atsitiktinis indeksas "h[iz]" gautas naudojant int_raw[j] reiksmes
        i=0,j=0;//iteruos: int_hash[i], int_raw[j]

    while(n-->0){//suksis n kartu, kaskart viena int_hash[i] reiksme bus pakeista
        iz= compress_to_64(int_raw[j]);

        int_randomize(//pakeicia int_hash[i] reiksme
            &int_hash[i],                   //int_hash [i]
            int_hash[iz],                   //int_hash [int_raw [j] ]
            int_hash[ i>0?i-1:Hash_size-1 ],//int_hash [i-1]
            int_raw[j],                     //int_raw [j]
            i,                              //i
            j                               //j
            );

//i ir j bus iteruojami vis is naujo kaskart pasiekus savo limitus
        if(++i>=Hash_size)i=0;
        if(++j>=int_raw[0])j=0;
    }

    delete[] int_raw;//atlaisvinu atminti
    return int_hash;
};
string hasher(string string_raw){ //string_raw -> string_hash (hexadecimal)

    int *int_hash=int_to_hashed_int(string_to_int(string_raw));
                   //int_hash[64] <-  int_raw  <- string_raw

    string s = int_to_hex_string(int_hash);
             //string_hash[64] <- int_hash[64]
    delete []int_hash;
    return s;
};

#endif //HASHER end of include guard
