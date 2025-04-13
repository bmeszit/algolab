#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

const int infty = numeric_limits<int>::max();

struct pref { int b, g; bool ans_sel, sol_sel; };

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

  int n, q; in_file>>n>>q;
  for(int i=0; i<q; ++i)
  {
    double ans_x; ans_file>>ans_x;
    double sol_x; sol_file>>sol_x;
    if (1e-6 < abs(ans_x - sol_x) ) return -1;
  }

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
