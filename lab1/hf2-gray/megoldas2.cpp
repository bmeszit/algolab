// Meg ilyen bitmágiákkal is lehet Gray-kódot generálni. :)

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin>>n;
  for(int i=0; i<(1<<n); ++i)
  {
    int g=i^(i>>1);
    int b=n; while(b--) cout << ((g>>b)&1);
    cout<<endl;
  }
  return 0;
}
