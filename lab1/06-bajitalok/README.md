# Mágus Misi bájitalai

Mágus Misi újabb problémával szembesült. Varázskamrájában $n$ darab bájital található, amiknek $b_1, \dots, b_n$ az erősségük.

Azonban ahhoz, hogy használni tudja a bájitalokat, szüksége van egy varázslat egyidejű kimondásához is. Varázslatból $m$ darab áll rendelkezésére és ezekhez is tartozik egy erősség, ezeket $v_1, \dots, v_m$ jelöli.

Csak abban az esetben fog egy varázslat - bájital pár működni, ha az erősségük szorzata legalább $k$, azaz ha $k \leq b_i \cdot v_j$, akkor az $i$. bájital és $j$. varázslat együtt hatásos, egyébként pedig nem.

Sajnos év eleje van és Mágiahatóság kötelező leltárt írt elő Misi számára, ahol meg kell határoznia minden bájitaláról, hogy azok hány varázslattal alkotnak hatásos párt.

## Bemenet

A bemenet első sorában az $n, m, k$ egész számok állnak szóközzel elválasztva, $n, m \leq 2 \cdot 10^5$, $k \leq 10^10$.
A második sorban a $b_1, \dots, b_n$, a harmadik sorban az $v_1, \dots, v_m$ számok szóközzel elválasztva, $b_i, v_j \leq 10^5$.

## Kimenet

A kimenet $n$ sorból álljon, az $i$. sorban az $i$. bájitalhoz tartozó hatásos párok száma legyen.

## Példa

Bemenet:
```
3 5 7
5 1 3
1 2 3 4 5
```

Kimenet:
```
4
0
3
```
