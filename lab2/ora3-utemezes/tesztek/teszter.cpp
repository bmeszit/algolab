#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

vector<int> getNs(std::ifstream& in)
{
  string line;
  if(!getline(in, line)) return {};

  if (line.find("IMPOSSIBLE") != string::npos) return {};
  
  vector<int> ns;
  istringstream ss(line);

  int n;
  while(ss>>n) { ns.push_back(n); }
  return ns;
}

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

  int n, m; in_file>>n>>m;
  
  vector<int> ans_topo, sol_topo;
  ans_topo=getNs(ans_file);
  sol_topo=getNs(sol_file);

  if(ans_topo.empty() && sol_topo.empty()) return 0;
  if(sol_topo.size() != n) return -1;
  
  vector<int> topo_inv(n, -1);
  for(int i=0; i<n; ++i)
  {
    topo_inv[sol_topo[i]-1] = i;
  }
  for(int i=0; i<n; ++i)
  {
    if(topo_inv[i] == -1) return -1;
  }

  for(int i=0; i<m; ++i)
  {
    int v, u; in_file>>v>>u; --v; --u;
    if(topo_inv[u] <= topo_inv[v]) return -1;
  }
  return 0;

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
