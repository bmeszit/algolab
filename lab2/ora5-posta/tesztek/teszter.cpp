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
  vector<set<int>> adj(n);
  for(int i=0; i<m; ++i)
  {
    int v, u; in_file>>v>>u; --v; --u;
    adj[v].insert(u);
  }

  vector<int> ans_euler, sol_euler;
  ans_euler=getNs(ans_file);
  sol_euler=getNs(sol_file);

  if(ans_euler.empty() && sol_euler.empty()) return 0;
  if(sol_euler.size() != m+1) return -1;

  for(int i=0; i<m; ++i)
  {
    int v = sol_euler[i]; --v;
    int u = sol_euler[i+1]; --u;

    if(adj[v].count(u)) adj[v].erase(u);
    else if (adj[u].count(v)) adj[u].erase(v);
    else return -1;
  }

  for(int i=0; i<n; ++i)
  {
    if(!adj[i].empty()) return -1;
  }

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
