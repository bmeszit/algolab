# Tamás és a hegyek

Tamás úgy döntött, hogy kirándulni megy a hegyekbe, ahol $n$ darab hegytető van,
túraútszakaszokkal össszekötve. Az $i$. hegytető $h_i$ magasságú.

Tamás valamilyen kezdeti energiáról indul és csak úgy tud az $i$. hegytetőről a $j$. hegytetőre
átmenni az összekötő útszakaszon, hogyha $h_j - h_i$ energiát elhasznál
menet közben. Ha az energiája $0$ alá csökken menet közben, akkor nem jut el a $j$.
hegytetőre. Továbbá előfordulhat, hogy a $h_j - h_i$ érték negatív, ilyenkor Tamás
energiája feltöltődik.

Tamás többféle útvonalat is szeretne kipróbálni, ezért sok kérdése van feléd. Tamás
a kérdéseit a következő formátumban teszi fel: El lehet-e jutni az $a$. hegytetőről
a $b$. hegytetőre, ha $e$ kezdeti energiával indul?

## Bemenet

A bemenet első sora két egész számot tartalmaz, $n$ és $m$: a hegyek és a túraszakaszok darabszámát.
$2 \le n,m \le 2\cdot10^5$.

A második sorban a hegytetők magasságai vannak: $h_1, \dots, h_n$. $1 \le h_i \le 10^9$.

Ezt követi $m$ darab sor, minden sorban egy $u$ és $v$ egész szám, mely egy $u$. és $v$.
hegytető közötti kétirányú túraútvonalat jelöl. Garantált, hogy $u \neq v$ és hogy
minden hegytetőpár között legfeljebb egy közvetlen túraszakasz vezet.

Végül Tamás kérdéseinek $q$ száma következik, ahol $1 \le q \le 2 \cdot 10^5$,
majd pedig $q$ darab sor a kérdésekkel: $a, b$ és $e$, ahol $1 \le a,b \le n$ és
$1 \le e \le 10^9$, a kérdéshez tartozó kezdő $a$ és végső $b$ hegytető, illetve
a kezdőenergia $e$ mennyisége.

## Kimenet

A kimeneten pontosan $q$ darab sort vár Tamás, az $i$. sor tartalma "YES", ha
az adott kérdésre igen és "NO", ha nem a válasz.

## Példák

### 1\. példa

Bemenet:
```
7 7
1 5 3 4 2 4 1
1 4
4 3
3 6
3 2
2 5
5 6
5 7
5
1 1 3
6 2 0
4 7 0
1 7 4
1 7 2
```

Kimenet:
```
YES
NO
YES
YES
NO
```

### 2\. példa

Bemenet:
```
6 5
4 7 6 2 5 1
1 3
5 3
1 5
2 4
6 2
5
1 5 1
1 3 1
1 2 1000
6 2 6
6 2 5
```

Kimenet:
```
YES
NO
NO
YES
NO
```

### 3\. példa

Bemenet:
```
3 2
1 3 9
1 2
2 3
5
1 1 1
3 2 2
1 1 2
3 3 0
1 2 1
```

Kimenet:
```
YES
YES
YES
YES
NO
```

### 4\. példa

Bemenet:
```
3 3
1 4 1
1 2
2 3
1 3
5
3 3 9
1 3 6
1 1 2
3 3 6
3 3 4
```

Kimenet:
```
YES
YES
YES
YES
YES
```

### 5\. példa:
```
6 10
7 9 2 10 8 6
4 2
6 1
4 5
3 5
6 4
1 3
2 6
6 5
1 2
3 6
5
4 4 8
3 3 1
5 5 9
2 1 7
6 6 10
```

Kimenet:
```
YES
YES
YES
YES
YES
```
