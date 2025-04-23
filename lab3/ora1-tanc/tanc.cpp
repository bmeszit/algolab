#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;

vector<vector<int>> g;
vector<int> mt;
vector<bool> used;
 
bool kuhn(int v)
{
  if (used[v]) return false;
  used[v] = true;
  for (int to : g[v])
  {
    if (mt[to] == -1 || kuhn(mt[to]))
    {
      mt[to] = v;
      return true;
    }
  }
  return false;
}
int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin>>n>>m>>k;
  g.assign(n, {});
  for(int i=0; i<k; ++i)
  {
    int a, b; cin>>a>>b; --a; --b;
    g[a].push_back(b);
  }

  int ans=0;
  mt.assign(m, -1);
  for(int v=0; v<n; ++v)
  {
    used.assign(n, false);
    ans += kuhn(v);
  }

  cout << ans << endl;
  for(int i=0; i<m; ++i)
  {
    if(mt[i]!=-1) cout << mt[i]+1 << " " << i+1 << endl;
  }
  return 0;
}