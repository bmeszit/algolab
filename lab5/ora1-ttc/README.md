# Top Trading Cycle [PROGRAMOZÁS]

Implementáljuk az Algoritmikus játékelméletből a lakáspiaci újraelosztáshoz tanult Top Trading Cycle (TTC) algoritmust!

## Bemenet

A bemenet első sorában egy egész szám, az $n$ áll, ami a résztvevők számát jelöli, ahol $1 \leq n \leq 2000$. a résztvevőket $1 \dots n$ indexeljük.

Ezt követően $n$ darab sor következik, melyek mindegyike az $1..n$ számok egy permutációját tartalmazza: az $(i+1)$. sor az $i$. résztvevő preferencialistájának felel meg a résztvevők lakásain, ahol a $j$. szám, az $a_{i,j}$ az $i$. résztvevő $j$. opcióját jelenti. Az $a_{i,1}$ a résztvevő legjobb választása, míg az $a_{i,n}$ a legrosszabb választása.

## Kimenet

A kimenet $n$ sorból áll, az $i$. sorban az $i$. résztvevő által megkapott ingatlan eredeti tulajdonosának az indexe áll.

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
3
4
5
2
1
```
