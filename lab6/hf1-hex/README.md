# Hex stratégiák [PROGRAMOZÁS]

A feladat célja HEX játszó bot implementálása `c++`-ban vagy `Python`-ban.

## Emberi játék

1. A játék indításakor a konzol kérdezi a táblaméretet és a játékosok típusát.
2. Ember esetén lépés: koordináták beírása bármilyen formátumban, pl. `3 5` vagy `(3,5)`.
3. Visszavonás:
  - `u`: alapértelmezetten egy lépés ha 2 ember játszik egymás ellen és 2 lépés ha ember vs bot játszik
  - `u 5`: a megadott számnak megfelelő lépés

## Gépi játékos implementálása

- Leszármazás az absztrakt `player` osztályból.
- A `move(board)` metódus implementálása.
  - Kényelmi szempontból az `opponent_move(board, c)` függvény az ellenfél lépését elküldi nekünk, de ezt nem kötelező használni.
- Valamilyen extra, órán megbeszélt vagy akár általad kitalált ötletet vagy ötleteket, heurisztikákat tartalmazzon.
- Három típusú botot nem lehet csinálni:
  - Olyan ami kizárólag a `BaseBot` algoritmusát használja (az esetek felében saját maga ellen nyilván nyerni fog).
  - Fix stratégiát használ, pl. a 10. körben biztosan a `(2,3)` mezőre tesz.
  - Valami nem általános, láthatóan nem ésszerű, a nyerés felé vivő, csak véletlenül működő stratégiával nyer, például virágot rajzol a pálya közepére, stb.
- Csapatban is lehet dolgozni, ekkor arányosan vagy több órán megbeszélt ötletet is tartalmazzon a kód, vagy legyen benne órán nem elhangzott, általános ötlet.
- Ésszerű keretek között megengedett különböző libraryk használata, például ha azok Ubuntu-n apt vagy pip packageként telepíthetők.
  - A `/.github/workflows/evaluate.yml` fájlt aki tudja hogyan kell módosítani, nyugodtan beleírhatja a telepítő sorokat, aki nem, annak segítek.
  - Ha valaki nagyon extra és ért hozzá, lehet akár Python-ban neurális hálót feltanítani, vagy egyéb `numpy` / `scipy` optimalizálót használni.
    - A tanítás eredményét, pl. a háló súlyait egy fájlban feltölteni a kód mellé és indításkor onnan betölteni. (Ehhez én kevésbé értek, ha valami nem megy, mérsékelten tudok segíteni.)

A fő célja a feladatnak, hogy legyetek kreatívak, emberi játékos számára is izgalmasan játszó
botokat írjatok. Nem titkolt célom továbbá, hogy a készült botokat egymás ellen is versenyeztessem,
érdemes lehet ezért okosabb botokat is készíteni! :)

## Beadás

- Készüljön egy rövid leírás a botról (4-5 mondant is elég):
  - Hogyan működik a bot? (ötlet, algoritmusok, adatszerkezetek)
  - Miért lehet ez jó? Milyen ellenfél ellen hatékony?
  - Milyen gyengeségei lehetnek? (Nem baj ha van!)
- A tesztesetek darabonként 5 pontot érnek, a laborral összesen 50 pontot lehet szerezni.
