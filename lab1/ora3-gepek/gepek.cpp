// Ha x másodperc elegendő t termék elkészítésére, akkor
// bármilyen x<x' is elegendő, tehát a válasz bináris kereshető!

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, t;
vector<ll> a;

// Ellenőrző függvény: Adott idő alatt legyártható-e t db termék?
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

  // Keresési intervallum választása, például:
  ll lo = 0; // Biztosan túl kevés idő.
  ll hi = a[0]*t; // Biztosan elegendő idő.
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
