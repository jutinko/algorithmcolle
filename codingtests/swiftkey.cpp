#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define LOOP(i, e) for(int i=0; i<e; ++i)
#define LOOPS(i, e) for(size_t i=0; i<e; ++i)
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FORS(i, s, e) for(size_t i=s; i<e; ++i)
#define VE vector<int>
#define SZ size()
#define PB push_back
#define PF printf
#define PR pair<int, int>

int solution(const string &S)
{
  if(S.length() == 0)
    return 1;
  int left_bracket = 0;
  LOOPS(i, S.length())
  {
    if(left_bracket < 0)
    {
      return 0;
    }
    if(S[i] == '(')
    {
      ++left_bracket;
    } else if(S[i] == ')')
    {
      --left_bracket;
    }
  }
  return left_bracket == 0;
}

int main()
{
  VE v;
  v.push_back(5);
  LOOPS(i, v.size())
  {
    PF("%i\n", v[i]);
  }
  string s = "())";
  PF("Result: %i\n", solution(s));
  return 0;
}
