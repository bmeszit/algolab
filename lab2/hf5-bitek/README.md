# Bitek [PROGRAMOZÁS]

https://cses.fi/problemset/task/1692

A feladatod konstruálni egy minimális hosszúságú bitsorozatot, ami tartalmaz minden lehetséges $1 \le n \le 15$ hosszú bitsorozatot részszóként. (A részszót úgy kapjuk, hogy az eredeti bitsorozat egy prefixét és egy szuffixét elhagyjuk.)

Például, $n=2$ esetén a `00110` egy lehetséges megoldás, mivel tartalmazza az összes $2$ hosszú bitsorozatot: `00`, `01`, `10` and `11` és belátható, hogy ennél rövidebb megoldás nincs.

## Bemenet

A bemenet egyetlen sorában az $n$ egész szám van.

## Kimenet

A kimeneten egy olyan minimális hosszúságú bitsorozatot kell kiírni, ami minden $n$ hosszú lehetséges bitsorozatot tartalmaz részszóként. Ha több megoldás is van, tetszőleges minimális hosszúságú kiírható.

## Példa

Bemenet:
```
2
```

Kimenet:
```
00110
```
