#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

bool contains(string x, string what)
{
  return x.find(what) != string::npos;
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

  string ans_ok, sol_ok;
  ans_file>>ans_ok;
  sol_file>>sol_ok;

  bool ans_ok_yes = contains(ans_ok, "YES");
  bool ans_ok_no = contains(ans_ok, "NO");
  bool sol_ok_yes = contains(ans_ok, "YES");
  bool sol_ok_no = contains(ans_ok, "NO");

  if(sol_ok_yes == sol_ok_no) return -1;
  if(ans_ok_yes != sol_ok_yes) return -1;
  if(sol_ok_no) return 0;

  int ans_k, sol_k;
  ans_file>>ans_k;
  sol_file>>sol_k;

  if(ans_k != sol_k) return -1;

  int n, m;  in_file>>n>>m;
  vector<string> rooms(n);
  for(int i=0; i<n; ++i) in_file>>rooms[i];

  string steps; sol_file >> steps;

  int ax=-1, ay=-1, bx=-1, by=-1;
  for(int x=0; x<n; ++x)
  {
    cin>>rooms[x];
    for(int y=0; y<m; ++y)
    {
      if(rooms[x][y]=='A') { ax=x; ay=y; }
      if(rooms[x][y]=='B') { bx=x; by=y; }
    }
  }

  int x=ax, y=ay;
  for(int i=0; i<sol_k; ++i)
  {
    auto step = steps[i];
    if(step=='U') --x;
    if(step=='D') ++x;
    if(step=='L') --y;
    if(step=='R') ++y;

    if(x<0 || n<=x) return -1;
    if(y<0 || m<=y) return -1;
    if(rooms[x][y]=='#') return -1;
  }
  if(x!=bx || y!=by) return -1;

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
