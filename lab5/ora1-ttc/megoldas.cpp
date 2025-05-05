#include<bits/stdc++.h>
using namespace std;

int n; // Lakástulajok száma.
vector<int> state; // Lakástulaj állapota.
enum { unmatched=-1, matched=-2 }; // Spec. állapotcímkék.
vector<int> point; // Lakástulaj kire mutat.
vector<vector<int>> ord; // Preferenciasorrendek.

int main()
{
  cin>>n;
  ord.assign(n, vector<int>(n));
  for(int i=0; i<n; ++i)
  {
    for(int j=0; j<n; ++j) { cin>>ord[i][j]; --ord[i][j]; }
    reverse(ord[i].begin(), ord[i].end()); // Megfordítjuk: végéről gyors törölni.
  }

  int done=0; // Hány tulaj távozott eddig.
  state.assign(n, unmatched);
  point.assign(n, -1);
  while(done<n)
  {
    // Minden játékban lévő rámutat a neki legszimpatikusabb játékban lévőre.
    for(int i=0; i<n; ++i)
    {
      if(state[i]==matched) continue;
      while(state[ord[i].back()]==matched) ord[i].pop_back();
      point[i] = ord[i].back();
    }
    // Megkeressük a kialakult köröket:
    // Mivel a mutatásokból álló gráfban mindenkinek 1 a kifoka,
    // pontosan akkor van kör a gráfban
    // Minden játékban lévő és korábban nem kezelt csúcsra:
    for(int v=0; v<n; ++v)
    {
      if(state[v]!=unmatched) continue;
      // Megyünk előre amíg el nem akadunk.
      int u=v; while(state[u]==unmatched)
      {
        state[u]=v; // Ideiglenes állapot = v. körben talált útvonalon vagyunk.
        u=point[u];
      }
      // Ha nem a saját útvonalunkban akadtunk el akkor nincs kör.
      if(state[u]!=v) continue; 
      // Ha a saját utunkban akadtunk el, akkor a talált körben lévő tulajok készen vannak.
      int c=u; do
      {
        state[u]=matched; ++done;
        u = point[u];
      } while(u!=c);
    }
    // Az ideiglenes állapotjelzőket töröljük.
    for(int v=0; v<n; ++v)
    {
      if(state[v]!=matched) state[v]=unmatched;
    }
  }
  for(int v=0; v<n; ++v) cout<<point[v]+1<<endl;
  return 0;
}