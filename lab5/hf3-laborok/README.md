# Laboridőpont tradelő alkalmazás [PROGRAMOZÁS]

A BME-n sokszor előfordul, hogy a hallgatókat véletlenszerűen sorsolva osztják be
az egyes laboridőpontokra, a hallgatóknak pedig ezután egymás között kell
megoldaniuk a cserét.

Készíts alkalmazást, amely a hallgatók által megadott preferenciasorrendek
figyelembevételével elkészíti a TTC szerinti újraelosztását a "javaknak"!

Emlékeztető: Algojáték gyakorlaton volt egy kapcsolódó feladat! Melyik az, mi volt a trükk? :)

## Bemenet

Bár itt egy "konzolos" alkalmazásról van szó, mégiscsak szeretnénk 
valamennyire felhasználóbaráttá tenni, ezért most a bemenet a programozó
szempontjából egy kicsit kényelmetlenebb formátumban lesz megadva.

Legyen $n$ a cserében résztvevő hallgatók száma, $k$ pedig a lehetséges
laboridőpontok száma, de ezeket most külön nem kapjuk meg a bemeneten.

A bemenet pontosan $n$ darab sorból áll és EOF-ig kell olvasni.

Az $i$. sor $k_i+1$ stringet tartalmaz, szóközökkel elválasztva, ahol:
- Az első string a hallgató Neptun-kódja.
- Az azt követő $k_i$ stringből az első $k_i-1$ a hallgató által preferált laboridőpontok,
  sorrendben (legelső a legjobb), az utolsó pedig a jelenlegi laboridőpontja.

Az adott sorhoz tartozó $k_i$ értéke nincs megadva, a sort sorvége karakterig
kell olvasni. A hallgató csak a számára szimpatikus laboridőpontokat listázza,
a sajátjával bezárólag, azaz $2 \leq k_i \leq k$.

A laboridőpontok stringekkel vannak kódolva, az újrahasznosíthatóság érdekében
ezekről a kódokról egyedül annyit tudunk, hogy az azonos stringek azonos
laboridőpontokat jelölnek, a különbözőek pedig különbözőket, ezen felül
semmilyen formátumbeli megkötés nincs.

## Kimenet

A kimenet első $k$ darab sora a laborok új beosztását adja meg.

Az $i$. sorban az első string a labor kódját adja meg, ezt követi egy `:`,
majd a hozzárendelt hallgatók neptun kódjai következnek, szóközzel elválasztva.

Ezt kövesse egy üres sor.

Majd a kimenet következő $n$ darab sora a hallgatók szemszögéből adja meg az
újraelosztást: A $k+1+i$. sorban az $i$. hallgató kurzuscseréje legyen látható,
`<neptun-kód>: <eredeti kurzus> >> <új kurzus>` formátumban.

## Példa

Bemenet:
```
BATMAN P12 CS8
ROBINX CS8 P12
ALADAR H14 K10
MEZGEZ K10 H14
```

Kimenet:
```
P12: BATMAN
CS8: ROBINX
H14: ALADAR
K10: MEZGEZ

BATMAN: CS8 >> P12
ROBINX: P12 >> CS8
ALADAR: K10 >> H14
MEZGEZ: H14 >> K10
```
