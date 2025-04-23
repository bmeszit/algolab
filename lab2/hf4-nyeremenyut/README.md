# Nyereményút [PROGRAMOZÁS]

https://cses.fi/problemset/task/1680

Levi megnyert egy versenyt, a nyereménye pedig egy ingyenes repülőút, ami ráadásul tetszőlegesen sok egymást követő járatból állhat. Természetesen, Levi egy olyan útvonalat szeretne megtervezni, ami a legtöbb várost érinti.

Levi el akar repülni Budapestről Tokióba úgy, hogy közben a lehető legtöbb várost látogatja meg. A bemeneten megkapod a felhasználható repülőjáratokat, továbbá előre lehet tudni, hogy nincs irányított kör a járatok gráfjában.

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ található, a városok és az összeköttetések darabszáma, ahol $2 \le n \le 10^5$ és $1 \le m \le 2 \cdot 10^5$. A városokat $1,2,\dots,n$-el sorszámozzuk, Budapest sorszáma $1$, Tokió sorszáma $n$.

Ezt követi $m$ sor, az összeköttetések leírásai. Minden sorban két egész szám, $a$ és $b$ található, $1 \le a,b \le n$, ami azt jelenti, hogy a repülő az $a$ városban indul, a $b$ városba tart. A járatok egyirányúak.

## Kimenet

Ha megoldható a feladat, akkor a kimenet első sorába írjuk ki a maximális darabszámú várost tartalmazó útvonal városainak a darabszámát. A második sorba pedig írjuk ki, mely városokat tartalmazza ez az útvonal, az útvonal szerinti sorrendben. Ha több megoldás is van, tetszőleges kiírható.

Ha nincs megoldás, akkor az "IMPOSSIBLE" szót kell kiírni.

## Példa

Bemenet:
```
5 5
1 2
2 5
1 3
3 4
4 5
```

Kimenet:
```
4
1 3 4 5
```
