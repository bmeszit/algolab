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
