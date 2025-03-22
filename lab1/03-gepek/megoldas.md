# Gyár

Ha $x$ másodperc elegendő $t$ termék elkészítésére, akkor bármilyen $x<x'$ is elegendő!

Készítsünk tehát egy függvényt, ami ellenőrzi, hogy $x$ másodperc alatt le lehet-e gyártani $t$ terméket, majd használjunk bináris keresést a legkisebb jó $x$ megtalálására.

A lehetséges válaszok intervallumát válasszuk úgy, hogy az alsó érték egy lehetséges legkisebb érték legyen (például a $0$, hiszen az biztosan túl kicsi), a felső pedig egy olyan érték ami biztosan jó, például a $(t \cdot a[0])$ ilyen, de sok más jó választás is van.

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, t;
vector<ll> a;

// Adott idő alatt legyártható-e t db termék?
bool can_make(ll time)
{
  // Mennyi van még hátra.
  ll rem = t;
  for(int i=0; i<n; ++i)
  {
    // Itt érdemes gyorsan visszatérni, különben ha
    // a time nagy, könnyen túlcsordulhatunk.
    if(rem <= 0) break;
    rem -= time / a[i];
  }
  return rem <= 0;
}

int main()
{
  cin>>n>>t;
  a.assign(n, {}); for(auto& ax: a) cin>>ax;

  // Bináris keresés a [lo, hi] intervallumon.
  ll lo = 0;
  ll hi = a[0]*t;
  while(lo < hi)
  {
    // A (lo+hi)/2 túlcsordulhat nagy értékekre.
    ll mid = (hi-lo)/2+lo;
    if(can_make(mid)) hi = mid;
    else lo = mid+1;
  }
  cout << lo << endl;
  return 0;
}
```
