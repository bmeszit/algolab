#include<bits/stdc++.h>
using namespace std;

int n;
enum { fresh = -1, matched = -2 };

struct course
{
  string code;
  int id;

  int capacity;
  vector<int> orig_students;
  vector<int> new_students;
};
map<string, int> course_id;
vector<course> courses;

struct student
{
  string neptun;

  int orig_course;
  int new_course;

  int state=fresh;
  int pick=-1;
  vector<int> course_ord;
  vector<int> ord;
};
vector<student> students;

vector<vector<string>> read()
{ 
  vector<vector<string>> input;
  string line;
  while(getline(cin, line))
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
  auto input = read();
  n = input.size();

  students.assign(n, {});

  int next_course_id=0;
  for(int i=0; i<n; ++i)
  {
    students[i].neptun=input[i].front();
    for(int j=1; j<input[i].size(); ++j)
    {
      auto code=input[i][j];
      if(course_id.find(code) == course_id.end())
      {
        course_id[code]=next_course_id++;
        courses.push_back({.code=code, .id=course_id[code]});
      }
      courses[course_id[code]].capacity++;
      students[i].course_ord.push_back(course_id[code]);
    }
    students[i].orig_course=course_id[input[i].back()];
    courses[students[i].orig_course].orig_students.push_back(i);
  }

  for(int i=0; i<n; ++i)
  {
    for(auto& course_id: students[i].course_ord)
    for(auto& student_id: courses[course_id].orig_students)
    {
      students[i].ord.push_back(student_id);
    }
    reverse(students[i].ord.begin(), students[i].ord.end());
  }

  int done=0;
  while(done<n)
  {
    for(int i=0; i<n; ++i)
    {
      if(students[i].state==matched) continue;
      while(students[students[i].ord.back()].state==matched) students[i].ord.pop_back();
      students[i].pick = students[i].ord.back();
    }
    for(int v=0; v<n; ++v)
    {
      if(students[v].state!=fresh) continue;
      int u=v; while(students[u].state==fresh)
      {
        students[u].state=v;
        u=students[u].pick;
      }
      if(students[u].state!=v) continue;
      int c=u; do
      {
        students[u].state=matched; ++done;
        u = students[u].pick;
      } while(u!=c);
    }
    for(int v=0; v<n; ++v)
    {
      if(students[v].state!=matched) students[v].state=fresh;
    }
  }
  for(int i=0; i<n; ++i)
  {
    auto new_course=students[students[i].pick].orig_course;
    students[i].new_course=new_course;
    courses[new_course].new_students.push_back(i);
  }
  for(auto& course: courses)
  {
    cout << course.code << ":";
    for(auto& student_id: course.new_students)
    {
      cout << " " << students[student_id].neptun;
    }
    cout << endl;
  }
  cout << endl;
  for(auto& student: students)
  {
    cout << student.neptun << ": "
         << courses[student.orig_course].code << " >> "
         << courses[student.new_course].code << endl;
  }
  return 0;
}