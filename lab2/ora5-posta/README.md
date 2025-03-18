# Posta

https://cses.fi/problemset/task/1691

Egy város postásaként a te feladatod kivinni a leveleket a lakóknak. Szeretnél egy olyan útvonalat találni a városban, ami a postáról indul és ott is végződik és minden utcán pontosan egyszer megy végig.

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ található, a város csomópontjainak és az utcáinak a darabszáma, ahol $2 \le n \le 10^5$ és $1 \le m \le 2 \cdot 10^5$. A csomópontokat $1,2,\dots,n$-el sorszámozzuk, a posta az $1$-es sorszámú csomópontban van.

Ezt követi $m$ sor, az egyes utcák leírásai. Minden sorban két egész szám, $a$ és $b$ található, $1 \le a,b \le n$, ami azt jelenti, hogy az utca az $a$ és $b$ csomópontok között megy. Az utcák mindkét irányban járhatóak.

Minden utca két különböző csomópont között megy és bármely csomópontpár között legfeljebb egy utca mehet.

## Kimenet

Ha több megoldása is van a feladatnak, akkor tetszőleges megadható. A kimenet egyetlen sorába az útvonaltervet írd: a meglátogatott csomópontok sorszámai a megfelelő sorrendben.

Ha nem létezik ilyen útvonalterv, akkor az "IMPOSSIBLE" szót kell kiírni.

## Példa

Bemenet:
```
6 8
1 2
1 3
2 3
2 4
2 6
3 5
3 6
4 5
```

Kimenet:
```
1 2 6 3 2 4 5 3 1
```
