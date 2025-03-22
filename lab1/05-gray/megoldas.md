# Gray kód

Használjunk rekurziót! Készítsünk egy függvényt, ami legenerálja nekünk egy tömbben az $n$ bites Gray-kódot.

Az $n=1$ bemenet esetén a megoldás a $["0", "1"]$.

Nagyobb $n$-re pedig először hívjuk meg a függvényt rekurzívan $n-1$-re, majd duplikáljuk a kapott tömböt:
az első példány elemei elé $0$-kat, a második példány elemei elé pedig $1$-eseket szúrjunk be, végül 
fordítsuk meg a második példány sorrendjét és konkatenáljuk őket!

Látható, hogy ez egyrészt $n$ bites Gray kódot eredményez, hiszen az egyes példányokon belül az egymást
követő párok között továbbra is egy bit eltérés van, a két példány határán lévő pár pedig a második példány
megfordítása miatt pont az $n-1$ hosszú kód utolsó eleméből keletkezett, tehát egyedül az első biten térnek el.

```cpp
#include <bits/stdc++.h>
using namespace std;
 
vector<string> gray(int n)
{
  if(n==1) return {"0", "1"};
  auto prev = gray(n-1);
  auto curr = vector<string>();
  int s = prev.size();
  for(int   i=0;  i<s; ++i) curr.push_back("0" + prev[i]);
  for(int i=s-1; 0<=i; --i) curr.push_back("1" + prev[i]);
  return curr;
}
 
int main()
{
  int n; cin>>n;
  auto ans = gray(n);
  for(auto& ax: ans) cout << ax << endl;
  return 0;
}
```
