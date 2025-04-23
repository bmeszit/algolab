#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// Kiválasztásos rendezés
void selection_sort()
{
  for(int i=0; i<n-1; ++i) // Az i. pozícióba keressük a megfelelő elemet.
  {
    int min_i=i;  // A min_i-vel keressük a[i:n-1]-ben a minimumot.
    for(int j=i+1; j<n; ++j) if(a[j] < a[min_i]) min_i=j;
    swap(a[i], a[min_i]); // Beszúrjuk a minimumot az i. helyre.
  }
}

int main()
{
  cin >> n;
  a.assign(n, {});
  for(auto& ax: a) cin>>ax;

  selection_sort();

  for(auto& ax: a) cout<<ax<<" ";
  return 0;
}
