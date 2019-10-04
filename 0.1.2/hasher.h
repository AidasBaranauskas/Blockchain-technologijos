#include <iostream>
#include <ctype.h>

using std::cout;
int compress_int(int x, int base){
//if(x<0 || x>=base) -> x< [0; base)
    if(x<0)x=(int)(-1.3*x);//panaikinu minusa
    x-=(base*((int)(x/base)));//panaikina pertekliu
    //f(x = 1/2/3/4/5/6, base = 3) return = 1/2/0/1/2/0
    return x;
};

int add(int h, int a, int b){//naudoja siuos kintamuosius, kad pridetu atsitiktinius skaicius prie "h"

    h+=(h*a - b&a - a - b);
    if(h>10000||h<-10000) h/=76;//noriu isvengti overflow

    return h;
};//*/

std::string hasher(std::string base, const int Hash_size=64){

    int h[Hash_size];//laikinai talpinamos vertes
    for(int i=0; i<Hash_size; i++)h[i]=i;//pradines reiksmes

    int n=(base.size()>10000)? base.size(): 10000,//n=max(base size, 10000)
        iz;//laikina reiksme naudojama modify()
    int i=0,j=0;//loop
    //iteruojami 3 kintamieji: i-h, j-base, n-kiek kartu suksis
    //kiti du vis virsa nuliu pasiekus limitus, priesingai nei n
    while(n-->0){ //while(n>0){ n--; ...

        iz= compress_int((int)base[j], Hash_size);// h[iz] todel suspaudziu iki h.size()/Hash_size
       //po compress iz>= 0 bet maziau nei Hash_size
        h[i]+=(add( h[i], base[j], n)+
               add( base[j], h[iz], i-j));

        if(++i==Hash_size)i=0;
        if(++j==base.size())j=0;
    }

    base.resize(Hash_size);
    for(int i=0; i<Hash_size; i++){
        iz=compress_int(h[i], 16);
        iz+=iz<10?48:87;//0-15 -> '0'-'9' 'a'-'f
        base[i]=(char)iz;
    }

    return base;
};



