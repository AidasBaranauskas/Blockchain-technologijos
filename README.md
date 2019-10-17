# Blockchain-technologijos
# 0.1.1
2 failai "main.cpp" ir "funkcijos.h"

Naudojimas{
  Įjungus programą, paprašoma įvesties:
  "iveskite eile simboliu. Uz kiekviena dali atskirta tarpu, bus isvedama po hasha"
  Todel įvedus "a", bus išvestas vienas hashas, įvedus "a b asd"=_341eG21 d"- išvesti bus 4 hashai.

  Nėra atskiro būdo išeiti iš įvesties laukiančio ciklo todel galima ivesti neribotai reikšmių.
  Programa neatskiria neangliškų raidžių, todel f(a) = f(ą). Kai įvestis artėja 10000, reikšmės darosi vis     mažiau atsitiktinės.
}
Kartais pavadinimus kintamųjų rašysiu su jų tipais: "int a, string b..."
"Main" perduoda įvestį funkcijai: "hasher", ji funkcijoje vadinama "base".
Ten sukuriamas masyvas "int h", su talpa 64.
Pradinės vertės yra nuo 0 iki 63 didėjančia tvarka, todel h[30] = 29. 

Pagrindinis maišymo ciklo sukimosi skaicius talpinamas "int n" kintamajame. Jis bus 10000 arba jei "base" ilgis didesnis nei 10000- tai bus tas ilgis. Galėčiau "n" pakelt iki bent 10 kart daugiau nei "base" dydį

Sekantis while ciklas suksis "n" kartų, kaskart pridedant 2 atsitiktinius skaičius prie vieno "int h" masyvo nario naudojant funkciją add(int h, int a, int b). Naudojant šias tris reikšmes pridedamas atsitiktinis skaičius prie "h" ir grąžinamas "h".

Ciklas iteruoja per konteinerius "int h[]" ir "string base", bet pasiekus limitą vel iteruojama juos nuo '0', todel ciklas baigiasi tik kai "n" pasiekia '0'.

Tada "base"o talpa pakeičiama į 64 ir jo reikšmės pakeičiamos tomis iš "h", bet pirmiau suspaudžiamos su funkcija "compress_int" į intervalą [0; 15], ir konvertuojamos į char'us šešioliktainiu fomratu.

supaprastinus:
compress_int(0/10/20/30/40, 16) -> 0/10/4/14/8, nes 20-16=4, 40- (16* 2)=8
tada: 0/10/4/14/8 -> '0', 'a', '4', 'e', '8'

Galiausiai gražinamas užhashintas "base" funkcijai "main"

# 0.1.2
Atsirado galimybė skaityti reikšmes iš failo. Ta failą reikia nurodyti programoje, pakeitus file_name reikšmę į norima txt file pilną pavadinimą (abc.txt ir pan.) arba pervadinkite txt file į "input".
Taip pat pervadintas "funkcijos.h" į "hasher.h", naujas failas "input.h" pridėtas.

# 0.1.3
failai: "main.cpp", "hasher.h", "input_output"
Pirmiausiai laukiamo vieno failo pavadinimo įvesties (be .txt priedo), jei nepavyksta atidaryti arba po iš failų nuskaitytų žodžių hash'ų išvesties- laukiamo rankinės tekso įvesties, kurią taip pat hash'uos.

Pavyzdžiui, jei yra išorinis failas "input.txt", įvedus "input" jo turinys bus išvestas į konsolę ir po šios išvesties arba pranešimo, kad nepavyko atidaryti "input.txt", bus laukiama naujos įvesties kurią hash'uos tad už kiekvieną žodį bus po hash'ą.

Eksperimentinė analizė: 
  1. neribojamas įvesties dydis maišos funkcijai: įvedus 5 milijonus "a" raidžių- veikė sklandžiai. Bet... ivedus tą patį su "b" raide gale nors gavau skirtingą visiškai hash'ą, ten papuolė 2 nereikalingi simboliai ir aš nesuvokiu kaip tai įmanoma, nes kitaip nepavyko tų simbolių gaut
  2. fiksuotas hash'o dydis: tinka. Visad bus 64, nes su šiuo parametru apibrėžiu masyvo dydį, o jis negali programoje kisti. Naudoju "define Hash_size 64" viršuje "hasher.h" failo. 
  3. reikšmė hash'o priklauso tik nuo jo pagrindo žodžio, todel pakis tik dėl savo pakitimo, o ne kitų sąlygų. Bandžiau ir veikia
  4. nesu tikras... Hash trukmė kyla jei įvesties ilgis viršija 5000. Kiekvienas hash'as turės po vieną simbolį pakeistą bent 10000 kartų. Nuspręndžiau sumažint tą skaičių iki 600
  5. bent jau aš nemokėčiau net matant kodą. Nors negarantuoji, kad kiti negalėtų.
  6. Žiūrint į kodą negaliu jų sugalvot. Kita vertus, reikia atlikti išsamų išbandymą su bent kelioms dešimtims tūkstančių reikšmių kurias hash'ins, o to dar nepadariau
  7. veikia. Net pakeitus paskutinį simbolį itin ilgame faile veikia. 
  lietuva Lietuva Lietuva!
a442f3ef017af5841b0dedc45863359bffd432398cbd76378539c8c8c5da9f5f
f7d9046a9e32e3487c0e76d28d0841f82bb04489960b1d7f84c5941ae89f1db8
2dbbf8eaeaab2fdcf64a493823c56e91a0af3ef1aa119bb463369e3a3f2596ec

Dar neatlikti papildomi komentarai
