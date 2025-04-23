#include<bits/stdc++.h>
using namespace std;

const int infty = numeric_limits<int>::max();

int n, m;
vector<queue<int>> boy_props;
vector<map<int, int>> girl_prefs;

vector<int> girl_match;
vector<int> boy_match;

int girl_rank(int g, int b) { return girl_prefs[g].count(b) ? girl_prefs[g][b] : infty; }

bool gale_shapely()
{
  bool change = false;
  for(int i=0; i<n; ++i)
  {
    if(boy_match[i] != -1) continue;
    while(!boy_props[i].empty())
    {
      int g = boy_props[i].front(); boy_props[i].pop();
      int j = girl_match[g];

      if (j == -1 || girl_rank(g, i) < girl_rank(g, j))
      {
        if(j != -1) boy_match[j] = -1;
        girl_match[g] = i;
        boy_match[i] = g;
        change = true;
        break;
      }
    }
  }
  return change;
}

int main()
{
  cin>>n>>m;
  boy_props.assign(n, {});
  girl_prefs.assign(m, {});

  boy_match.assign(n, -1);
  girl_match.assign(m, -1);

  for(int b=0; b<n; ++b)
  {
    int k; cin>>k;
    for(int p=0; p<k; ++p)
    {
      int g; cin>>g; --g;
      boy_props[b].push(g);
    }
  }

  for(int g=0; g<m; ++g)
  {
    int k; cin>>k;
    for(int p=0; p<k; ++p)
    {
      int b; cin>>b; --b;
      girl_prefs[g][b] = p;
    }
  }

  while(gale_shapely());

  int cnt=0;
  for(int b=0; b<n; ++b) if(boy_match[b] != -1) ++cnt;
  cout << cnt << endl;
  for(int b=0; b<n; ++b)
  {
    if(boy_match[b] == -1) continue;
    cout << b+1 << " " << boy_match[b]+1 << endl;
  }

  return 0;
}