#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> rooms;

void dfs(int x, int y)
{
  if(x<0 || n<=x) return;
  if(y<0 || m<=y) return;
  if(rooms[x][y] == '#') return;

  rooms[x][y] = '#';
  dfs(x-1, y);
  dfs(x+1, y);
  dfs(x, y-1);
  dfs(x, y+1);
}

int main()
{
  cin>>n>>m;
  rooms.assign(n, {});
  for(int i=0; i<n; ++i)
  {
    cin>>rooms[i];
  }

  int ans=0;
  for(int i=0; i<n; ++i)
  for(int j=0; j<m; ++j)
  {
    if(rooms[i][j] == '.')
    {
      ++ans;
      dfs(i, j);
    }
  }
  cout << ans << endl;
  return 0;
}