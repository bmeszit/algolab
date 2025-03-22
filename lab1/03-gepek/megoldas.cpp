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
