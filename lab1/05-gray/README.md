# Gray kód

A Gray kód egy olyan sorrendje az összes $n$ bites stringnek, ahol bármely két szomszédos string pontosan egy biten tér el.

Készíts egy programot ami a bemeneten megadott $n$-hez kiír egy Gray kódot!

**Figyelem**: Itt több jó megoldás is van, az automatikus teszter még nem elég okos hogy az alternatív opciókat is kezelje, de természetesen kézzel el fogom fogadni!

## Bemenet

Az input egyetlen sorában az $n$ egész szám van, $1 \le n \le 16$.

## Kimenet

A kimeneten $2^n$ darab sort kell kiírni, minden sorban a Gray kód következő elemét.

## Példa

Bemenet:
```
3
```

Kimenet:
```
000
001
011
010
110
111
101
100
```
