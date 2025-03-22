#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge { int a, b, c; };

int n, m, k;
vector<edge> edges;

struct dsu
{
  int n, cnt;
  vector<int> p, s;

  dsu(int n) : n(n), cnt(n), p(n), s(n, 1)
  {
    for(int i=0; i<n; ++i) p[i]=i;
  }

  int find(int i)
  {
    return p[i] == i ? i : p[i] = find(p[i]);
  }

  bool merge(int i, int j)
  {
    i = find(i);
    j = find(j);
    if (i == j) return false;
    if (s[i] < s[j]) swap(i, j);
    s[i] += s[j];
    p[j] = i;
    --cnt;
    return true;
  }
};

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin>>n>>m;
  edges.assign(m, {});

  for(auto& e: edges)
  {
    cin>>e.a>>e.b>>e.c; --e.a; --e.b;
  }

  sort(edges.begin(), edges.end(),
    [](const edge& e1, const edge& e2) { return e1.c < e2.c; });

  ll ans=0;
  dsu d(n);
  for(auto& e: edges)
  {
    if(d.merge(e.a, e.b)) ans += e.c;
  }

  if(1<d.cnt) cout << "IMPOSSIBLE" << endl;
  else cout << ans << endl;

  return 0;
}
