/*
   A feladatban annyi a trükk, hogy meg kell fordítani az időt, azaz visszafele
   sorrendben kell megválaszolni a kérdéseket. Ekkor az éltörlésekből
   élbeszúrások lesznek, amit az unió-holvan adatszerkezet szépen tud kezelni.
   A komponensek darabszámát pedig az unió műveletek közben tartjuk nyilván.

   A lenti kód inkább olvasható, van pár dolog benne amit felesleges csinálni,
   de azért ordóban ugyanott van.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;

// Tároljuk egy piros-fekete fában a gráf összes élét.
// Először beolvasunk majd minden élet, majd úgy sorrendezzük
// őket, hogy előre kerüljenek a törlendők, megfelelő sorrendben,
// a végére pedig a maradék. Ehhez kell tudni gyorsan törölni g-ből:
set<pair<int, int>> g;

// Rendezett pár konstruktor:
// Az élek irányítatlanok, gonosz módon egyetlen teszteset
// egyetlen éle miatt szükség van rá, hogy rendezett párokként
// tároljuk őket.
pair<int,int> ord(int a, int b) { return { min(a, b), max(a, b) }; }

// Unió holvan adatszerkezet:
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

  void merge(int i, int j)
  {
    i = find(i);
    j = find(j);
    if (i == j) return;
    if (s[i] < s[j]) swap(i, j);
    s[i] += s[j];
    p[j] = i;
    --cnt;
  }
};

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin>>n>>m>>k;
  g.clear();
  // Beolvassuk az összes élet:
  for(int i=0; i<m; ++i)
  {
    int a, b; cin>>a>>b; --a; --b;
    g.insert(ord(a, b));
  }

  vector<pair<int, int>> e;
  for(int i=0; i<k; ++i)
  {
    // Olvassuk be a törlendő éleket:
    int a, b; cin>>a>>b; --a; --b;
    // Tároljuk el őket a megfelelő sorrendben:
    e.push_back(ord(a,b));
    // A végső gráfból predig töröljük ki őket:
    g.erase(ord(a,b));
  }
  // A maradék éleket is tegyük a sorrend végére, mintha
  // az egész gráfot teljesen törölnénk.
  for(auto& gx: g) e.push_back(gx);
  // Fordítsuk meg az időt, mostmár behúzni kell az éleket:
  reverse(e.begin(), e.end());

  // Játsszuk végig az élek behúzását:
  dsu d(n);
  vector<int> comp(m);
  for(int i=0; i<m; ++i)
  {
    // Menet közben mentsük el a komponensek számát:
    comp[i]=d.cnt;
    auto& [a, b] = e[i];
    d.merge(a, b);
  }
  
  // Fordítsuk vissza az időt jó irányba:
  reverse(comp.begin(), comp.end());
  
  // Írjuk ki az eredményt:
  for(int i=0; i<k; ++i)
  {
    cout << comp[i] << " ";
  }
  cout << endl;
  return 0;
}
