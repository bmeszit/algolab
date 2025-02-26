# Csapatok

https://cses.fi/problemset/task/1668/

Egy osztályba $n$ tanuló jár, akik között $m$ (kölcsönös) baráti kapcsolat van. A feladatod szétosztani a diákokat két csapatra úgy, hogy a barátok ne kerüljenek egy csapatba. A csapatok méretét tetszőlegesen megválaszthatod.

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ található, a tanulók és a barátságok darabszáma, ahol $2 \le n \le 10^5$ és $1 \le m \le 2 \cdot 10^5$. A tanulókat $1,2,\dots,n$-el sorszámozzuk.

Ezt követi $m$ sor, a barátságok leírásai. Minden sorban két egész szám, $a$ és $b$ található, $1 \le a,b \le n$, ami azt jelenti ez két tanuló barátok.

Saját magának senki nem barátja és minden barátság csak egyszer szerepel a bemeneten.

## Kimenet

Adj meg egy lehetséges csapatbeosztást, olyan módon, hogy minden tanulóhoz (a sorszámuk szerinti növekvő sorrendben) az $1$ vagy a $2$ számot írod ki, a szerint, hogy melyik csapatba osztottad be őket. Ha több megoldás is lehetséges, bármelyiket megadhatod.

Ha nincs megoldás, akkor az "IMPOSSIBLE" szót írd ki.

## Példa

Bemenet:
```
5 3
1 2
1 3
4 5
```

Kimenet:
```
1 2 2 1 2
```