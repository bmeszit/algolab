#include<bits/stdc++.h>
using namespace std;

struct boy { vector<int> ord; int i; };
struct girl { vector<int> rank; int i; };

int n, m;
vector<boy> b; // Fiúk
vector<girl> g; // Lányok

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

int main()
{
  cin>>n>>m;
  b.assign(n, { ord: {}, i: 0 });
  g.assign(m, { rank: vector<int>(n, -1), i: -1 });

  for(int i=0; i<n; ++i)
  {
    int k; cin>>k;
    for(int j=0; j<k; ++j)
    {
      int x; cin>>x; --x;
      b[i].ord.push_back(x);
    }
  }
  for(int i=0; i<m; ++i)
  {
    int k; cin>>k;
    for(int j=0; j<k; ++j)
    {
      int x; cin>>x; --x;
      g[i].rank[x]=j;
    }
  }

  for(int i=0; i<n; ++i)
  {
    int bi = i;
    while(bi != -1) bi = propose(bi);
  }
  
  int cnt=0;
  for(int i=0; i<m; ++i) cnt += g[i].i != -1;
  cout<<cnt<<endl;
  for(int i=0; i<m; ++i)
  {
    if(g[i].i == -1) continue;
    cout << g[i].i+1 << " " << i+1 << endl;
  }
  return 0;
}
