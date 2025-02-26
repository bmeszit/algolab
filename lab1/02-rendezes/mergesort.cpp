#include <bits/stdc++.h>
using namespace std;

vector<int> a;

void mergesort(int s, int e)
{
  if(e <= s) return;

  int m = (s+e)/2;
  mergesort(s, m);
  mergesort(m+1, e);

  int i = 0;
  vector<int> tmp(e-s+1);
   
  int fi=s, si=m+1;
  while(fi <= m && si <= e)
  {
    if(a[fi] < a[si]) { tmp[i] = a[fi]; ++i; ++fi; }
    else { tmp[i] = a[si]; ++i; ++si; }
  }
  while(fi <= m) { tmp[i] = a[fi]; ++i; ++fi; }
  while(si <= e) { tmp[i] = a[si]; ++i; ++si; }

  for(int i=s; i<=e; ++i) a[i] = tmp[i-s];
}

int main()
{
  int n; cin >> n;
  a.assign(n, {});
  for(auto& ax: a) cin>>ax;

  mergesort(0, n-1);

  for(auto& ax: a) cout<<ax<<" ";
  return 0;
}
