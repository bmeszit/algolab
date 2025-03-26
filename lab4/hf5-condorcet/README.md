# Condorcet szavazók

Berlandban közeledik a választás időpontja. $2 \leq n \leq 50$ jelöltre kell a válaszóknak
szavazniuk, méghozzá olyan módon, hogy a teljes preferenciasorrendjüket megadják.

Mivel a választás tiszta és transzparens módon zajlik, az állami TV már előre
leközölt néhány, összesen $1 \leq m \leq \frac{n(n-1)}{2}$ darab részeredményt, a szavazás végeredményéről,
még mielőtt bárki voksolt volna.

Az $i$. részeredmény állítása szerint az $a_i$. jelölt a szavazók több mint felénél
győzte le a $b_i$. jelöltet.

A választás napján a te feladatod lesz a szavazatok összeszámlálása. Erősen javasolt
olyan eredményt prezentálnod, ami az eddig leközölt részeredményeknek megfelel. Tudjuk,
hogy az állami TV (szerencsére) nem közölt olyan részeredményt, ahol ugyanaz a
jelöltpár mindkét sorrendben is szerepelt. Így belátható, hogy mindig van olyan
véges szavazathalmaz, ami eleget tesz minden leközölt állításnak. A feladatod egy ilyen
halmaz generálása, általad válaszott $k$ méretben, ahol $k \leq 50000$.

## Figyelem

**A feladatot most egyetlen konkrét, $n=10$ méretű inputra tűztük ki, csak erre kell megoldani.**

Adható rá általános megoldás is (ilyen is létezik), de választható ügyes konstrukció, ami
konkrétan erre a gráfra működik, illetve ha valaki kézzel, vagy félig kézzel félig
számítógéppel segített módon végigszámolja és ír egy programot, ami ezt a statikus
kimenetet írja ki, azt is el fogjuk fogadni.

Pusztán kíváncsiságból persze érdekelni fog, hogy kinek hogy jött ki az eredmény. :)

## Bemenet

A bemenet első sorában az $n$ és az $m$ egész számok állnak. Ezt követi $m$ darab sor, ahol az $i$. sorban $a_i$ és $b_i$ számok találhatók: az $a_i$. jelölt legyőzi a $b_i$. jelöltet a szavazók szavazatainak több mint a felében.

## Kimenet

A kimenet első sorába a választott $k$ szavazószámot kell írni, majd ezt kövesse $k$ darab sor, minden sorban az $1 \dots n$ számok egy permutációja álljon.

## Egy másik példa, ami nem feladat

Bemenet:
```
5 4
1 2
2 3
3 4
2 5
```

Kimenet:
```
2
1 2 3 4 5
1 2 5 3 4
```
