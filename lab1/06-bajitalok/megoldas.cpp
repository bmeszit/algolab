#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool success(ll spell, ll potion, ll success)
{
  return success <= spell * potion;
}

int main()
{
  ll n, m, k; cin>>n>>m>>k;
  vector<ll> b(n), v(m);
  for(auto& bx: b) cin>>bx;
  for(auto& vx: v) cin>>vx;

  // Rendezzük a varázslatokat növekvő sorrendbe.
  std::sort(v.begin(), v.end());

  // Keressük meg binárisan minden bájitalhoz az első
  // sikeres párt! Minden ennél erősebb bájital is sikeres
  // lesz, tehát a hátralévő tömb mérete a sikeres párok
  // száma az adott bájitallal.
  for(auto& bx: b)
  {
    ll lo = 0;
    ll hi = m;
    while(lo < hi)
    {
      ll mid = (hi-lo)/2 + lo;
      if (success(bx, v[mid], k))  hi = mid;
      else lo = mid + 1;
    }
    cout << m-lo << endl;
  }
  return 0;
}
