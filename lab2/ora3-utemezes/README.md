# Ütemezés [PROGRAMOZÁS]

https://cses.fi/problemset/task/1679

Az egyetemen teljesítened kell $n$ kurzust, amikhez összesen $m$ darab előkövetelmény szabály tartozik, olyan formátumban, hogy a $b$ kurzus megkezdéséhez az $a$-t teljesíteni kell.

A feladatod egy lehetséges teljesítési sorrend megtalálása, amiben az összes kurzust teljesíteni tudod. (Minden félévben csak egy kurzust fogsz teljesíteni.)

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ található, a kurzusok és az előkövetemény szabályok darabszáma, ahol $2 \le n \le 10^5$ és $1 \le m \le 2 \cdot 10^5$. A kurzusokat $1,2,\dots,n$-el sorszámozzuk.

Ezt követi $m$ sor, az előkövetelmény szabályok leírásai. Minden sorban két egész szám, $a$ és $b$ található, $1 \le a,b \le n$, ami azt jelenti, hogy az $a$ kurzust a $b$ megkezdése előtt teljesíteni kell.

## Kimenet

Adj meg egy lehetséges sorrendet, amiben a követelményeknek megfelelően teljesíteni tudod a kurzusokat. Ha több megoldás is lehetséges, bármelyiket megadhatod.

Ha nincs megoldás, akkor az "IMPOSSIBLE" szót írd ki.

## Példa

Bemenet:
```
5 3
1 2
3 1
4 5
```

Kimenet:
```
3 4 1 5 2
```
