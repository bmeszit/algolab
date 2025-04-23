/*
 * Vegyük észre, hogy az energiamegmaradás törvénye érvényesül a feladatban:
 * Tamás kezdeti (mozgási) energiája sosem vész el, pusztán átalakulhat
 * helyzeti energiává, a két energia összege pedig állandó marad végig.
 * 
 * Adott kezdeti összenergia mellett az a kérdés mely hegycsúcsok érhetők el:
 * modellezzük a feladatot egy gráffal, amelynek csúcsai a hegytetők, élei pedig
 * az irányítatlan túraútvonalak két hegytető között!
 * 
 * Modellezzük az élek átjárhatóságát úgy, hogy a magasabbik csúcs magasságát
 * írjuk rá az élekre. Bármely végpontjában is állunk az élnek, pontosan akkor
 * tudunk átmenni rajta, ha az összenergiánk legalább ennyi (nyilván a magasabbik
 * csúcsban ez mindenképp teljesül). Az összenergia pedig sosem változik, tehát
 * egy adott kezdeti összenergia mellett a gráf bizonyos élei aktívak lesznek,
 * a többi pedig szakadásként viselkedik.
 * 
 * Használjuk ezután az unió holvan adatszerkezetet a gráf összefüggőségének
 * számontartására, a következőképpen:
 * - Sorrendezzük az éleket rájuk írt érték szerint, illetve a lekérdezéseket
 *   a kezdeti összenergia szerint növekvő sorrendben.
 * - Minden lekérdezés előtt hajtsuk végre az uniót azokra az élekre, akiknél
 *   nem nagyobb a lekérdezéshez tartozó összenergia, majd kérdezzük meg, hogy
 *   ugyanabban a komponensben van-e a lekérdezés két végpontja. Ha igen, akkor
 *   van út a két csúcs között adott kezdeti energiával, egyébként nincs.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// (a,b): él, en: energiával
struct edge { int a, b, en; };
// i. lekérdezés a-ból b-be, en: kezdeti összenergiával, ans: válasszal
struct query {int a, b, en, i; bool ans; };

int n, m, q;

vector<int> h;
vector<edge> edges;
vector<query> queries;

struct dsu
{
  int n, cnt;
  vector<int> p, s;

  dsu(int n) : n(n), cnt(n), p(n), s(n, 1)
  {
    for(int i=0; i<n; ++i) p[i]=i;
  }

  int find(int i)
  {
    return p[i] == i ? i : p[i] = find(p[i]);
  }

  bool merge(int i, int j)
  {
    i = find(i);
    j = find(j);
    if (i == j) return false;
    if (s[i] < s[j]) swap(i, j);
    s[i] += s[j];
    p[j] = i;
    --cnt;
    return true;
  }
};

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin>>n>>m;
  h.assign(n, {});
  edges.assign(m, {});

  for(auto& hx: h) cin>>hx;
  for(auto& ex: edges)
  {
    cin>>ex.a>>ex.b; --ex.a; --ex.b;
    // Az élekre a magasabbik hegytető magasságát írjuk:
    ex.en=max(h[ex.a], h[ex.b]);
  }
  // Energia szerinti növekvő sorrendbe rendezzük őket:
  sort(edges.begin(), edges.end(),
    [](const edge& ex, const edge& ey) { return ex.en < ey.en; });

  cin>>q;
  queries.assign(q, {});
  for(int i=0; i<q; ++i)
  {
    auto& qx = queries[i];
    qx.i=i;
    cin>>qx.a>>qx.b>>qx.en; --qx.a; --qx.b;
    // A lekérdezéshez az összenergiát tároljuk, aminek része a helyzeti energia:
    qx.en+=h[qx.a];
  }
  // Ezeket is rendezzük energia szerinti növekvő sorrendbe:
  sort(queries.begin(), queries.end(),
    [](const query& qx, const query& qy) { return qx.en < qy.en; });

  dsu d(n);
  int j=0;
  for(int i=0; i<q; ++i)
  {
    // Az aktuális lekérdezéshez...
    auto& qx = queries[i];
    // ...összevonunk minden olyan élet, ami már átjárhatóvá
    // vált az adott energiaszint mellett ...
    while(j<m && edges[j].en <= qx.en)
    {
      d.merge(edges[j].a, edges[j].b);
      ++j;
    }
    // ... majd lekérdezzük egy komponensben vannak-e már a csúcsok:
    qx.ans = (d.find(qx.a) == d.find(qx.b));
  }
  // Végül visszarendezzük a kérdéseket index szerinti sorrendbe...
  sort(queries.begin(), queries.end(),
    [](const query& qx, const query& qy) { return qx.i < qy.i; });
  // ... és kiírjuk a válaszokat.
  for(auto& qx: queries)
  {
    cout << (qx.ans ? "YES" : "NO") << endl;
  }
  return 0;
}
