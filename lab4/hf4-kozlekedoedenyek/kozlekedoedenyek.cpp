#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int n,q; cin>>n>>q;
  vector<int> pipes(n);
  // Olvassuk be a közlekedőedény méreteket: egy követeléshez
  // két közlekedőedény tartozik, melyek mérete a követelés fele-fele.
  for (int i=0; i<n; i++) { cin >> pipes[i]; pipes[i] /= 2; }
  // Rendezzük ezeket növekvő sorrendbe, hiszen a rendszer alsó
  // felében ilyen sorrendben telíti majd meg őket a víz.
  sort(pipes.begin(), pipes.end());
  
  // Amennyiben a szétosztandó vagyonmennyiség akkora, hogy az edényrendszer
  // alsó felében marad a víszint, úgy a következőképpen számolunk:
  // Lásd: edenyek.png
  // A közlekedőedényekben lévő víszint alakulása az elosztandó vagyon
  // függvényében egy szakaszosan lineáris függvény, aminek a töréspontjai
  // t_0=n*p_0
  // t_1=t_0+(n-1)*p_1
  // ...
  // t_{n-2}=t_{n-3}+2*p_{n-2}
  // t_{n-1}=t_{n-2}+1*p_{n-1}

  // Számítsuk ki ezeket:
  vector<int> psum(n+1, 0);
  for (int i=0; i<n; i++)
  {
    int prev = i == 0 ? 0 : pipes[i-1];
    psum[i+1]=psum[i]+(n-i)*(pipes[i]-prev);
  }
  
  for (int qi=0; qi<q; qi++)
  {
    int v; cin>>v;
    bool refl = false;
    // Amennyiben pedig a vagyonmennyiség akkora, hogy a felső felében
    // vagyunk az edényrendszernek, úgy helyette számolhatunk a fennmaradó
    // levegővel úgy, mintha az alsó félben lennénk:
    if(psum[n]<=v) { v=2*psum[n]-v; refl=true; }
    
    // Binárisan megkereshetjük melyik két töréspont között van a vísztint:
    int idx = lower_bound(psum.begin(), psum.end(), v) - psum.begin();

    // A két töréspont között pedig lineárisan interpolálunk:
    double level = 0.0;
    if(idx == 0) { level = 0.0; }
    else
    {
      int i = idx-1;
      int prev = (i == 0 ? 0 : pipes[i-1]);
      int cnt = n-i; 
      level = prev + (v-psum[i])/(double)cnt;
    }
    
    // Végül, ha most levegővel számoltunk, akkor visszaszámolunk vízmennyiségre:
    double ans = refl ? (2 * pipes[n-1] - level) : level;
    cout << fixed << setprecision(6) << ans << "\n";
  }
    
  return 0;
}
