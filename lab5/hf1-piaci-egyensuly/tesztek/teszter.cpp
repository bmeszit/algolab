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

  int n; in_file>>n;
  vector<vector<int>> ord;

  vector<int> p(n), s(n, -1);
  for(auto& pp: p) sol_file>>pp;

  ord.assign(n, vector<int>(n));
  for(int i=0; i<n; ++i)
  {
    bool done=false;
    for(int j=0; j<n; ++j)
    {
      int x; in_file>>x; --x;
      if(p[x] <= p[i] && !done) { s[i]=x; done=true; }
    }
  }
  sort(s.begin(), s.end());
  for(int i=0; i<n; ++i) { if(s[i]!=i) return -1; }
  
  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
