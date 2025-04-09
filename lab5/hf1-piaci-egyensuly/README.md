# Lakáspiaci egyensúly

Folytassuk az [ora1-ttc](../ora1-ttc/) feladatot és keressük most meg a piaci
egyensúlyhoz tartozó árazást:

Rendeljünk minden tulajdonos lakásához egy árat úgy, hogy ha mindenki a
saját lakásánál nem drágább lakások közül a számára legszimpatikusabbat
választja, akkor minden lakást pontosan egyvalaki fog választani.

## Bemenet

Ugyanaz, mint az [ora1-ttc](../ora1-ttc/) feladatban.

## Kimenet

A kimenet $n$ sorból áll, az $i$. sorban az $i$. tulajdonos lakásához rendelt ár legyen.

Több lehetséges megoldás is van, tetszőleges kiírható. Lakásárnak bármilyen
$2 \cdot 10^9$-nél nem nagyobb pozitív egész számot választhatunk.

## Példa

Bemenet:
```
5
3 2 4 1 5
4 3 1 2 5
2 4 5 1 3
2 5 4 3 1
4 1 3 5 2
```

Kimenet:
```
50
1000
50
1000
50
```
