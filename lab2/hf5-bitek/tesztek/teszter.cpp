#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

bool contains(string x, string what)
{
  return x.find(what) != string::npos;
}

string to_string(int bits, int size)
{
  string res;
  for(int i=size-1; 0<=i; --i)
  {
    res += (bits & (1 << i)) ? '1' : '0';
  }
  return res;
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

  int n; in_file>>n;
  string ans_bits, sol_bits;
  ans_file >> ans_bits;
  sol_file >> sol_bits;
  
  if(ans_bits.size() != sol_bits.size()) return -1;

  for(int i=0; i<sol_bits.size(); ++i)
  {
    if(sol_bits[i]!='0' && sol_bits[i]!='1') return -1;
  }

  for(int i=0; i<(1<<n); ++i)
  {
    string x = to_string(i, n);
    if(!contains(sol_bits, x)) return -1;
  }

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
