/*
   Értelmezzük az érmemátrixot egy páros gráf "szomszédossági mátrixaként",
   olyan értelemben, hogy az egyik partíció csúcsai a sorok, a másikéi pedig
   az oszlopok, él pedig akkor megy két csúcs között, ha a hozzájuk tartozó sor
   és oszlop metszetében lévő cellában van érme.

   A feladat ekkor éppen egy minimális lefogó csúcshalmaz keresése. BSZ2-ből
   tanultuk, hogy páros gráfban minimális lefogó csúcshalmazt konstruálhatunk
   például a javítóutas algoritmus végén keletkező halmazok alapján, lásd:

   http://cs.bme.hu/bsz2/bsz2_jegyzet.pdf 91. oldal, 7.16. lemma

   A csúcshalmaz az egyik partíció fedetlen csúcsaiból alternáló úton elérhető
   csúcsok párjaiból, továbbá a nem elérhetőkből fog állni.

   Figyelem: Nem lesz igaz az, hogy egy maximális párosítás egyik oldala lefogó
   ponthalmaz lenne, erre ellenpéldát láthatunk a
   
   tesztek/ellenpelda_parositas_egyik_oldala.in

   nevű tesztesetben, amit az ellenpelda.jpg fájlban is felrajzoltam: a max
   párosítás semelyik oldala sem lesz lefogó csúcshalmaz, a lila színű
   csúcsokat kell venni.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;
vector<vector<int>> g;

vector<int> mt, rmt;
vector<bool> used;
bool kuhn(int v)
{
  if (used[v]) return false;
  used[v]=true;
  for (int to : g[v])
  {
    if (mt[to] == -1 || kuhn(mt[to]))
    {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

vector<bool> reached;
void reach(int v)
{
  if(reached[v]) return;
  reached[v]=true;
  for (int to : g[v])
  {
    if (mt[to] != -1) reach(mt[to]);
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin>>n;
  g.assign(n, {});
  for(int i=0; i<n; ++i)
  {
    string a; cin>>a;
    for(int j=0; j<n; ++j)
    {
      if(a[j] == 'o') g[i].push_back(j);
    }
  }

  // Először futtatjuk a javítóutas algoritmust,
  // a max párosítás mérete egyezni fog a min lefogó
  // ponthalmaz méretével, ezt követjük az ans változóban.
  int ans=0;
  mt.assign(n, -1);
  for(int v=0; v<n; ++v)
  {
    used.assign(n, false);
    ans += kuhn(v);
  }

  // Az mt tömb a "matching" rövidítése, az egyik oldal párjait tartalmazza.
  // Az rmt-be pedig invertáljuk a tömböt, hogy a másik oldali párjait tartalmazza.
  rmt.assign(n, -1);
  for(int v=0; v<n; ++v)
  {
    if(mt[v] != -1) rmt[mt[v]] = v;
  }

  // Megkeressük a fedetlenekből elérhetőket / nem elérhetőket.
  reached.assign(n, false);
  for(int v=0; v<n; ++v)
  {
    if(rmt[v] == -1) reach(v);
  }

  cout << ans << endl;
  for(int v=0; v<n; ++v)
  {
    if(rmt[v] == -1) continue;

    // Min lefogó ponthalmaz: a fedettek közül...
    // ... az elérhetők párjai
    if(reached[v]) cout << "2 " << rmt[v]+1 << endl;
    // ... és a nem elérhetők.
    else cout << "1 " << v+1 << endl;
  }
  return 0;
}
