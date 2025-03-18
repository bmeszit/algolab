#include<bits/stdc++.h>
using namespace std;

// A feladat egy topologikus sorrend megtalálását kéri tőlünk.
// Amennyiben van topologikus sorrend, úgy jó sorrend lesz például
// egy mélységi keresésben talált befejezési számok szerinti
// fordított sorrendje a csúcsoknak. Ezt fogjuk most megtalálni.

// Bemenet:
int n, m; // csúcsok és élek darabszáma
vector<vector<int>> adj; // éllista: adj[v] a v. csúcs ki-szomszédait tartalmazza

// A mélységi keresés eredménye:
vector<int> mszam; // mszam[v] a v. csúcs mélysési száma.
vector<int> bszam; // bszam[v] a v. csúcs befejezési száma.

// Ezek a számok globálisan egyediek, a rekurzív függvényünk
// két globális változót használ arra, hogy számon tartsa
// melyik következő számot kell majd kiosztania.
// Informatikusként továbbra is 0-tól kezdve sorszámozunk.
int mszam_next=0;
int bszam_next=0;

// A DFS-re úgy is gondolhatunk, mintha valami olyasmit csinálnánk
// mint a BFS, csak várakozási sor helyett egy vermet használnánk.
// Nagyon szép kódot eredményez, ha veremként magát a függvényhívási
// vermet használjuk, azaz egy rekurzív függvényként implementáljuk
// a DFS-t (adott v csúcsból).
void dfs(int v)
{
  // A v csúcsnak a megtalálás pillanatában adunk mélységi számot,
  // ami a rekurzív függvény legelső utasítása.
  mszam[v] = mszam_next++; // A globális számlálót értékadás után növeljük 1-el.
  // Ezek után v minden ki-szomszédján végigmegyünk:
  for(auto& u: adj[v])
  {
    // Ha az adott szomszédot már megtaláltuk (van mszam-ja), akkor skippeljük:
    if(mszam[u] != -1) continue;
    // Egyébként pedig arra is rekurzívan meghívjuk a DFS-t.
    dfs(u);
  }
  // A v csúcs akkor kap befejezési számot, amikor már minden gyerekét
  // kifejtettük, ez a rekurzív függvény legutolsó utasítása.
  bszam[v] = bszam_next++; // A globális számlálót értékadás után növeljük 1-el.
}

// Topologikus sorrend pontosan akkor van, ha nem talál a DFS visszaélet a futása során.
bool is_backedge(int v, int u)
{
  // Egy v->u él pontosan akkor visszaél, ha u mélységi száma kisebb,
  // a befejezési száma viszont nagyobb a v-nél.
  return (mszam[u] <= mszam[v]) && (bszam[v] <= bszam[u]);
}

// Segédfüggvény, ami végignézi az összes élet és eldönti van-e köztük visszaél:
bool has_backedge()
{
  for(int v=0; v<n; ++v)
  for(auto& u: adj[v])
  {
    if(is_backedge(v, u)) return true;
  }
  return false;
}

int main()
{
  // Olvassuk be a bemeneti adatokat:
  cin>>n>>m;
  adj.assign(n, {});
  for(int i=0; i<m; ++i)
  {
    // Praktikus átsorszámozni a csúcsokat 0-tól n-1-ig,
    // hiszen a tömböket is úgy sorszámozzuk:
    int v, u; cin>>v>>u; --v; --u;
    // Mivel a gráf irányított, az éleket most csak egy irányban vesszük fel:
    adj[v].push_back(u);
  }

  // Az ismeretlen mszam és bszam legyen -1-el jelölve.
  mszam.assign(n, -1);
  bszam.assign(n, -1);

  // Ha a gráf nem összefüggő, akkor a DFS-t addig kell hívogatni
  // még meg nem talált csúcsokból, amíg mindegyiket meg nem találjuk.
  for(int v=0; v<n; ++v)
  {
    // Ha v-t már korábbi iterációban láttuk, akkor rá nem hívunk DFS-t:
    if(mszam[v]!=-1) continue;
    dfs(v);
  }

  // Ha van a gráfban visszaél, akkor nincs topologikus sorrendje:
  if(has_backedge())
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  // Ellenkező esetben készítsük el a topologikus sorrendet a topo tömbben:
  vector<int> topo(n, -1);
  // Iteráljunk végig a csúcsokon:
  for(int v=0; v<n; ++v)
  {
    // A bszam tömb tudjuk, hogy 0 és n-1 közötti értékeket tartalmaz,
    // ezért ezért a v csúcs helye a topologikus sorrendben
    // pontosan az n-1-bszam[v].
    topo[n-1-bszam[v]] = v;
  }

  // Végül írjuk ki a kimenetre a megtalált topologikus sorrendet:
  for(int i=0; i<n; ++i)
  {
    cout << topo[i]+1 << " ";
  }
  
  return 0;
}