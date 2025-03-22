#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int n; cin>>n;
  map<int, int> latott;
 
  int j=1, valasz=0;
  for(int i=1; i<=n; ++i)
  {
    int p; cin>>p;
    j = max(j, latott[p]+1);
    latott[p] = i;
    valasz = max(i-j+1, valasz);
  }
  cout << valasz << endl;
  return 0;
}