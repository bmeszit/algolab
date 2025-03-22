#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// Beszúrásos rendezés
void insertion_sort() // Tömbbel + lineáris kereséssel.
{
  for(int i=1; i<n; ++i)    // Az a[i]-t szúrjuk be a rendezett a[0:i-1]-be.
  for(int j=i-1; 0<=j; --j) // A j-vel keressük a[i] helyét, közben odacseréljük
  {
    if(a[j] > a[j+1]) swap(a[j], a[j+1]);
    else break;
  }
}

int main()
{
  cin >> n;
  a.assign(n, {});
  for(auto& ax: a) cin>>ax;

  insertion_sort();

  for(auto& ax: a) cout<<ax<<" ";
  return 0;
}
