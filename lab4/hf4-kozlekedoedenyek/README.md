# Közlekedőedények [PROGRAMOZÁS]

Implementáljuk a Kaminski-féle közlekedőedény-rendszert a kelmeszabály-konzisztens szétosztásra
a nem-hidraulikus számítógépünkön! :)

A feladat érdekessé tétele érdekében ugyanazon követelésekhez több kérdés is tartozik, több különböző szétosztandó vagyonértékre is kell alkalmaznunk ugyanazt a követelésrendszert és csak a **legnagyobb** kiosztott vagyonmennyiséget kell kiírni.

## Bemenet

A bemenet első sorában az $1 \leq n,q \leq 2 \cdot 10^5$ egész számok, a követelések és a kérdések darabszámát jelölik.

Az ezt követő $n$ sorban a követelések értékét adtuk meg, páros egész számként reprezentálva.
Az $(i+1)$. sorban az $2 \leq k_i \leq 2000$ szám az $i$. hitelező követelését reprezentálja.

Végül $q$ sorban következnek a kérdések, az $(n+i+1)$. sorban a $0 \leq v_i \leq 10^4$ vagyonmennyiség.

## Kimenet

A kimenet $q$ sorból álljon, az $i$. sorban a $v_i$ vagyonmennyiség esetén a ksz-konzisztens szétosztás eredményeképpen kapott **legnagyobb** részesedés, tizedestört alakban, $10^{-6}$-os pontossággal.

## Példa

Bemenet:
```
4 3
6
4
8
2
2
4
5
```

Kimenet:
```
0.500000
1.000000
1.333333
```
