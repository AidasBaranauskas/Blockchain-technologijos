using std::string;
using std::cout;

int* string_to_int(const string base){ //string -> int masyvo rodykle

    int *rbase = new int [base.size()+1] {base.size()+1};
//pirma reiksme yra masyvo dydis. Todel masyvas bus vienu didesnis
    for(int i=1; i<rbase[0]; i++){
        rbase[i]=(int)base[i-1];//perkeliamos reiksmes
    }
    return rbase;
};

void manual_input(){//neribotai priima rankine ivesti ir grazina hashus

    std::string base;
    cout<<"\niveskite eile simboliu. Uz kiekviena dali atskirta tarpu, bus isvedama po hasha\n";
    while(true){
        std::cin>>base;
        cout<<hasher(string_to_int(base))+" \n";
    }
};
void file_input(const string file_name){//nuskaito duota faila ir isveda po hasha kiekvienam zodziui jame

    std::ifstream input;
    input.open(file_name.c_str());//atidarau faila

    if(!input.is_open()){//jei nepavyko atidaryti failo uzdaromas file_input
        cout<<" nepavyko atidaryti failo: "+file_name+'\n';
        return;}


    cout<<"\n---hashinamos reiksmes is failo "+file_name+'\n';
    string base;
    while(input >> base){//kol nesibaige failas
        cout<<hasher(string_to_int(base))+'\n';
    }
    input.close();
    return;
};


