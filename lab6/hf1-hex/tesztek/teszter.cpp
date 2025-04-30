#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

string last_line(ifstream& in)
{
  string result, line;
  while (getline(in, line))
  {
    bool non_ws = any_of(line.begin(), line.end(), [](unsigned char ch){ return !isspace(ch); });
    if (non_ws) result = line;
  }
  return result;
}

int main()
{
  string in_file_path, ans_file_path, sol_file_path;
  cin>>in_file_path>>ans_file_path>>sol_file_path;
  cin.exceptions(ios::failbit);

  ifstream in_file(in_file_path);
  ifstream sol_file(sol_file_path);

  if(!in_file.is_open()) { cerr << "Failed to open in_file: " << in_file_path << endl; return -1; }
  if(!sol_file.is_open()) { cerr << "Failed to open sol_file: " << sol_file_path << endl; return -1; }

  int size, p0, p1; in_file>>size>>p0>>p1;
  auto sol = last_line(sol_file);

  if(p0==2)
  {
    if (sol.find("Vertical (x) player wins!") == string::npos) return -1;
  }
  else if(p1==2)
  {
    if (sol.find("Horizontal (o) player wins!") == string::npos) return -1;
  }
  
  in_file.close();
  sol_file.close();

  return 0;
}
