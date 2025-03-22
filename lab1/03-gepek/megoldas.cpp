#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, t;
vector<ll> a;

bool can_make(ll time)
{
  ll rem = t;
  for(int i=0; i<n; ++i)
  {
    if(rem <= 0) break;
    rem -= time / a[i];
  }
  return rem <= 0;
}

int main()
{
  cin>>n>>t;
  a.assign(n, {}); for(auto& ax: a) cin>>ax;

  ll lo = 0;
  ll hi = a[0]*t;
  while(lo < hi)
  {
    ll mid = (hi-lo)/2+lo;
    if(can_make(mid)) hi = mid;
    else lo = mid+1;
  }
  cout << lo << endl;
  return 0;
}