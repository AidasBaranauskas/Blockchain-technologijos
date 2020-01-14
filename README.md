# Blockchain-technologijos
# 2 (v0.3) merkel tree hasher- minimum requirements
"classes_tools.h" faile paskutinė funkcija "tsts_to_merkel_root_hash"
"tsts" reiškia "transactions", tai yra tra tranzakcijų žemėlapis, kas yra funkcijos įvestis; išvestis yra string su merkel tree hash.

veikimo principas: 
Kuomet hash'ų skaičius (tst_count) lyginis, jie poromis suhash'uojami, o tst_count padalinamas iš dviejų, nes nauji hash'ai užima tik pusę praeitų vietos ir jie talpinami pirmoje pusėje hash'ų masyvo.
Kuomet hash'ų skaičius nėra lyginis, priklausomai nuo to, ar kintamasis "remainder" talpina hash'ą, jei talpina jis bus pridėtas prie hash'ų masyvo, jei jis tuščias bus iš masyvo perkeltas hash'as į jį, taip užtikrinant, kad visada bus lyginis skaičius hash'ų masyve.
Veikia loop kol hash'ų skaičius masyve yra nulis.
Jei po veikimo "remainder" talpina hash'ą, jis bus suhashintas su vieninteliu masyvo elementu.

Kaip supaprastintas pavyzdys jei hash'ų masyvas yra: string hashes[7] {"h1","h2","h3","h4","h5","h6","h7"}, tai taip kis hasher masyvo ir "remainder" būsenos veikimo metu.

0: 7{"h1","h2","h3","h4","h5","h6","h7"}, remainder="";

h1=hasher(h1+h2),  h2=(h3+h4),  h3=(h5+h6); remainder="h7"
1: 3{"h1","h2","h3"}; remainder="h7"

2: 4{"h1","h2","h3","h7"}; remainder=""

3: 2{"h1","h2"}; remainder=""

4: 1{"h1"}


# 2 (v0.2) competitive miner
Kasimo valdymui reikia keisti reikšmes esančias "main.cpp". Čia yra jos ir jų pradinės vertės:
    user_count=1000,- kiek naudotojų
    transaction_count=10000,//kartais tst_count- kiek tranzakcijų
    mining_rounds=10,- kiek kartų konkuruosis arba kiek bloku iš viso iškas
    contender_count=5;- kiek konkurentų
bei "struct.h" -> block -> difficulty_target = 3.

Kasimo pradžioje paminės katik minėtų kintųjų pavadinimus ir vertes, neskaitant user_count
Po kasimo praneš kiek kartų kiekvienas konkurentas laimėjo, bei kiek tranzakcijų liko. Taip pat išves visus iškastus blokus į failą "blocks_mined.txt".

# 2 (v0.1)
Programa (bent jau man) neveiks iš pirmo bandymo. Po pirmo ar pirmų kelių bandymų, ji veiks visada be išimties. Tas lųžimas įvyksta hasher() funkcijoje ir jo konkrečios priežasties neradau.

# Kaip naudotis
Įjungti programą ir tada iškas 100 blokų (blocks_to_mine) su 3 nuliais pradžioje (difficulty_target) ir talpins jų BLOCK_HEADER naujame faile "mined blocks.txt"(file_name) = 3. Jei norite pakeisti vieną iš šių kintamųjų, teks naviguotis pagal šias instrukcijas:
    blocks_to_mine: "main.cpp" failas, "main()" funkcija
    difficulty_target: "struct.h" failas, "block" klasė, "block_" metodas
    file_name: "miner.h" failas, "miner" funkcija

Kasimo (po programos įjungimo) metu į konsolę išves "kasami blokai...", kas bus sekama indeksų kiekvieno  iškasto bloko.

# 1.5
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
