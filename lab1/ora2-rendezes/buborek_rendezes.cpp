#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// Buborékrendezés
void bubble_sort()
{
  for(int i=n-1; 0<i; --i) // Az a[i] az utolsó a körben.
  {
    bool swapped=false;
    for(int j=0; j<i; ++j)   // Az a[j]-t buborékoltatjuk fel.
    {
      if (a[j] > a[j+1])
      {
        swap(a[j], a[j+1]);
        swapped=true;
      }
    }
    if(!swapped) break;
  }
}

int main()
{
  cin >> n;
  a.assign(n, {});
  for(auto& ax: a) cin>>ax;

  bubble_sort();

  for(auto& ax: a) cout<<ax<<" ";
  return 0;
}
