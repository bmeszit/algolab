# Mágus Misi és a félrement permutáció varázslat

Mágus Misi épp a lakáspiaci egyensúly számítása feladatot oldotta meg, amikor
egy véletlen pálcasuhintással elsütött egy permutáció varázslatot és
összekeveredtek a sorok a papírján!

Sajnos nagy a baj, mert Misi nem tudja hogy kell visszavonni az előző varázslata
hatását, ezért hozzád fordul segítségért.

Misi papírján $n$ darab sor van, a varázslat elsütése előtt az $i$. sor az $i$.
lakástulajdonoshoz tartozott. Minden sor első eleme a Misi által már kiszámolt
piaci egyensúlyi ár az adott lakásra, ezt követi az adott tulajdonos
preferenciasorrendje, ami alapján Misi számolt. A varázslat elsütése után
pontosan ugyanezek a sorok találhatók a papíron, azonban más sorrendben, mint eredetileg.

Főmágus Tamás hamarosan visszatér ellenőrizni a feladatot. Segíts Misinek megtalálni
egy lehetséges permutációját a soroknak, amiben a már kiszámolt
árak valóban piaci egyensúlyt alkotnak az adott preferenciasorrendek mellett!

Előfordulhat, hogy többféle sorrend is lehetséges, de szerencsére Tamás csak
nagyjából emlékszik az eredeti feladatra, ezért ilyenkor bármelyik megadható.
Sajnos az is megeshet, hogy Misi elszámolt valamit és nem megoldható a feladat,
ilyenkor nincs mit tennie, be kell vallania Tamásnak, hogy mi történt.

a) Adj hatékony algoritmust ami megoldja a feladatot és igazold a lépésszámát!  
b) Mondd meg azt is, hogyan kell az összes lehetséges megoldás darabszámát kiszámolni!

## Példa

Például Misi papírján a következő sorok vannak összekeveredve:

```
50 2 4 5 1 3
50 3 2 4 1 5
1000 2 5 4 3 1
1000 4 3 1 2 5
50 4 1 3 5 2
```

Az órai feladatból ismerős lehet ez, az eredeti sorrendje a soroknak lehetett például:
```
50 3 2 4 1 5
1000 4 3 1 2 5
50 2 4 5 1 3
1000 2 5 4 3 1
50 4 1 3 5 2
```
