#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin>>n;

  // Hanyadik körben láttuk legutóbb az adott zeneszámot:
  vector<int> last_seen(n, -1);

  int ans=0;
  // A legkisebb olyan index, ahonnan nézve minden zeneszám egyedi i-ig:
  int j=0;
  for(int i=0; i<n; ++i)
  {
    int p; cin>>p; --p;

    // Ha p-t valahol j után láttuk, akkor rövidül az intervallum:
    j = max(j, last_seen[p]+1);
    
    // Az eddigi leghosszabb intervallum:
    ans = max(i-j+1, ans);

    // Tároljuk, hogy p-t most láttuk:
    last_seen[p] = i;
  }

  /*
   * Helyesség bizonyítása:
   * - Invariáns tulajdonság:
   *     adott i-hez j az a legkisebb index, hogy [j,i]-ben csupa különböző szám van.
   * - Kezdetben: i=0-ra j=0.
   * - Ha adott i-re jó a j, akkor az i+1-hez tartozó j' csak j<=j' lehet.
   * - Mivel a [j,i] intervallum elemei egyediek, ezért [j,i+1] jóságához csak
   *   azt kell garantálni, hogy az i+1. zeneszám ne szerepeljen benne, ehhez pedig
   *   last_seen[p]+1 <= j' szükséges.
   * - Tehát j' = max(j, last_seen[p]+1) a lehető legkisebb j'.
   * - A megoldás a lehetséges [j,i] intervallumok hosszának maximuma az összes i-re.
   */
  cout<<ans<<endl;

  return 0;
}