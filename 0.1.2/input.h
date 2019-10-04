using std::string;
using std::cout;

void manual_input(){

    string base;
    cout<<"\niveskite eile simboliu. Uz kiekviena dali atskirta tarpu, bus isvedama po hasha\n";
    while(true){
        std::cin>>base;
        cout<<" "<<hasher(base)<<'\n';
    }
};
void automatic_input(string file_name){ //nuskaito faila

    string base, sz;
    std::ifstream in;
    in.open(file_name.c_str());

    if(!in.is_open()){//jei nepavyko atidaryti failo
        cout<<"nepavyko atidaryti failo: "+file_name+"\n\n";
        return;
    }

    cout<<"hashinamos reiksmes is failo "+file_name+":\n\n";
    while(in >> sz){
        base+=(hasher(sz)+'\n');

    }
    in.close();
    cout<<base;
    return;
};//
