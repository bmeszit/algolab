#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

const int infty = numeric_limits<int>::max();

struct pref { int b, g; bool ans_sel, sol_sel; };

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

  int k;
  sol_file >> k;

  int n, m; in_file>>n>>m;

  vector<vector<int>> wins(n, vector<int>(n, 0));
  for(int i=0; i<k; ++i)
  {
    vector<int> ord;
    set<int> permu;
    for(int j=0; j<n; ++j)
    {
      int p; sol_file>>p; --p;
      if(p<0 || n<=p) return -1;
      permu.insert(p);
      ord.push_back(p);
    }
    if(permu.size()!=n) return -1;

    for(int a=0; a<n; ++a)
    for(int b=a+1; b<n; ++b)
    {
      ++wins[ord[a]][ord[b]];
    }
  }

  for(int i=0; i<m; ++i)
  {
    int a, b; in_file>>a>>b; --a; --b;
    if(wins[a][b] <= (k/2)) return -1;
  }

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
