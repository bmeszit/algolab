#include <bits/stdc++.h>
using namespace std;

// Használjunk rekurziót! Készítsünk egy függvényt, ami
// legenerálja nekünk egy tömbben az $n$ bites Gray-kódot:
vector<string> gray(int n)
{
  // Alapeset: 1 hosszú Gray kód.
  if(n==1) return {"0", "1"};

  // Egyébként az n hosszú Gray kód az n-1 hosszúból állítható elő:
  auto prev = gray(n-1);

  auto curr = vector<string>();
  int s = prev.size();
  // Egyrészt tegyünk egy 0-át az n-1 hosszú Gray kódsorozat minden eleme elé:
  for(int   i=0;  i<s; ++i) curr.push_back("0" + prev[i]);
  // Másrészt pedig tegyünk egy 1-et elé és adjuk őket hozzá visszafele sorrendben:
  for(int i=s-1; 0<=i; --i) curr.push_back("1" + prev[i]);

  // Látható, hogy ez egyrészt $n$ bites Gray kódot eredményez, hiszen az egyes
  // példányokon belül az egymást követő párok között továbbra is egy bit
  // eltérés van, a két példány határán lévő pár pedig a második példány
  // megfordítása miatt pont az n-1 hosszú kód utolsó eleméből keletkezett,
  // tehát egyedül az első biten térnek el.
  return curr;
}
 
int main()
{
  int n; cin>>n;
  auto ans = gray(n);
  for(auto& ax: ans) cout << ax << endl;
  return 0;
}
