## Rádió

Algoritmus:

- Olvassuk be és tároljuk a lejátszási listát egy $p$ tömbben!
- Iteráljunk rajta végig, menet közben tartsuk nyilván minden addig látott zeneszámról, hogy hanyadik lépésben láttuk legutoljára, tároljuk ezt a `latott` map-ben.
- Legyen $i$ az aktuális zeneszám indexe! Tartsunk menet közben nyilván egy $j$ indexet, ami a legkisebb olyan index,
ahonnan nézve minden zeneszám egyedi $i$-ig. Ez $i=1$-re $j=1$.
- Amikor az $i$-ről az $i+1$-re lépünk, frissítsük $j$-t az $i+1$. zeneszám alapján. Azt legutoljára `latott[p[i+1]]`-ben láttuk, tehát az $i+1$-hez tartozó $j'$ értéke `max(j, latott[p[i+1]]+1)` lesz!
- A látott $[j,i]$ intervallumok hosszának, a $i-j+1$ értékeknek a maximuma a megoldás.

Helyesség bizonyítása:

- Invariáns tulajdonság: a $j$ adott $i$-re mindig az a legkisebb index, hogy a $[j, i]$ intervallum elemei egyediek legynek.
- Kezdetben teljesül, hiszen $i=1$-re $j=1$.
- Ha $i,j$-re teljesül ez a tulajdonság, akkor az $i+1$-hez tartozó $j'$ csak $j \leq j'$ lehet.
- Mivel a $[j, i]$ intervallum elemei egyediek, csak azt kell garantálni, hogy $p[i+1]$-el ne ütközzön senki, ami akkor lehet csak, ha $j \leq latott[p[i+1]]$, ilyenkor pedig $j' = latott[p[i+1]]+1$ a helyes választás.
- A megoldás pedig az összes lehetséges $i$-hez tartozó maximális hosszú $[j,i]$ intervallum hossza.

A lenti kódban egyetlen különbség, hogy a $p$ tömböt le sem kell tárolni, hiszen mindig csak az aktuális eleme érdekes, ezért beolvasás közben iterálunk rajta végig.

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int n; cin>>n;
  map<int, int> latott;
 
  int j=1, valasz=0;
  for(int i=1; i<=n; ++i)
  {
    int p; cin>>p;
    j = max(j, latott[p]+1);
    latott[p] = i;
    valasz = max(i-j+1, valasz);
  }
  cout << valasz << endl;
  return 0;
}
```
