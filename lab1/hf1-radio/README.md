# Rádió [PROGRAMOZÁS]

A bemeneten megkapod egy rádióállomás adott napi lejátszási listáját, ami
összesen $n$ zeneszámot tartalmaz.

Mi az a leghosszabb intervallum, ahol minden dal egyedi volt a listában?

## Bemenet

A bemenet első sora az $n$-t tartalmazza: a zenék darambszáma, $1 \le n \le 2 \cdot 10^5$.  
A következő sorban $n$ darab egész szám szerepel: $k_1,k_2,\ldots,k_n$, az egyes dalok azonosítószáma, $1 \le k_i \le 10^9$.

## Kimenet

A kimenet egyetlen sorból áll: azon leghosszabb intervallum hossza, amin minden zeneszám egyedi volt.

## Példa

Bemenet:
```
8
1 2 1 3 2 7 4 2
```

Kimenet:
```
5
```
