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

  int n, m, k; in_file>>n>>m>>k;
  vector<set<int>> g(n, set<int>());
  for(int i=0; i<k; ++i)
  {
    int a, b; in_file>>a>>b; --a; --b;
    g[a].insert(b);
  }

  vector<bool> a_p(n, false), b_p(m, false);
  for(int i=0; i<sol_r; ++i)
  {
    int a, b; sol_file>>a>>b; --a; --b;
    if(a<0 || n<=a) return -1;
    if(b<0 || m<=b) return -1;
    if(!g[a].count(b)) return -1;
    if(a_p[a] || b_p[b]) return -1;
    a_p[a] = b_p[b] = true;
  }
  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
