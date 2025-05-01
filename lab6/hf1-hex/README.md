# Hex stratégiák [PROGRAMOZÁS]

A feladat célja HEX játszó bot implementálása `c++`-ban vagy `Python`-ban.

## Kód használata

Emberi játék:

1. A játék indításakor a konzol kérdezi a táblaméretet és a játékosok típusát.
2. Ember esetén lépés: koordináták beírása bármilyen formátumban, pl. `3 5` vagy `(3,5)`.
3. Visszavonás:
  - `u`: Visszavonja az előző emberi lépést.
  - `u 5`: A megadott számnak megfelelő lépést von vissza.

Gépi játékos implementálása:

- Leszármazás az absztrakt `player` osztályból.
- A `move(board)` metódus implementálása.
  - Kényelmi szempontból az `opponent_move(board, c)` függvény az ellenfél lépését elküldi nekünk, de ezt nem kötelező használni.

## Órai anyag

Algojátékból tanultuk a Hex-ről, hogy:

- Nincs benne döntetlen.
- Az első játékosnak van nyerő stratégiája, ezt stratégialopással bizonyítottuk, nem ismert a nyerő stratégia.

Ötletek a ti bototok megvalósítására:

- Általános ötletek, amik bármilyen kombinatorikus játékra működhetnek:
  - Állapottér fájának valamilyen heurisztikus bejárása:
    - Lásd MI diasor: Problémamegoldás kereséssel [[1]][KERES-1], [[2]][KERES-2], [[3]][KERES-3]
    - Véletlen választás, heurisztikák, nyalábkeresés, stb.
    - Adott mélységig minden ág kifejtése, az ennyi lépés után nyerő és vesztő ágak megszámolása.
- Modellezés, a modellen működő specifikusabb ötletek:
  - Modellezés:
    - Gráf, csúcsai = mezők, élei = szomszédos mezők, további 1-1 extra csúcs játékosonként, a "0." és "n." oszlop, illetve sor reprezentálására.
    - Játékos feladata a saját kezdőcsúcsából a saját végcsúcsába útvonalat építeni, az ellenfelet akadályozni az ő útvonala megépítésében.
  - Legrövidebb út keresése saját kezdőcsúcsból a saját végcsúcsunkba, úgy hogy az üres mezők $1$, a mi mezőink $0$, az ellenfél mezői pedig $\infty$ súlyúak. A legrövidebb út egyik üres mezőjének megépítése.
    - Esetleg érdemes inkább a közepéről választani, intuitíven az jobb lesz, valószínűleg több lehetséges útvonalnak is a része.
      - A `base_bot` ezt csinálja, illetve az ellenfél oldaláról is megnézi a legrövidebb utat és inkább abba rondít bele, ha az rövidebb mint az övé.
  - Az ellenfél akadályozása, egy minimális vágás megtalálásával az ő kezdő- és végcsúcsa között, majd annak egy következő mezőjének a megépítése.
- A Hex játék konkrét struktúrájának kihasználása:
  - Híd formáció: lásd [HexWiki](https://www.hexwiki.net/index.php/Basic_(strategy_guide)#The_bridge).
  - A vágáshoz folyamalgoritmust nem programoztunk, de azt állítom hogy ebben a konkrét gráfban az ellenfél kezdő és végcsúcsa közötti minimális vágás megtalálásához nincs is szükség folyamalgoritmusra. Nyitott kérdés, hogy miért és milyen (egyszerűbb) algoritmust lehet helyette használni. :)

A `base_bot` mellett készítettem egy másik botot is, ami a fentiek közül használ egy-két ötletet és ezek segítségével az *összes* teszteseten meg tudja verni a `base_bot`-ot. Tehát a feladat nem lesz nehéz! :)

[KERES-1]: https://vik.wiki/images/1/17/Mi_eloadasdia_2018osz_2.1.1.pdf
[KERES-2]: https://vik.wiki/images/b/b7/Mi_eloadasdia_2018osz_2.1.2.pdf
[KERES-3]: https://vik.wiki/images/c/c5/Mi_eloadasdia_2018osz_3.1.pdf

## Feladat

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
