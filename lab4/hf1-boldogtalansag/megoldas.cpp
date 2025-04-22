#include<bits/stdc++.h>
using namespace std;

const int infty = numeric_limits<int>::max();

struct gale_shapely
{
  int n, m;
  vector<int> boy_idx;
  vector<vector<int>> boy_props;
  vector<map<int, int>> girl_prefs;

  int regret;
  vector<int> boy_best_idx;
  vector<int> girl_best_idx;

  queue<int> free_boys;
  vector<int> girl_match;
  vector<int> boy_match;

  void init(int n, int m)
  {
    this->n=n;
    this->m=m;
    boy_idx.assign(n, {});
    boy_props.assign(n, {});
    girl_prefs.assign(m, {});
  }

  void add_boy_pref(int b, int g, int p) { boy_props[b].push_back(g); }
  void add_girl_pref(int g, int b, int p) { girl_prefs[g][b] = p; }

  void reset()
  {
    free_boys = {};
    for(int b=0; b<n; ++b) free_boys.push(b);
    boy_match.assign(n, -1);
    girl_match.assign(m, -1);
  }

  bool boy_has_next(int b)
  {
    return boy_idx[b] < boy_props[b].size();
  }

  int boy_next(int b)
  {
    return boy_props[b][boy_idx[b]++];
  }

  int girl_rank(int g, int b)
  {
    return girl_prefs[g].count(b) ? girl_prefs[g][b] : infty;
  }

  void propose(int b)
  {
    int g = boy_next(b);
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

  void run()
  {
    while(!free_boys.empty())
    {
      int b = free_boys.front(); free_boys.pop();
      if (!boy_has_next(b)) continue;
      propose(b);
    }
  }

  void print(bool rev=false)
  {
    int cnt=0;
    for(int b=0; b<n; ++b) if(boy_match[b] != -1) ++cnt;
    cout << cnt << endl;

    if(rev)
    {
      for(int g=0; g<m; ++g)
      {
        if(girl_match[g] == -1) continue;
        cout << g+1 << " " << girl_match[g]+1 << endl;
      }
    }
    else
    {
      for(int b=0; b<n; ++b)
      {
        if(boy_match[b] == -1) continue;
        cout << b+1 << " " << boy_match[b]+1 << endl;
      }
    }
  }
};

int main()
{
  int n, m;
  cin>>n>>m;

  // Lefuttatjuk a lánykérő algoritmust mindkét irányból.

  gale_shapely boy, girl;
  boy.init(n, m); boy.reset();
  girl.init(m, n); girl.reset();

  for(int b=0; b<n; ++b)
  {
    int k; cin>>k; for(int p=0; p<k; ++p)
    {
      int g; cin>>g; --g;
      boy.add_boy_pref(b, g, p);
      girl.add_girl_pref(b, g, p);
    }
  }

  for(int g=0; g<m; ++g)
  {
    int k; cin>>k; for(int p=0; p<k; ++p)
    {
      int b; cin>>b; --b;
      boy.add_girl_pref(g, b, p);
      girl.add_boy_pref(g, b, p);
    }
  }

  boy.run();
  girl.run();

  // Megnézzük ki hanyadik opcióját kapta a két esetben,
  // ezek külbségei a boldogtalanságok.

  vector<int> boy_regret(n, -1);
  vector<int> girl_regret(m, -1);

  for(int b=0; b<n; ++b)
  {
    int boy_best_match = boy.boy_match[b];
    int boy_worst_match = girl.girl_match[b];

    int rank_best = girl.girl_rank(b, boy_best_match);
    int rank_worst = girl.girl_rank(b, boy_worst_match);

    if(rank_best != infty) boy_regret[b] = rank_worst - rank_best;
  }

  for(int g=0; g<m; ++g)
  {
    int girl_best_match = girl.boy_match[g];
    int girl_worst_match = boy.girl_match[g];

    int rank_best = boy.girl_rank(g, girl_best_match);
    int rank_worst = boy.girl_rank(g, girl_worst_match);

    if(rank_best != infty) girl_regret[g] = rank_worst - rank_best;
  }

  for(int b=0; b<n; ++b)
  {
    cout << boy_regret[b] << endl;
  }
  for(int g=0; g<m; ++g)
  {
    cout << girl_regret[g] << endl;
  }

  return 0;
}