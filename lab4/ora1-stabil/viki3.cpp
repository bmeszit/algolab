#include<bits/stdc++.h>
using namespace std;
const int infty = numeric_limits<int>::max();

int n, m;
vector<int> boy_idx;
vector<vector<int>> boy_props;
vector<map<int, int>> girl_prefs;
queue<int> free_boys;
vector<int> girl_match;
vector<int> boy_match;

int girl_rank(int g, int b) { return girl_prefs[g].count(b) ? girl_prefs[g][b] : infty; }

void propose(int b)
{
  int g = boy_props[b][boy_idx[b]]; ++boy_idx[b];
  int ob = girl_match[g];
  if(ob != -1)
  {
    if(girl_rank(g, ob) < girl_rank(g, b)) { free_boys.push(b); return; }
    boy_match[ob] = -1;
    free_boys.push(ob);
  }
  girl_match[g] = b;
  boy_match[b] = g;
}

int main()
{
  cin>>n>>m;
  boy_idx.assign(n, {});
  boy_props.assign(n, {});
  girl_prefs.assign(m, {});

  free_boys = {};
  boy_match.assign(n, -1);
  girl_match.assign(m, -1);

  for(int b=0; b<n; ++b)
  {
    free_boys.push(b);
    int k; cin>>k;
    for(int p=0; p<k; ++p)
    {
      int g; cin>>g; --g;
      boy_props[b].push_back(g);
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

  while(!free_boys.empty())
  {
    int b = free_boys.front(); free_boys.pop();
    if (boy_props[b].size() <= boy_idx[b]) continue;
    propose(b);
  }

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