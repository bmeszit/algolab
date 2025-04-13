#include<bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

vector<vector<string>> read(ifstream& in)
{ 
  vector<vector<string>> input;
  string line;
  while(getline(in, line))
  {
    istringstream iss(line);
    vector<string> words;
    string word;
    while(iss >> word)
    {
      words.push_back(word);
    }
    input.push_back(words);
  }
  return input;
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

  auto in = read(in_file);
  auto ans = read(ans_file);
  auto sol = read(sol_file);

  int n = in.size();
  int k = ans.size()-1-n;

  if(sol.size() != ans.size()) return -1;

  for(int i=0; i<k; ++i)
  {
    sort(ans[i].begin()+1, ans[i].end());
    sort(sol[i].begin()+1, sol[i].end());
  }
  sort(ans.begin(), ans.begin()+k);
  sort(sol.begin(), sol.begin()+k);
  
  sort(ans.begin()+k+1, ans.end());
  sort(sol.begin()+k+1, sol.end());

  if(ans != sol) return -1;

  in_file.close();
  ans_file.close();
  sol_file.close();

  return 0;
}
