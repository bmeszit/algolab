#include<bits/stdc++.h>
using namespace std;

// A feladat találni egy tetszőleges kört (akár hurokélet) a gráfban.
// Pontosan akkor van kör a gráfban, ha egy DFS futás során találunk
// valamilyen v->u visszaélet. Továbbá, egy lehetséges ehhez tartozó
// kör élei ekkor éppen a v->u visszaél, illetve az u-ból a v-be menő faélek lesznek.

// Bemenet:
int n, m; // csúcsok és élek darabszáma
vector<vector<int>> adj; // éllista: adj[v] a v. csúcs ki-szomszédait tartalmazza

// A mélységi keresés eredménye:
vector<int> mszam; // mszam[v] a v. csúcs mélysési száma.
vector<int> bszam; // bszam[v] a v. csúcs befejezési száma.
vector<int> p; // p[v] a v. csúcs szülője a DFS fában, vagyis a faéleket tartalmazza.

// Hasonlóan az ora3-utemezes feladathoz, rekurzív implementáció:
int mszam_next=0;
int bszam_next=0;
void dfs(int v)
{
  mszam[v] = mszam_next++;
  for(auto& u: adj[v])
  {
    if(mszam[u] != -1) continue;
    // Ebben az implementációban az u csúcs szülőjét is elmentjük:
    p[u]=v;
    dfs(u);
  }
  bszam[v] = bszam_next++;
}

// Hasonlóan az ora3-utemezes feladathoz, egy v->u él visszaélségét így ellenőrizzük:
bool is_backedge(int v, int u)
{
  return (mszam[u] <= mszam[v]) && (bszam[v] <= bszam[u]);
}

// Használjunk az ora1-uzenet feladatban megismert segédfüggvényt a faélek
// mentén lépkedésre, azzal a különbséggel, hogy most kört akarunk kiírni,
// ezért a v-t az elején és a végén is kiírjuk.
// A v->u egy megtalált visszaél, tehát az u->v útvonalat akarjuk kiírni.
void print_cycle(int u, int v)
{
  vector<int> r;
  int curr=v; r.push_back(v);
  while(curr!=u)
  {
    curr = p[curr];
    r.push_back(curr);
  }
  r.push_back(v);

  cout << r.size() << endl;
  for(int i=r.size()-1; 0<=i; --i)
  {
    cout << r[i]+1 << " ";
  }
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

  // Az ismeretlen mszam, bszam és p legyen -1-el jelölve.
  mszam.assign(n, -1);
  bszam.assign(n, -1);
  p.assign(n, -1);

  // Ha a gráf nem összefüggő, akkor a DFS-t addig kell hívogatni
  // még meg nem talált csúcsokból, amíg mindegyiket meg nem találjuk.
  for(int v=0; v<n; ++v)
  {
    if(mszam[v]!=-1) continue;
    // Általában célszerű megjelölni a megtalált fák gyökereit, hogy ne keverjük
    // őket össze a még nem megtalált csúcsokkal:
    p[v]=-2; 
    dfs(v);
  }

  // A DFS futása után nézzük meg találtunk-e visszaélet a gráfban:
  for(int v=0; v<n; ++v)
  for(auto& u: adj[v])
  {
    if(!is_backedge(v, u)) continue;
    // Ha találtunk, akkor írjuk ki és álljunk meg:
    print_cycle(u, v);
    return 0;
  }

  // Ha eddig nem álltunk meg, akkor nincs visszaél, tehát nincs kör a gráfban:
  cout << "IMPOSSIBLE" << endl;
  return 0;
}