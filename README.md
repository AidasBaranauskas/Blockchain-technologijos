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
