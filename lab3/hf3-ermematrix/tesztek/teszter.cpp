#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

int main()
{
  string in_file_path, ans_file_path, sol_file_path;
  cin>>in_file_path>>ans_file_path>>sol_file_path;

  ifstream in_file(in_file_path);
  ifstream ans_file(ans_file_path);
  ifstream sol_file(sol_file_path);

  if(!in_file.is_open()) { cerr << "Failed to open in_file: " << in_file_path << endl; return -1; }
  if(!ans_file.is_open()) { cerr << "Failed to open ans_file: " << ans_file_path << endl; return -1; }
  if(!sol_file.is_open()) { cerr << "Failed to open sol_file: " << sol_file_path << endl; return -1; }

  int ans_r, sol_r;
  ans_file >> ans_r;
  sol_file >> sol_r;
  if(ans_r != sol_r) return -1;

  int n; in_file>>n;
  vector<set<int>> g(n, set<int>());
  for(int i=0; i<n; ++i)
  {
    string a; cin>>a;
    for(int j=0; j<n; ++j)
    {
      if(a[j] == 'o') g[i].insert(j);
    }
  }

  set<int> rev;
  for(int i=0; i<sol_r; ++i)
  {
    int c, x; sol_file>>c>>x; --x;
    if(c==1) g[x].clear(); 
    else rev.insert(x);
  }

  for(int v=0; v<n; ++v)
  for(auto& u: g[v])
  {
    if(!rev.count(u)) return -1;
  }
  
  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
