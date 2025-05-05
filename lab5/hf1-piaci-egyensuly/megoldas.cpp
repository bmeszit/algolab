#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> state;
vector<int> pick;
vector<int> price;
vector<vector<int>> ord;

enum { fresh = -1, matched = -2 };

int main()
{
  cin>>n;
  ord.assign(n, vector<int>(n));
  for(int i=0; i<n; ++i)
  {
    for(int j=0; j<n; ++j) { cin>>ord[i][j]; --ord[i][j]; }
    reverse(ord[i].begin(), ord[i].end());
  }

  int done=0;
  state.assign(n, fresh);
  pick.assign(n, -1);
  price.assign(n, -1);
  while(done<n)
  {
    for(int i=0; i<n; ++i)
    {
      if(state[i]==matched) continue;
      while(state[ord[i].back()]==matched) ord[i].pop_back();
      pick[i] = ord[i].back();
    }
    for(int v=0; v<n; ++v)
    {
      if(state[v]!=fresh) continue;
      int u=v; while(state[u]==fresh)
      {
        state[u]=v;
        u=pick[u];
      }
      if(state[u]!=v) continue;
      int c=u; do
      {
        state[u]=matched; ++done;
        u = pick[u];
      } while(u!=c);
    }
    for(int v=0; v<n; ++v)
    {
      if(state[v]==matched && price[v]==-1)
      {
        price[v]=n-done+1;
      }
      if(state[v]!=matched) state[v]=fresh;
    }
  }
  for(int v=0; v<n; ++v) cout<<price[v]<<endl;
  return 0;
}