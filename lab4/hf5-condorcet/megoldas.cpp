// Ez a megoldas.md-ben a Csúcsok implementálása fejezetben van leírva:

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> x, bool rev=false)
{
  if(!rev) for(int i=0; i<x.size(); ++i) cout << x[i]+1 << " ";
  else for(int i=x.size()-1; 0<=i; --i) cout << x[i]+1 << " ";
}
 
int main()
{
  int n, m; cin>>n>>m;
  vector<vector<int>> win(n), loss(n);
  
  set<pair<int, int>> e;
  for(int i=0; i<n; ++i)
  for(int j=i+1; j<n; ++j)
    e.insert({i, j});
 
  for(int i=0; i<m; ++i)
  {
    int v, u; cin>>v>>u; --v; --u;
    e.erase({min(v,u), max(v,u)});
    e.insert({v,u});
  }
  for(auto& [v,u]: e)
  {
    // v wins, u loses
    win[u].push_back(v);
    loss[v].push_back(u);
  }
  cout << 4*n << endl;
  for(int i=0; i<n; ++i)
  {
    cout << i+1 << " "; print(loss[i], false); print(win[i], false); cout << endl;
    print(loss[i], true); print(win[i], true); cout << i+1 << " "; cout << endl;
    print(win[i], false); cout << i+1 << " "; print(loss[i], false); cout << endl;
    print(win[i], true); cout << i+1 << " "; print(loss[i], true); cout << endl;
  }
  return 0;
}