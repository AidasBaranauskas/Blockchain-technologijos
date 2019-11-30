# Blockchain-technologijos
# 0.1.5
"main.cpp"
"hasher.h"
"input_output_h"
"analyzer.h" ateityje nebus reikalingas

pagrindinė funkcija hasher() arba gal kita dalis programos nulaužia programą per pirmuosius 1-3 paleidimus, bet tai vėliau nesikartoja, nepaisant nepalyginamai didesnio skaičiaus šių funkcijų naudojimo

# hasher() funkcija: 

dydis: 64
reikšmių aibė: 16 reikšmių (šešioliktainė): ['0','9'] V ['a';'f']
Veikimo principas: priima string, paverčia jį į int masyvą, sukuria naują int masyvą ir modifikuoja kiekvieną elementa iteruojant iš eiles kelis kartus (2 kartus stringams virsijantiems minimum_n) naudojant sudėtį tarp to elemento ir kitų reikšmių paduotų int_randomize() funkcijai. Tų reikšmių atsitiktinumas ir sukuria atsitiktį pakeitimą. Galiausiai suspaudžiama (compress_to_16(), funkcija gražina liekaną dalybos iš 16) kiekvieno elemento reikšmė į intervalą [0,15] su funkcija int_to_hex_string() ir tos paverčiamos į šešioliktaines vertes.
# Kaip naudotis

0. Įveskite failo pavadinimą ir jo turinys bus išvestas kaip hashai. Pasiekta su funkcija file_to_hash( string )
1. manual_input_to_hash( string ) nesibaigiants ciklas, kurio metu įvestis išvedama kaip hashai. Norint naudot ši funkcionalumą, reikia užkomentuoti praeitą kodą ir naudot tik manual_input_to_hash() funkciją
2. Galima atkomentuoti "CODE FOR HASHER ANALYSIS"- šis kodas atlieka hasher() analizę.

Anot analizės, hasher veikia tobulai nes visi testai sėkmingi, nors nežinau, ar čia greitas algoritmas. Turiu jo laiką, bet ne su kuo palygint. Čia hasher analizės išvestis: 

    1.1 po viena skirtinga simboli
    d195055c2901ed2a76d33638054160a51a1ee2124a0188abee485790d7ec6b17
    3c04ed0170e469ddf2bbec97b79501bbfcf8a83f70b170c7ef9328c5679dce0f

    1.2 po daug skirtingu simboliu
    f697befe8dd0f9c88b7e2e854e07e1b643690b223e7e673490ded747c711afd3
    cfcae45e0ae3dfa762a51899f793f07bcdd8bde88764a96ae310308027d38435

    1.3 po daug vienodu simboliu neskaitant vieno
    8aa02e623a854634b0a304caf7800929990046df0c49afd515bc49ef54f6d771
    219e04817211bdae3dd5f387f336ee08cab00b2dcfa47fcf1b5679c6b37efced

    1.4 tuscia ivestis
    de7a9d5a0a4eda01fe0b5f5fa06c3c76f5382501744943df22672b3d03514c01

    2 hasher greicio tikrinimas
    hashing of files/konstitucija.txt duration in microseconds: 562485

    3 kiek kartu pasikartoja pakeitus viena simboli is daug poru
    10000000 poru, hashai sutapo 0 kartu

    4 panasiu poru hashu panasumo palyginimas
    dif_array_max: 333
    dif_array_min: 178
    dif_average: 256.043

"4" Nenaudoja bitų lygmens palyinimo, bet hasher() nenaudoja bitwise operatoriu, tik sudėtį ir kartą daugybą. Lyginą skirtumą tarp dviejų simbolių konvertuotų į int, todel '0'=0, '8'=8, 'a'=10, 'f'=15... Didžiausias skirtumas tarp poros yra 8, skirtumas tarp 15 ir 0 bus 1, tarp 2 ir 8 bus 6.
Kadangi hash yra 64 dydžio, didžiausias skirtumas tarp dviejų hash yra 64 * 8=512. Vidurkis(dif_average) ≈ 512/2.
512 - didžiausia reikšmė(dif_array_max=333) ≈ 178, kas reiškia, kad skirtumai tarp hashų yra gan tolygiai pasiskirstęs, ir panašumas nėra labiau ar mažiau tikėtinas tarp panašių žodžių hashų
