#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> rooms;
vector<int> p; // parent

pair<int,int> from(int v) { return {v/m, v%m}; }
int to(int x, int y) { return x*m+y; }

vector<int> adj(int v)
{
  auto [x, y] = from(v);

  vector<int> r;
  if(1<=x  && rooms[x-1][y]!='#') r.push_back(to(x-1, y));
  if(x<n-1 && rooms[x+1][y]!='#') r.push_back(to(x+1, y));
  if(1<=y  && rooms[x][y-1]!='#') r.push_back(to(x, y-1));
  if(y<m-1 && rooms[x][y+1]!='#') r.push_back(to(x, y+1));
  return r;
}

char step(int p, int c)
{
  auto [px, py] = from(p);
  auto [cx, cy] = from(c);

  if(cx == px+1) return 'D';
  if(cx == px-1) return 'U';
  if(cy == py+1) return 'R';
  if(cy == py-1) return 'L';
  return '?';
}

int main()
{
  cin>>n>>m;
  rooms.assign(n, {});
  int a=-1, b=-1;
  for(int x=0; x<n; ++x)
  {
    cin>>rooms[x];
    for(int y=0; y<m; ++y)
    {
      if(rooms[x][y]=='A') a=to(x, y);
      if(rooms[x][y]=='B') b=to(x, y);
    }
  }
  
  p.assign(n*m+m, -1);
  queue<int> q;
  q.push(a); p[a]=-2;
  while(!q.empty())
  {
    auto v = q.front(); q.pop();
    for(auto u: adj(v))
    {
      if(p[u] != -1) continue;
      q.push(u); p[u] = v;
    }
  }

  if(p[b]==-1) { cout << "NO" << endl; return 0; }
  
  int curr = b;
  string res=""; int cnt=0;
  while(curr!=a)
  {
    res += step(p[curr], curr); ++cnt;
    curr = p[curr];
  }
  reverse(res.begin(), res.end());
  cout << "YES" << endl;
  cout << cnt << endl;
  cout << res << endl;

  return 0;
}