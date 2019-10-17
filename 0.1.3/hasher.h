#include <iostream>
#include <ctype.h>
using std::string;
using std::cout;
#define Hash_size 64 //kiliazenklis hashas
int compress_int(int x, const int limit){ //grazina reiksme tarp 0 ir "limit" naudojant x kaip pagrinda
    if(x<0)x=(-x+1);//panaikinu minusa nors nesu tikras kokiais atevejais jis buna. Gal tik su lietuviskais simboliais
        x+=x/limit;

    x%=limit;//panaikina pertekliu
    return x;
};

int add(int h_i, int h_base, int h_previous, int base_j, int i, int j){
    //grazina pakeista h_1 reiksme

    h_i+=(  h_base+  //kol kas cia tik kelios paprastos sudetys
            h_previous+ h_previous*(base_j)+
            base_j+
            i+
            j
            );
    if(h_i>200000)h_i%=50000;//vengiu overflow
    return h_i;
};
string int_to_string(int *h){//tiksliau int h[64] -> string result[64]
    //bei visos "result" reiksmes yra sesioliktaines
    string result;
    int iz;//laikina reiksme
    for(int i=0; i<Hash_size; i++){
        iz=compress_int(h[i], 16);//0-10^5 -> 0-15
        iz+=(iz<10?48:87);//0-15 -> '0'-'9' 'a'-'f
        result+=(char)iz;
    }

    delete[] h;//atlaisvinu atminti
    return result;
};
int* base_to_int_hash(int *base){//base = ivestas zodis konvertuotas i int masyva

    const int Base_size=base[0];//pries tai talpinau ivesties dydi sio masyvo pirmajame elemente
    int *h = new int [Hash_size];//h masyvas turetu buti "int_array_hash" bet sitaip maziau teksto

    for(int i=0; i<Hash_size; i++)
        h[i]=i;//pradines reiksmes

    int minimum_n = 600,//koks maziausas turi buti n
        n=2*(Base_size>minimum_n? Base_size: minimum_n),//n=2*max(Base_size, minimum_n)
        iz,//atsitiktinis indeksas "h[iz]" gautas naudojant base[j] reiksmes
        i=0,j=0;//iteruos: h[i], base[j]

    while(n-->0){//suksis n (>9999) kartu, kaskart viena h[i] reiksme bus pakeista
        iz= compress_int(base[j], Hash_size);

        h[i] = add(h[i],             //h[i]
            h[iz],                   //h[base[j]]
            h[ i>0?i-1:Hash_size-1 ],//h[i-1]
            base[j],                 //base[j]
            //n,                     //n
            i,                       //i
            j                        //j
            );

        if(++i>=Hash_size)i=0;//sie du bus iteruojami vis nuo pradziu kol "n" pasieks nuli
        if(++j>=Base_size)j=0;
    }

    delete[] base;//atlaisvinu atminti
    return h;
};
string hasher(int *base){

    return int_to_string(base_to_int_hash(base));
};

