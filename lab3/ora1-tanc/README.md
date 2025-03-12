# Tánc

Egy iskolába $n$ fiú és $m$ lány jár. Következő héten bált szerveznek, ahol fiú-lány párokat kell alkotni. Előre ismert $k$ darab potenciális párjelölt. A feladatod találni egy olyan beosztást, ahol a lehető legtöbb fiú-lány pár tud majd egyszerre táncolni.

## Bemenet

A bemenet első sorában az $n$, $m$ és a $k$ egész számok találhatók: a fiúk, a lányok és a lehetséges párok darabszáma. A fiúkat $1,2,\dots,n$, a lányokat $1,2,\dots,m$ sorszámozzuk. $1 \le n,m \le 500$, $1 \le k \le 1000$.

Ezután $k$ sor következik a lehetséges párok leírásával. Az $i$. sorban az $a_i$ és $b_i$ egész számok az $i$. párt írják le, az $a_i$. sorszámú fiú és a $b_i$. sorszámú lány hajlandó együtt táncolni. $1 \le a_i \le n$, $1 \le b_i \le m$.

## Kimenet

A kimenet első sorába az $r$ egész számot írjuk: a lehetséges maximális egyszerre együtt táncoló párok darabszámát. Ezután a következő $r$ darab sorban írjunk le egy lehetséges beosztást. Ha több lehetséges megoldás is van, akkor tetszőleges kiírható.

## Példa

Bemenet:
```
3 2 4
1 1
1 2
2 1
3 1
```

Kimenet:
```
2
1 2
3 1
```
