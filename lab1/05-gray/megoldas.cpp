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