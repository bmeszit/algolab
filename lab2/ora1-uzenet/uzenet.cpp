#include<bits/stdc++.h>
using namespace std;

// Futtassunk egy szélességi keresést a kezdőcsúcsból kiindulva!

// Bemenet:
int n, m; // csúcsok és élek darabszáma
vector<vector<int>> adj; // éllista: adj[v] a v. csúcs szomszédait tartalmazza

// Szélességi keresés eredménye:
vector<int> p; // p[v] a v. csúcs szülője
vector<int> d; // d[v] a v. csúcs távolsága a kezdőcsúcstól

// Informatikus "végtelen" :)
const int infty = numeric_limits<int>::max();

// Használjunk egy segédfüggvényt, ami majd az elkészült p tömb alapján kiírja
// a from csúcsból a to csúcsba az útvonalat:
void print_path(int from, int to)
{
  // Az útvonalat az r listába mentjük el:
  vector<int> r;

  // Kiindulunk a legalsó to csúcsból:
  int curr=to; r.push_back(to);
  // Lépkedünk a p tömböt használva felfele a szülőkön,
  // egészen addig amíg el nem érjük a legfelső from csúcsot:
  while(curr!=from)
  {
    // Fellépünk a szülőbe:
    curr = p[curr];
    // Elmentjük:
    r.push_back(curr);
  }

  // Kiírjuk az r lista tartalmát, de mivel visszafele
  // lépkedtünk, ezért fordított sorrendben kell kiírni:
  cout << r.size() << endl;
  for(int i=r.size()-1; 0<=i; --i)
  {
    cout << r[i]+1 << " ";
  }
  cout << endl;
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

  // Jelöljük az ismeretlen szülőt -1-el,
  // a kezdő 0. csúcs szülőjét -2-vel.
  p.assign(n, -1); p[0]=-2;
  // A kezdőcsúcs önmagától 0 távolságra van,
  // az ismeretlen távolságokat szokásosan végtelennel jelöljük,
  // bár ebben a kódban ez nem számít, de pl. a Dijkstra-nál 
  // így lesz kényelmes.
  d.assign(n, infty); d[0]=0;

  // Készítsünk egy várakozási sort, amibe a megtalált, de még
  // nem kifejtett csúcsokat tesszük. Tegyük bele a kezdőcsúcsot!
  queue<int> q; q.push(0);
  // Amíg van várakozó csúcs, addig fut az algoritmus...
  while(!q.empty())
  {
    // Vegyük elő a soron következő elemet:
    auto v = q.front(); q.pop();
    // Nézzük végig a szomszédait:
    for(auto& u: adj[v])
    {
      // Minden olyan u szomszédra, akit még nem találtunk meg:
      if(p[u] != -1) continue;

      // Vegyük fel a várakozási sorba:
      q.push(u);
      // Továbbá jegyezzük fel, hogy u szülője v:
      p[u] = v;
      // Illetve, hogy milyen távol van a kezdőcsúcstól:
      d[u] = d[v]+1;
    }
  }
  // A szélességi keresés végén:

  // Ha a szélességi keresés nem találta meg az n-1. csúcsot,
  // akkor az nem elérhető a 0.-ból:
  if(p[n-1]==-1)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  // Ha viszont elérhető, akkor meg kell mondani, hogy milyen csúcsok mentén:
  print_path(0, n-1);

  return 0;
}