# Labirintus [PROGRAMOZÁS]

https://cses.fi/problemset/task/1193

A bemeneten megkapod egy labirintus térképét. A feladatod megtalálni egy utat egy megadott kiindulási cellából a célba. A térkép $n \times m$ cellából áll, minden cella vagy üres hely (padló) vagy fal. Lépni adott üres cellából jobbra, balra, felfele és lefele lehet, csak üres cellák mentén.

## Bemenet

A bemenet első sorában két egész szám, az $n$ és az $m$ található, $1 \le n,m \le 1000$, a térkép sorainak és oszlopainak a száma.

Ezt követi $n$ sor, minden sorban $m$ darab karakterrel, ami az alaprajz leírása. A `.` jelöli az üres cellákat, a `#` a falat, az `A` a kiindulási cellát, a `B` pedig a célt (ezek szintén üresek). Pontosan egy darab `A` és egy darab `B` cella van a térképen.

## Kimenet

Ha van útvonal `A`-ból `B`-be, akkor a kimenet első sorába "YES"-t, ellenkező esetben "NO"-t kell kiírni.

Amennyiben van útvonal, úgy adjunk is meg egy legrövidebbet, a következőképpen: a kimenet második sorába a $k$, az útvonal hossza kerüljön, a harmadik sorába pedig $k$ darab karakter, amelyek az egyes lépéseket kódolják: L (left), R (right), U (up), és D (down). Több megoldás esetén tetszőleges legrövidebb út kiírható.

## Példa

Bemenet:
```
5 8
########
#.A#...#
#.##.#B#
#......#
########
```

Kimenet:
```
YES
9
LDDRRRRRU
```
