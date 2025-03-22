#include<bits/stdc++.h>
using namespace std;
 
int n;
vector<int> done;
void euler(int v, int b)
{
  for(int d=0; d<=1; ++d)
  {
    int u = ((v << 1) | d) & ((1<<n)-1);
    if(done[2*v+d]) continue;
    done[2*v+d]=true;
    euler(u, d);
  }
  if(b!=-1) cout << b ;
}

int main()
{
  cin>>n; --n;
  done.assign(1<<(n+1), false);
  euler(0, -1);
  for(int i=0; i<n; ++i) cout << 0;
  cout << endl;
  return 0;
}