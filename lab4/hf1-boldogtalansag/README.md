# Boldogtalanság

Tanultuk, hogy a lánykérő algoritmussal megtalálhatjuk a fiú-optimális és a lány-optimális stabil párosítást, illetve
hogy adott preferenciák mellett a stabil párosítások ugyanazt a csúcshalmazt fedik le.

Definiáljuk most egy fiú boldogtalanságát a következőképpen:

Ha az $i$. fiú a fiú-optimális stabil párosításban az ő preferenciasorrendje szerint az $f_i$. lányt kapta,
egy tetszőleges stabil párosításban pedig az $x$.-et, akkor legyen az ő boldogtalansága $x-f_i$, ahol $f_i \leq x$.
Ha pedig az $i$. fiú nincs fedve a stabil párosítások által, akkor az ő boldogtalanságát nem definiáljuk.

Továbbá definiáljuk a lányok boldogtalanságát hasonlóan.

Számítsuk ki a fiúk és a lányok maximális boldogtalanságát, azaz a fiúk boldogtalanságát a lány-optimális stabil párosításra, illetve a lányok boldogtalanságát a fiú-optimális stabil párosításra nézve!

## Bemenet

A bemenet formátuma és méretei egyeznek az [órai stabil párosításos feladat](../ora1-stabil)tal!

## Kimenet

A kimenet első $n$ sora a fiúk boldogtalanságát írja le, az $i$. sorban szereplő egész szám az $i$. fiúét. A kimenet következő $m$ sora a lányok boldogtalanságát írja le, az $n+i$. sorban szereplő egész szám az $i$. lányét. A stabil párosítások által
nem fedett csúcsokra $-1$-et írjunk ki!

## Példa

Bemenet:
```
3 3
3 3 1 2
3 1 2 3
3 2 3 1
3 3 1 2
3 1 2 3
3 2 3 1
```

Kimenet:
```
2
2
2
2
2
2
```