#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a;

// Inverziószám számolása összefésüléses rendezéssel.
ll mergesort(int s, int e)
{
  if(e <= s) return 0;

  int m = (s+e)/2;
  
  // A rekurzív hívások során talált inverziók:
  ll inv = 0;
  inv += mergesort(s, m);
  inv += mergesort(m+1, e);

  int i = 0;
  vector<int> tmp(e-s+1);
  
  // Az összefésülés közben talált inverziók:
  int fi=s, si=m+1;
  while(fi <= m && si <= e)
  {
    if(a[fi] <= a[si]) { tmp[i] = a[fi]; ++i; ++fi; }
    // Amikor a második tömbből veszünk elemet, az inverzióban
    // van az első tömb hátralévő elemeivel.
    else { inv += m-fi+1; tmp[i] = a[si]; ++i, ++si; }
  }
  while(fi <= m) { tmp[i] = a[fi]; ++i; ++fi; }
  while(si <= e) { tmp[i] = a[si]; ++i; ++si; }

  for(int i=s; i<=e; ++i) a[i] = tmp[i-s];
  
  return inv;
}

int main()
{
  int n; cin >> n;
  a.assign(n, {});
  for(auto& ax: a) cin>>ax;
  cout << mergesort(0, n-1) << endl;
  return 0;
}
