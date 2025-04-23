# Érmemátrix [PROGRAMOZÁS]

Van egy $n \times n$ méretű mátrixunk, amelynek néhány cellájában egy-egy érme található. Minden lépésben választhatunk vagy egy sort vagy egy oszlopot és a benne található összes érmét levehetjük. Adjuk meg, hogy legkevesebb hány lépéssel lehet kiüríteni a mátrixot és hogy melyik sorokat, illetve oszlopokat kell kiválasztanunk.

## Bemenet

A bemenet első sorában egy $n$ egész szám található: a mátrix mérete, $1 \le n \le 100$. A sorokat és az oszlopokat is $1,2,\dots,n$ sorszámozzunk. Ezután következik $n$ sor, ami a mátrix tartalmát írja le. Minden sorban $n$ darab karakter található: vagy egy `.` (üres mező) vagy egy `o` (érme).

## Kimenet

Először írjuk ki a $k$-t, a minimális szükséges lépések számát. Ezután írjunk ki $k$ darab sort ami a lépéseket írja le: minden sorban először egy $1$-est (sortörlés) vagy egy $2$-est (oszloptörlés), majd a kapcsolódó sor vagy oszlop sorszámát. Több megoldás esetén tetszőleges megadható.

## Példa

Bemenet:
```
3
..o
o.o
...
```

Kimenet:
```
2
1 2
2 3
```
