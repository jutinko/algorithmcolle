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

int getmaxsubarray(VE v)
{
  int max = v[0];
  int curr = v[0] > 0 ? v[0] : 0;
  FORS(i, 1, v.size())
  {
    if(curr+v[i] > max)
    {
      max = curr+v[i];
      curr = curr+v[i];
    } else if(curr+v[i] < 0)
    {
      curr = 0;
    } else
    {
      curr = curr+v[i];
    }
  }
  return max;
}

int main()
{
  ifstream infile;
  infile.open("maxsubarray.txt");
  istringstream sline;
  string line;
  string line1 = "fda";
  VE v;
  int temp;
  while(getline(infile, line))
  {
    sline.str(line);
    while(sline>>temp)
    {
      v.push_back(temp);
    }
    cout<<getmaxsubarray(v)<<endl;
    sline.clear();
    v.clear();
  }
  return 0;
}
