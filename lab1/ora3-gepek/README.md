# Gyár [PROG]

Egy gyárban $n$ különböző sebességel dolgozó gép működik, amelyekkel egyféle terméket lehet gyártani. A cél, hogy összesen $t$ darab terméket készíts.

Minden gép esetében ismert, hogy hány másodperc alatt tud egyetlen terméket legyártani. A gépek egymástól függetlenül, párhuzamosan dolgoznak.

Mi a legrövidebb idő, ami alatt a $t$ darab termék elkészíthető?

## Bemenet

Az első bemeneti sor két egész számot tartalmaz: $n$ és $t$, a gépek és a termékek számát, $1 \le n \le 2 \cdot 10^5$, $1 \le t \le 10^9$.

A következő sor n darab egész számot tartalmaz: $k_1,k_2,\dots,k_n$ amelyek azt az időt jelentik (másodpercben), amennyi idő szükséges egy termék elkészítéséhez az adott géppel, $1 \le k_i \le 10^9$.

## Kimenet

Írj ki egy egész számot: a $t$ termék elkészítéséhez szükséges minimális időt.

## Példa

Bemenet:
```
3 7
3 2 5
```

Kimenet:
```
8
```