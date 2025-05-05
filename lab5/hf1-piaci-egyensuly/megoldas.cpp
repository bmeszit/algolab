// Az Algojátékból tanultak alapján:
// Lefuttatjuk a TTC-t és a távozási sorrend szerint csökkenően árazunk.

#include<bits/stdc++.h>
using namespace std;

int n; // Lakástulajok száma.
vector<int> state; // Lakástulaj állapota.
vector<int> pick; // Lakástulaj kire mutat.
vector<int> price; // Adott lakástulaj lakásának az ára.
vector<vector<int>> ord; // Preferenciasorrendek.

enum { fresh = -1, matched = -2 };  // Spec. állapotcímkék.

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
  state.assign(n, fresh);
  pick.assign(n, -1);
  price.assign(n, -1);
  while(done<n)
  {
    // Minden játékban lévő rámutat a neki legszimpatikusabb játékban lévőre.
    for(int i=0; i<n; ++i)
    {
      if(state[i]==matched) continue;
      while(state[ord[i].back()]==matched) ord[i].pop_back();
      pick[i] = ord[i].back();
    }
    // Megkeressük a kialakult köröket:
    // Mivel a mutatásokból álló gráfban mindenkinek 1 a kifoka,
    // pontosan akkor van kör a gráfban
    // Minden játékban lévő és korábban nem kezelt csúcsra:
    for(int v=0; v<n; ++v)
    {
      if(state[v]!=fresh) continue;
      // Megyünk előre amíg el nem akadunk.
      int u=v; while(state[u]==fresh)
      {
        state[u]=v; // Ideiglenes állapot = v. körben talált útvonalon vagyunk.
        u=pick[u];
      }
      // Ha nem a saját útvonalunkban akadtunk el akkor nincs kör.
      if(state[u]!=v) continue; 
      // Ha a saját utunkban akadtunk el, akkor a talált körben lévő tulajok készen vannak.
      int c=u; do
      {
        state[u]=matched; ++done;
        u = pick[u];
      } while(u!=c);
    }
    for(int v=0; v<n; ++v)
    {
      // Beállítjuk az árat:
      // A TTC-ből való távozási sorrend szerint csökkenően kell árazni.
      // Például n+1-(eddig távozottak száma) egy jó árérték.
      if(state[v]==matched && price[v]==-1) price[v]=n-done+1;
      // Az ideiglenes állapotjelzőket töröljük.
      if(state[v]!=matched) state[v]=fresh;
    }
  }
  for(int v=0; v<n; ++v) cout<<price[v]<<endl;
  return 0;
}