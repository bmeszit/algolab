#include<bits/stdc++.h>
using namespace std;

struct boy { vector<int> ord; int i; };
struct girl { vector<int> rank; int i; };

struct gale_shapely
{
  int n, m;
  vector<boy> b; // Fiúk
  vector<girl> g; // Lányok
  
  gale_shapely(int n, int m) : n(n), m(m)
  {
    b.assign(n, { ord: {}, i: 0 });
    g.assign(m, { rank: vector<int>(n, -1), i: -1 });
  }

  void b_ord_next(int bi, int gi) { b[bi].ord.push_back(gi); }
  void g_rank(int gi, int bi, int p) { g[gi].rank[bi] = p; }

  int propose(int bi)
  {
    boy& bx = b[bi];
  
    // Ha nincs felkérhető lány, nem próbálkozunk tovább.
    if(bx.ord.size() <= bx.i) return -1;
  
    // Ha a következő lány nem ismeri a fiút, próbálkozunk tovább.
    // Irányítatlan élekre ezt nem kell külön nézni.
    if(g[bx.ord[bx.i]].rank[bi] == -1) { ++bx.i; return bi; }
  
    girl& gx = g[bx.ord[bx.i]];
  
    // Ha a lánynak nincs párja, akkor sikerült!
    if(gx.i == -1) { gx.i = bi; return -1; }
  
    // Ha a lány mostani párja jobb, próbálkozunk tovább.
    if(gx.rank[gx.i] < gx.rank[bi])  { ++bx.i; return bi; }
  
    // Egyébként a mostani párt elutasítja a lány.
    int bo = gx.i; gx.i = bi;
    ++b[bo].i; return bo;
  }

  void run()
  {
    for(int i=0; i<n; ++i)
    {
      int bi = i;
      while(bi != -1) bi = propose(bi);
    }
  }
};



int main()
{
  int n, m; cin>>n>>m;
  gale_shapely gs(n, m), gs_rev(m, n);
  
  for(int i=0; i<n; ++i)
  {
    int k; cin>>k;
    for(int j=0; j<k; ++j)
    {
      int x; cin>>x; --x;
      gs_rev.g_rank(i, x, j);
      gs.b_ord_next(i, x);
    }
  }
  for(int i=0; i<m; ++i)
  {
    int k; cin>>k;
    for(int j=0; j<k; ++j)
    {
      int x; cin>>x; --x;
      gs.g_rank(i, x, j);
      gs_rev.b_ord_next(i, x);
    }
  }

  gs.run();
  gs_rev.run();

  for(int bi=0; bi<n; ++bi)
  {
    auto& bx = gs.b[bi];
    auto& bx_rev = gs_rev.g[bi];
    cout << bx_rev.rank[bx_rev.i] - bx.i << endl;
  }
  for(int gi=0; gi<m; ++gi)
  {
    auto& gx = gs.g[gi];
    auto& gx_rev = gs_rev.b[gi];
    cout << gx.rank[gx.i] - gx_rev.i << endl;
  }
  return 0;
}
