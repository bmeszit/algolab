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

  int r;
  sol_file >> r;

  int n, m; in_file>>n>>m;
  vector<int> boy_match(n, -1), boy_match_rank(n, infty);
  vector<int> girl_match(m, -1);

  for(int i=0; i<r; ++i)
  {
    int b, g; sol_file>>b>>g; --b; --g;
    if(boy_match[b]!=-1) return -1;
    if(girl_match[g]!=-1) return -1;
    boy_match[b]=g;
    girl_match[g]=b;
  }

  map<pair<int,int>, int> edges;
  for(int b=0; b<n; ++b)
  {
    int k; in_file>>k;
    for(int bp=0; bp<k; ++bp)
    {
      int g; in_file>>g; --g;
      edges[{b, g}] = bp;
      if(g == boy_match[b]) boy_match_rank[b] = bp;
    }
  }

  for(int g=0; g<m; ++g)
  {
    int k; in_file>>k;
    bool saw_pair=false;
    for(int gp=0; gp<k; ++gp)
    {
      int b; in_file>>b; --b;
      if(b == girl_match[g]) { saw_pair=true; continue; }

      auto& bp = edges[{b, g}];
      bool boy_better = (bp < boy_match_rank[b]);
      bool girl_better = !saw_pair;
      if(boy_better && girl_better) return -1;
    }
  }

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
