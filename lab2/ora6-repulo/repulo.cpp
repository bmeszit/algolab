#include <bits/stdc++.h>
using namespace std;

// A feladatunk egy Dijkstra algoritmus implementálása.

// Elég nagy értékek is előfordulhatnak, ezért használjunk 64 bites számokat.
const int64_t infty = numeric_limits<int64_t>::max();

// A Dijkstra hatékony implementációjához célszerű min-kupacot használni
// lineáris minimum keresés helyett: c++-ban a priority_queue adatszerkezet
// egy max-kupac. Ebből min-kupacot gyorsan a beírt értékek -1 -el való
// szorzásával lehet gyártani, azonban template paraméterekkel megkérhető maga
// az adatszerkezet is arra, hogy min-kupacként viselkedjen, ez szebb megoldás.

// A kupacban két adatot szeretnék tárolni: mi az adott csúcs indexe és
// milyen távolságbecslést tudok róla jelenleg.
// A pair adatszerkezet egy két elemű tuple, aminek az *első* paraméterébe
// fogom a távolságot tenni és a második paramétre lesz a hozzá tartozó
// csúcsindex. Ezt azért csinálom így, mert a beépített komparátor függvény
// a paramétereket a megadott sorrendben veszi figyelembe és én a távolság
// szerint szeretném sorrendezni őket (egyenlő távolság esetén pedig
// nem számít kit választunk, itt most a kisebb indexűeket fogjuk választani).
using heap_data = pair<int64_t, int>;
// A priority_queue generikus osztály template paraméterei pedig a következők:
// (1) az elemek típusa heap_data, (2) az "underlying" adattároló egy sima tömb,
// (3) az összehasonlító operátor, ami greater estén eredményez min-kupacot, lásd:
// https://en.cppreference.com/w/cpp/container/priority_queue#Template_parameters
using min_heap = priority_queue<heap_data, vector<heap_data>, greater<heap_data>>;

// Bemenet:
int n, m; // csúcsok és élek darabszáma
vector<vector<pair<int, int64_t>>> adj;  // éllista: adj[v] a v. csúcs szomszédai és a hozzájuk tartozó él súlya
vector<int64_t> d; // d[v] az aktuális távolságbecslés a v csúcsra

void dijkstra(int s)
{
  // Kezdetben a távolságbecslésünk minden csúcsra végtelen, kivéve a kezdőcsúcsra, akire 0.
  d.assign(n, infty); d[s]=0;

  // Tegyük be a kupacba a kezdőcsúcsot!
  min_heap next; next.push({d[s], s});
  while(!next.empty())
  {
    // Vegyük ki a kupacból a következő csúcsot!
    auto[dv, v] = next.top(); next.pop();
    // Figyeljünk rá, hogy egy csúcs többször is bekerülhetett a kupacba,
    // onnan látjuk, hogy v-t már feldolgoztuk, hogy a most megtalált
    // távolságbecslés rosszabb, mint amit a d[v] tartalmaz.
    if(d[v] < dv) continue;

    // Élmenti javításokat végzünk a v-ből kimenő éleken:
    for(auto& [u, w] : adj[v])
    {
      // Megnézzük v-n keresztül milyen hosszú úton érhető el az u:
      auto du = dv + w;
      if(d[u] <= du) continue;
      // Ha ez jobb mint eddig, akkor felírjuk:
      d[u] = du;
      next.push({d[u], u});
    }
  }
}

int main()
{
  cin>>n>>m;
  adj.assign(n, {});
  for(int i=0; i<m; ++i)
  {
    int v, u; int64_t w; cin>>v>>u>>w; --v; --u;
    adj[v].push_back({u, w});
  }

  dijkstra(0);
  
  for(int v=0; v<n; ++v) cout << d[v] << " ";
  cout << endl;

  return 0;
}
