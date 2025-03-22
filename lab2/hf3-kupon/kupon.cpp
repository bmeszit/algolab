#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll infty = numeric_limits<ll>::max();

using heap_data = pair<ll, int>;
using min_heap = priority_queue<heap_data, vector<heap_data>, greater<heap_data>>;

int n, m;
vector<vector<pair<int, ll>>> adj_fwd, adj_rev;
vector<ll> d_fwd, d_rev;

void dijkstra(int s, vector<vector<pair<int, ll>>>& adj, vector<ll>& d)
{
  d.assign(n, infty); d[s]=0;

  min_heap next; next.push({d[s], s});
  while(!next.empty())
  {
    auto[dv, v] = next.top(); next.pop();
    if(d[v] < dv) continue;

    for(auto& [u, w] : adj[v])
    {
      auto du = dv + w;
      if(d[u] <= du) continue;
      d[u] = du;
      next.push({d[u], u});
    }
  }
}

int main()
{
  cin>>n>>m;
  adj_fwd.assign(n, {});
  adj_rev.assign(n, {});
  for(int i=0; i<m; ++i)
  {
    int v, u; ll w; cin>>v>>u>>w; --v; --u;
    adj_fwd[v].push_back({u, w});
    adj_rev[u].push_back({v, w});
  }
  dijkstra(0, adj_fwd, d_fwd);
  dijkstra(n-1, adj_rev, d_rev);
  
  ll sol=infty;
  for(int v=0; v<n; ++v)
  for(auto [u, w]: adj_fwd[v])
  {
    if(d_fwd[v] == infty) continue;
    if(d_rev[u] == infty) continue;
    ll curr = d_fwd[v] + w/2 + d_rev[u];
    sol = min(sol, curr);
  }
  cout << sol << endl;

  return 0;
}
