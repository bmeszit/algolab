#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// Összefésüléses rendezés
void merge_sort(int s, int e) // Az a[s:e] intervallumot rendezzük.
{
  // Ha üres, visszatérünk.
  if(e <= s) return; 

  // Rekurzívan rendezzük a két felét.
  int m = (s+e)/2; 
  merge_sort(s, m);
  merge_sort(m+1, e);

  // Összefésülünk.
  int i=0;
  vector<int> tmp(e-s+1);
  
  // Az elsőben fi, a másodikban si mutatja a következő elemet.
  int fi=s, si=m+1;
  while(fi <= m && si <= e)
  {
    if(a[fi] < a[si]) { tmp[i] = a[fi]; ++i; ++fi; }
    else { tmp[i] = a[si]; ++i, ++si; }
  }
  // Ha az egyik tömb elfogyott a másik végét befejezzük.
  while(fi <= m) { tmp[i] = a[fi]; ++i; ++fi; }
  while(si <= e) { tmp[i] = a[si]; ++i; ++si; }

  // Az eredményt visszaírjuk az eredeti tömbbe.
  for(int i=s; i<=e; ++i) a[i] = tmp[i-s];
}

int main()
{
  cin >> n;
  a.assign(n, {});
  for(auto& ax: a) cin>>ax;

  merge_sort(0, n-1);

  for(auto& ax: a) cout<<ax<<" ";
  return 0;
}
