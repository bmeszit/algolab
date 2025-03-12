# Körút

https://cses.fi/problemset/task/1669 (De átírtam irányítottra a feladatot!)

Egy országban $n$ város található, akik között $m$ buszjárat közlekedik. A járatok csak az adott irányban közlekednek. Barátaiddal szeretnétek egy körutazást tervezni, ami egy tetszőleges városban indul, érint valahány további (akár $0$ darab) várost, majd visszatér a kezdővárosba. A körúton minden város legfeljebb egyszer szerepelhet.

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ található, a városok és a járatok darabszáma, ahol $2 \le n \le 10^5$ és $1 \le m \le 2 \cdot 10^5$. A városokat $1,2,\dots,n$-el sorszámozzuk.

Ezt követi $m$ sor, az irányított buszjáratok leírásai. Minden sorban két egész szám, $a$ és $b$ található, $1 \le a,b \le n$, ami azt jelenti, hogy van egy buszjárat ami az $a$ városban indul és a $b$ városba tart.

Minden buszjárat két különböző város között megy és nincs több buszjárat ugyanazon várospár között ugyanabban az irányban.

## Kimenet

Ha több megoldás is van, akkor tetszőleges megadható. A kimenet első sorában a megadott városok darabszáma, $k$ legyen, a második sorban pedig a városok felsorolva, abban a sorrendben ahogy meglátogatjuk őket.

Ha nincs megoldás, akkor az "IMPOSSIBLE" szót kell kiírni.

## Példa

Bemenet:
```
5 6
1 3
1 2
3 5
5 1
2 4
4 5
```

Kimenet:
```
4
3 5 1 3
```
