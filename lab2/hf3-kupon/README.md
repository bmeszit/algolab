# Kupon

https://cses.fi/problemset/task/1195

Egy repülőtársaság $n$ várost szolgál ki $m$ járattal. A feladatod, hogy eldöntsd mi a *legolcsóbb* légi útvonal Budapest és Tokió között.

Rendelkezésedre áll egy kedvezmény kupon, amit felhasználva pontosan egy repülőjárat árát tudod a felére csökkenteni. (A kupont csak egyszer használhatod fel a teljes utazáshoz.)

Pontosabban, ha egy repülőjárat ára $x$, akkor a kupon felhasználásával az új ár $\lfloor \frac{x}{2} \rfloor$ lesz, azaz lefelé kerekítünk.

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ található, a városok és az összeköttetések darabszáma, ahol $2 \le n \le 10^5$ és $1 \le m \le 2 \cdot 10^5$. A városokat $1,2,\dots,n$-el sorszámozzuk, Budapest sorszáma $1$, Tokió sorszáma $n$.

Ezt követi $m$ sor, az összeköttetések leírásai. Minden sorban három egész szám, $a$, $b$ és $c$ található, $1 \le a,b \le n$, $1 \le c \le 10^9$, ami azt jelenti, hogy a repülő az $a$ városban indul, a $b$ városba tart és $c$ a jegy *ára*. A járatok egyirányúak.

Tudjuk, hogy valahogyan el lehet jutni Budapestről Tokióba a repülőjáratokon keresztül.

## Kimenet

Írjunk ki egy egész számot: a legolcsóbb útvonal árát Budapestről Tokióba, a kupon felhasználásával.

## Példa

Bemenet:
```
3 4
1 2 3
2 3 1
1 3 7
2 1 5
```

Kimenet:
```
2
```
