# Stabil párosítás

Implementáljuk az Algoritmikus játékelméletből tanult lánykérő algoritmust!

## Bemenet

A bemenet első sorában az $n$ és $m$ egész számok, a fiúk és lányok darabszámai állnak, ahol $1 \leq n,m \leq 2000$. A fiúkat $1 \dots n$, a lányokat $1 \dots m$ indexeljük.

Ezt követi $n$ darab sor, a fiúk preferenciasorrendjeinek a leírásai: az $(i+1)$. sor első eleme a $0 \leq k_i \leq m$ egész szám, ami az $i$. fiú éleinek számát adja meg. Ezt követik az $a_{i,1}, \dots, a_{i,k_i}$ számok, az egyes élek leírásai. Az $a_{i,j}$ jelentése az $i$. fiú preferenciasorrendje szerinti $j$. élhez tartozó lány indexe. Az $a_{i,1}$ a legjobb, $a_{i,k_i}$ pedig a legrosszabb választása a fiúnak.

Ezt követi $m$ darab sor, a lányok preferenciasorrendjének a leírásai, az előzővel egyező formátumban: az $(n+i+1)$. sor első eleme a $0 \leq l_i \leq n$ egész szám, ami az $i$. lány éleinek számát adja meg. Ezt követik a $b_{i,1}, \dots, b_{i,l_i}$ számok, az egyes élek leírásai. A $b_{i,j}$ jelentése az $i$. lány preferenciasorrendje szerinti $j$. élhez tartozó fiú indexe. A $b_{i,1}$ a legjobb, $b_{i,l_i}$ pedig a legrosszabb választása a lánynak.

Az élek irányítatlanok, tehát ha egy lány szerepel egy adott fiú élei között, akkor a fiú is szerepel a lány élei között.

## Kimenet

A kimenet első sorában egy lehetséges stabil párosítás $r$ élszáma áll.

Ezt követi $r$ darab sor, az egyes élek leírásai.

Az $(i+1)$. sorban két egész szám: $b_i, g_i$ állnak, ahol $1 \leq b_i \leq n$ és $1 \leq g_i \leq m$, az $i$. stabil párosításbeli élhez tartozó fiú és lány indexei.

Amennyiben több stabil párosítás is van a gráfban, úgy tetszőlges kiírható.

## Példa

Bemenet:
```
5 5
3 2 3 1
1 3
2 2 4
3 5 4 3
3 1 3 5
2 1 5
2 3 1
4 5 2 1 4
2 3 4
2 5 4
```

Kimenet:
```
4
1 1
3 2
4 5
5 3
```
