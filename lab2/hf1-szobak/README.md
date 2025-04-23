# Szobák [PROGRAMOZÁS]

https://cses.fi/problemset/task/1192

A bemeneten megkapod egy épület alaprajzát és a feladatod eldönteni, hogy hány szoba van benne. Az alaprajz $n \times m$ cellából áll, minden cella vagy üres hely (padló) vagy fal. Lépni adott üres cellából jobbra, balra, felfele és lefele lehet, csak üres cellák mentén.

## Bemenet

A bemenet első sorában két egész szám, az $n$ és az $m$ található, $1 \le n,m \le 1000$, az alaprajz sorainak és oszlopainak a száma.

Ezt követi $n$ sor, minden sorban $m$ darab karakterrel, ami az alaprajz leírása. A `.` jelöli az üres cellákat, a `#` a falat.

## Kimenet

A kimenet egyetlen sorában a szobák darabszáma legyen.

## Példa

Bemenet:
```
5 8
########
#..#...#
####.#.#
#..#...#
########
```

Kimenet:
```
3
```