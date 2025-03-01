#include<bits/stdc++.h>
using namespace std;

// A feladat a gráf egy Euler-körsétájának a megtalálása.
// Euler-körséta pontosan akkor van a gráfban, ha
// (1) összefüggő és
// (2) minden fokszáma páros.

// Bemenet:
int n, m; // csúcsok és élek darabszáma
vector<vector<int>> adj; // éllista: adj[v] a v. csúcs szomszédait tartalmazza

// Az összefüggőséget többféleképpen eldönthetjük, például egy DFS futtatásával
// és a megtalált csúcsok megjelölésével.
vector<bool> visited; // visited[v]=true, ha a v. csúcsot megtaláltuk.
void dfs(int v)
{
  visited[v]=true;
  for(auto& u: adj[v])
  {
    if(visited[u]) continue;
    dfs(u);
  }
}

// Amennyiben már tudjuk, hogy van Euler-körséta a gráfban, úgy azt a
// következőképpen találhatjuk meg:

// Problémát okoz a feladatban, hogy a gráf irányítatlan, így minden él kétszer
// szerepel az adj tömbben (mindkét irányban). Az Euler-körséta során, ha egy
// élet használunk, annak fordított irányú párját sem használhatjuk már.
// Ezt egy globális set-tel követjük, ami a használt éleket tárolja.
// A c++ set piros-fekete fa alapú, ezért a beszúrás és a keresés is O(log m)
// időben történik.
set<pair<int,int>> used;


// Az algoritmus lényege: mohón "szaladunk" előre az éleken amíg tudunk és felírjuk
// magunknak a menet közben látott csúcsokat. Mivel minden csúcs foka páros, a szaladásunkkal
// a kezdőpontban fogunk elakadni, ezzel egy valamekkora körsétát kapva a gráfban.
// Ha szerencsénk van, akkor pont úgy szaladtunk, hogy a gráf összes élét el is használtuk és a
// felírt csúcsok máris az Euler-körsétát adják a gráfban.
// Ha nincs szerencsénk, akkor maradhatott a megtalált körséta mentén olyan v csúcs, akinek még van
// nem bejárt éle. Ilyenkor ebből a csúcsból meg kell ismételni a mohó szaladást és a most
// felírt csúcsokat be kell szúrni az eredeti listánkba a v csúcs helyére, ezáltal egy
// nagyobb körsétát kapva a gráfban.
// Ezt az eljárást addig kell ismételni, amíg maradt még nem bejárt éle a gráfnak.

// Szépen úgy lehet implementálni ezt az algoritmust, hogy a megtalált csúcsokat egy veremben
// tesszük el és amikor elakadunk, akkor elkezdjük kiolvasni a verem tartalmát és csak akkor kiírni
// az adott csúcsot, ha annak már nincs nem bejárt éle.
// Ha pedig van nem bejárt éle a csúcsnak, akkor ismételten elindulunk annak a mentén és 
// tesszük el a verembe a megtalált csúcsokat.
// Látható, hogy ezzel a módszerrel pont a fenti "kézi" algoritmus által megtalált sorrend
// fordítottját fogjuk a kimenetre írni, ami az irányítatlan élek miatt szintén egy Euler-körsétája a gráfnak.

// Veremként pedig ismét érdemes a függvényhívás vermét használni, amitől még tömörebb és letisztultabb kódot kapunk.
// Itt megjegyzendő, hogy operációs rendszertől függően előfordulhat, hogy a függvényhívás vermen valamilyen
// szigorú méretkorlát van beállítva, ami miatt "stack overflow" hibát kaphatunk az egyébként helyes,
// csak nagy mélységű rekurzív hívásokat használó kódunkkal.
// Ezt a Linuxos tesztelő scriptben egy `ulimit -s 65536` parancs kiadásával oldottam meg, ami növeli a stack méretét.
// (A különböző versenyeken használt beadórendszerekben is általában be van ez állítva.)

// Csodáljuk meg milyen szép és rövid lett ezáltal a fent bemutatott algoritmus kódja:
void euler(int v)
{
  while(!adj[v].empty())
  {
    // Annak érdekében, hogy hatékony legyen az algoritmusunk,
    // azokat az éleket amiket éppen elhasználunk érdemes kivenni
    // az éllistából, mivel az adott v csúcsot a rekurzió több szinten
    // is megtalálhatja és nem akarjuk, hogy a már elhasznált éleket
    // mindegyik hívásnak feleslegesen végig kelljen újra néznie.
    // Nagyon figyeljünk arra, hogy itt most egy közös adj[v] tömböt
    // módosítgatunk "kvázi párhuzamosan", ezért olyan implementációt
    // kell adnunk, ami nem próbál meg emlékezni a tömb méretére az
    // éleken történő iterációhoz. Például így:
    auto u = adj[v].back(); adj[v].pop_back();
    auto edge = make_pair(min(u,v),max(u,v));
    if(!used.contains(edge))
    {
      used.insert(edge);
      euler(u);
    }
  }
  cout << v+1 << " ";
}
 
int main()
{
  cin>>n>>m;
  adj.assign(n, {});
  visited.assign(n, false);
 
  for(int i=0; i<m; ++i)
  {
    int v, u; cin>>v>>u; --v; --u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
 
  // Ellenőrizzük le, hogy összefüggő és páros fokú a gráfunk:
  dfs(0);
  for(int v=0; v<n; ++v)
  {
    if((!visited[v] && adj[v].size()) || adj[v].size()%2)
    {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
 
  // Indítsuk a körséta keresését 0. csúcsból, ahol a posta van:
  euler(0);
  cout << endl;
  
  return 0;
}