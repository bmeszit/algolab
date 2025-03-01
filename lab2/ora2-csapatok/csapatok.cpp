#include<bits/stdc++.h>
using namespace std;

// Futtassunk egy szélességi keresést a kezdőcsúcsból kiindulva!
// Ha páros a gráf, akkor jó 2-színezés például a szélességi keresés
// eredményében a páros szinteknek adni az egyik színt,
// a páratlanoknak pedig a másikat.

// Bemenet:
int n, m; // csúcsok és élek darabszáma
vector<vector<int>> adj; // éllista: adj[v] a v. csúcs szomszédait tartalmazza

// Szélességi keresés eredménye:
// p[v] a v. csúcs szülője
vector<int> p;
// A color[v] értéke 0 vagy 1, a v. csúcs színétől függően,
// továbbá 2 jelöli a még színezetlen csúcsokat menet közben.
vector<int> color;

// Itt azért készült egy segédfüggvény a bfs-hez, mert
// a függvény visszatérési értékén keresztül jelzem, hogy
// 2-színezhető-e a gráf.
bool bfs(int from)
{
  // A kezdőcsúcsra beállítom a speciális "szülő" értéket
  // továbbá 0-ás színnel színezem.
  p[from]=-2; color[from]=0;
  // Várakozási sor a megtalált de még nem kifejtett csúcsokra:
  queue<int> q; q.push(from);
  // Amíg várakozik csúcs...
  while(!q.empty())
  {
    // ... vegyük elő a soron következőt és dolgozzuk fel:
    auto v = q.front(); q.pop();
    // Vizsgáljuk meg v minden szomszédját:
    for(auto& u: adj[v])
    {
      // Ha ezt az u csúcsot már kiszíneztük, akkor ellenőrizzük a színét v-hez képest:
      if(color[u] != 2)
      {
        // Ha azonos színűek, akkor a gráf nem lehet páros.
        // Figyeljük meg, hogy itt két egymásba ágyazott ciklus belsejéből
        // térek vissza azonnal, egy false-al. Ez azért sokkal praktikusabb így,
        // mert például egy break parancs csak a belső ciklust szakítaná meg.
        if(color[u] != 1-color[v]) return false;
        continue;
      }

      // Ha pedig most látjuk először az u-t, akkor tegyük be a várakozási sorba:
      q.push(u);
      // Továbbá mentsük el, hogy v a szülője
      p[u] = v;
      // és színezzük meg a v-vel ellentétes színnel.
      color[u] = 1-color[v];
    }
  }
  return true;
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
    // Mivel a gráf irányítatlan, az éleket mindkét irányban felvesszük:
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  // Az ismeretlen szülőt -1-el jelöljük:
  p.assign(n, -1);
  // Az ismeretlen színt 2-vel jelöljük:
  color.assign(n, 2);

  // Ha a gráf nem összefüggő, akkor a bfs-t addig kell hívogatni
  // még meg nem talált csúcsokból, amíg mindegyiket meg nem találjuk.
  for(int v=0; v<n; ++v)
  {
    // Ha v-t már korábbi iterációban láttuk, akkor rá nem hívunk BFS-t:
    if(p[v]!=-1) continue;
    // Meghívjuk a BFS-t a még nem látott csúcsra:
    if(!bfs(v))
    {
      // Ha kiderül róla, hogy az ő komponense nem páros, akkor ezt rögtön jelezzük
      cout << "IMPOSSIBLE" << endl;
      // és le is állunk a programmal.
      return 0;
    }
  }
  
  // Ha nem volt semmi gond, akkor pedig kiírjuk a megtalált színezést.
  for(auto& c: color)
  {
    // A feladat 1-től sorszámozza a színeket (1 és 2):
    cout << c+1 << " ";
  }
  cout << endl;

  return 0;
}