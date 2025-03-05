# Repülő

https://cses.fi/problemset/task/1671

Egy repülőtársaság $n$ várost szolgál ki $m$ járattal. A feladatod, hogy eldöntsd mi a legrövidebb légi útvonal a központból az összes városba.

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ található, a városok és az összeköttetések darabszáma, ahol $2 \le n \le 10^5$ és $1 \le m \le 2 \cdot 10^5$. A városokat $1,2,\dots,n$-el sorszámozzuk, a központi város az $1$-es sorszámú.

Ezt követi $m$ sor, az összeköttetések leírásai. Minden sorban három egész szám, $a$, $b$ és $c$ található, $1 \le a,b \le n$, $1 \le c \le 10^9$, ami azt jelenti, hogy a repülő az $a$ városban indul, a $b$ városba tart és $c$ az út hossza. A járatok egyirányúak.

Tudjuk, hogy minden városba el lehet jutni a központból.

## Kimenet

Írj ki $n$ darab egész számot: a központból a legrövidebb út hosszát az adott városba, a városok sorszáma szerinti növekvő sorrendben.

## Példa

Bemenet:

```
3 4
1 2 6
1 3 2
3 2 3
1 3 4
```

Kimenet:
```
0 5 2
```
