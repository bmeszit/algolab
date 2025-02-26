#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<long long> a;

bool validal(int mo)
{
    long long gyartottunk = 0;
    for(auto& ax: a)
    {
        gyartottunk += mo / ax;
    }
    return t <= gyartottunk;
}

int main()
{
  cin>>n>>t;
  a.assign(n, {});
  for(auto& ax: a) cin>>ax;

  long long lo=0;
  long long hi=t*a[0]; // t= hány termék kell , a[0] = hány mp / 1 termék

  while(lo < hi)
  {
    long long mid = (hi-lo)/2+lo;
    if(validal(mid)) hi = mid;
    else lo = mid + 1;
  }

  cout << lo << endl;
  return 0;
}
