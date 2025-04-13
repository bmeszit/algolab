#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

int getN(std::ifstream& in)
{
  string line;
  if(!getline(in, line)) return -2;

  if (line.find("IMPOSSIBLE") != string::npos) return -1;
  
  int n;
  istringstream ss(line);

  if(!(ss>>n)) return -2;
  return n;
}

int main()
{
  string in_file_path, ans_file_path, sol_file_path;
  cin>>in_file_path>>ans_file_path>>sol_file_path;
  cin.exceptions(ios::failbit);

  ifstream in_file(in_file_path);
  ifstream ans_file(ans_file_path);
  ifstream sol_file(sol_file_path);

  if(!in_file.is_open()) { cerr << "Failed to open in_file: " << in_file_path << endl; return -1; }
  if(!ans_file.is_open()) { cerr << "Failed to open ans_file: " << ans_file_path << endl; return -1; }
  if(!sol_file.is_open()) { cerr << "Failed to open sol_file: " << sol_file_path << endl; return -1; }

  int n, m; in_file>>n>>m;
  vector<set<int>> adj(n);
  for(int i=0; i<m; ++i)
  {
    int v, u; in_file>>v>>u; --v; --u;
    adj[v].insert(u);
  }

  int ans_k, sol_k;
  ans_k=getN(ans_file);
  sol_k=getN(sol_file);

  if(ans_k == -1 && sol_k == -1) return 0;
  if(sol_k < 0) return -1;

  int v, u; sol_file>>v; --v;
  if(v!=0) return -1;
  for(int i=0; i<sol_k-1; ++i)
  {
    sol_file>>u; --u;
    if(!adj[v].count(u)) return -1;
    v = u;
  }
  if(v!=n-1) return -1;

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
