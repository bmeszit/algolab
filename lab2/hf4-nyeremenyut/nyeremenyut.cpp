#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj_fwd;
vector<vector<int>> adj_rev;

vector<int> mszam; // melysegi szam
vector<int> bszam; // befejezesi szam

int mszam_next=0;
int bszam_next=0;

void dfs(int v)
{
  mszam[v] = mszam_next++;
  for(auto& u: adj_fwd[v])
  {
    if(mszam[u] != -1) continue;
    dfs(u);
  }
  bszam[v] = bszam_next++;
}

int main()
{
  cin>>n>>m;
  adj_fwd.assign(n, {});
  adj_rev.assign(n, {});
  mszam.assign(n, -1);
  bszam.assign(n, -1);

  for(int i=0; i<m; ++i)
  {
    int v, u; cin>>v>>u; --v; --u;
    adj_fwd[v].push_back(u);
    adj_rev[u].push_back(v);
  }

  for(int v=0; v<n; ++v)
  {
    if(mszam[v]!=-1) continue;
    dfs(v);
  }

  vector<int> topo(n, -1);
  for(int i=0; i<n; ++i)
  {
    topo[n-1-bszam[i]] = i;
  }

  vector<int> dp(n, -1), p(n, -1);
  dp[0]=1; p[0]=-2;
  for(auto& v: topo)
  for(auto& u: adj_rev[v])
  {
    if(dp[u] == -1) continue;
    if(dp[v] < dp[u]+1)
    {
      dp[v] = dp[u]+1;
      p[v] = u;
    }
  }

  if(dp[n-1] == -1)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  cout << dp[n-1] << endl;
  int curr = n-1;
  vector<int> path;
  while(curr!=0)
  {
    path.push_back(curr);
    curr = p[curr];
  }
  path.push_back(0);
  for(int i=path.size()-1; 0<=i; --i)
  {
    cout << path[i]+1 << " ";
  }
  cout << endl;

  return 0;
}