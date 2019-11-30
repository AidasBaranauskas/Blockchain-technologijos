
#include "hasher.h"
#include "analizer.h"
#include "input_output.h"

using std::cout;
int main()
{
    cout<<hasher("asd")<<'\n';
    cout<<hasher("asd");
    /*
    srand(time(NULL));//reikalingas norint naudot rand()

    cout<<"1.1 po viena skirtinga simboli\n"
        <<hasher("a")<<'\n'
        <<hasher("b")<<'\n';

    cout<<"\n1.2 po daug skirtingu simboliu\n"
        <<hasher(random_string(15000))<<'\n'
        <<hasher(random_string(15000))<<'\n';

    string s=random_string(15000);
    cout<<"\n1.3 po daug vienodu simboliu neskaitant vieno\n"
        <<hasher(s+"a")<<'\n'
        <<hasher(s+"b")<<'\n';

    cout<<"\n1.4 tuscia ivestis\n"
        <<hasher("")<<'\n';


    cout<<"\n2 hasher greicio tikrinimas\n";
    hasher_speed_test("files/konstitucija.txt");


    cout<<"\n3 kiek kartu pasikartoja pakeitus viena simboli is 10e5 poru\n";
    int repetition_count = 0,
        pair_count = 1,//kiek poru
        symbol_count =5;
    string random_s_1,random_s_2;

    for(int i=0; i<pair_count; i++){
        random_s_1=random_string(symbol_count);
        random_s_2=random_string(symbol_count);
        if(hasher(random_s_1) == hasher(random_s_2) &&
            random_s_1 != random_s_2)repetition_count++;
    }
    cout<<"repetition_count: "<<repetition_count;


    cout<<"\n\n4\n";
    pair_count = 100000;
    int string_index=0,
        dif_symbol,
        dif_array=0,
        dif_array_min=999999,
        dif_array_max=-999999,
        dif_all=0,
        *int_hash_1,
        *int_hash_2,
        n=pair_count;

    char rand_char;
    do{
        random_s_1=random_string(symbol_count);
        random_s_2=random_s_1;
        random_s_2[string_index]=random_char();
        if(random_s_2[string_index]==random_s_1[string_index])random_s_2[string_index]++;
        //kartais bus ne alphanum simbolis, bet tai nieko nekeicia
        if(++string_index==symbol_count)string_index=0;
        int_hash_1=hasher_test(random_s_1);
        int_hash_2=hasher_test(random_s_2);

        for(int i=0; i<64; i++){
            dif_symbol=int_hash_1[i]-int_hash_2[i];//difference between 2 symbols
            dif_symbol=(dif_symbol<0)?-dif_symbol:dif_symbol;
            if(dif_symbol>7)dif_symbol=16-dif_symbol;

            dif_array+=dif_symbol;
        }
        if(dif_array>dif_array_max)dif_array_max=dif_array;
        if(dif_array<dif_array_min)dif_array_min=dif_array;

        dif_all+=dif_array;
        dif_array = 0;

        delete[] int_hash_1,int_hash_2;
    }while(--n!=0);
    cout<<"dif_array_max: "<<dif_array_max //64*8=
      <<"\ndif_array_min: "<<dif_array_min
      <<"\ndif_average: "<<double(dif_all)/pair_count;
*/
    return 0;
}



