# Hanoi tornyai

A megoldásban a legnagyobb korongnak biztosan át kell kerülnie a bal szélső rúdról a jobb szélsőre. Ahhoz, hogy ezt a korongot mozgathassuk, neki egyedül kell lennie a kiindulási rúdon és a cél rúdnak üresnek kell lennie. Tehát a legnagyobb mozgatása előtt a többi korongnak, növekvő sorrendben, a középső rúdra kell kerülnie valahogyan, a legnagyobb mozgatása után pedig a többi korongnak a legnagyobb tetejére kell kerülnie, szintén növekvő sorrendben.

Képzeljük el, hogy van egy függvényünk, ami megmondja az optimális lépésszámú algoritmust, amivel $k$ darab korongot az $a$. rúdról a $c$. rúdra lehet juttatni, úgy hogy közben a $b$. üres rudat felhasználhatjuk! Ennek a függvénynek a fenti érvelés alapján úgy kell működnie, hogy először valahogyan a $k-1$ darab korongot átmozgatja $a$-ról a $b$-re, majd egy lépésben a $k$. korongot átteszi $a$-ról a $c$-re, végül a $k-1$ darab korongot átmozgatja $b$-ről a $c$-re.

Látható, hogy a $k-1$ darab korong mozgatása feladat is hasonló az eredetihez, bár a köztes rúd nem mindig üres, hiszen a $k$. korong rajta van, de tekinthető üresnek, hiszen csak nála kisebb korongokat mozgatunk, amik mindig rátehetők a tetejére.

Tehát a program, ami az optimális mozgatássort generálja, ilyen szép rekurzív alakú:

```cpp
#include <bits/stdc++.h>
using namespace std;
 
void hanoi(int k, int a, int b, int c)
{
  if(k==0) return;
  hanoi(k-1, a, c, b);
  cout << a << " " << c << endl;
  hanoi(k-1, b, a, c);
}
 
int main()
{
  int n; cin>>n;
  cout << (1<<n)-1 << endl;
  hanoi(n, 1, 2, 3);
}
```

Gondoljunk bele milyen nehéz lett volna ezt rekurzió nélkül implementálni!

A lépésszám pedig a rekurzív alakból könnyen számolható: amennyiben $T[k]$ jelöli a
$k$ méretű feladat optimális megoldásának lépésszámát, úgy

$$T[k] = 2 T[k-1] + 1,$$

továbbá $T[0] = 0$, amiből pedig

$$T[k] = 2 \cdot T[k-1] + 1 = 2 \cdot (2 \cdot T[k-2] + 1) + 1 = 2^2 \cdot T[k-2] + 2 + 1 = \dots = 2^i \cdot T[k-i] + \sum_{j=0}^{i-1} 2^j$$

innen pedig látható, hogy az utolsó kifejtendő lépés az, amikor $i=k$, ezt behelyettesítve

$$2^i \cdot T[k-i] + \sum_{j=0}^{i-1} 2^j = 2^k \cdot T[0] + \sum_{j=0}^{k-1} 2^j = 0 + \sum_{j=0}^{k-1} 2^j = 2^k-1$$

tehát zárt alakban $T[k] = 2^k - 1 \in O(2^k)$.
