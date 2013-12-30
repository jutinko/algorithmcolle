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

void make_prefixsum(VE& v1, VE& v2)
{
  size_t size = v1.size();
  if(size == 0)
    return;
  v2.push_back(v1[0]);
  FORS(i, 1, v1.size())
  {
    v2.push_back(v2[i-1]+v1[i]);
  }
}

//Both start and end values inclusive
int getsum(VE& prefixsum, int start, int end)
{
  if(start == 0)
    return(prefixsum[end]);
  return(prefixsum[end]-prefixsum[start-1]);
}

PR get_range(int leftsteps, int steps, int position, int size)
{
  //int left = position;
  int right = size-1;
  PR result;
  if(position > leftsteps)
  {
    int rightbound = max(position, position+steps-2*leftsteps);
    rightbound = min(rightbound, right);
    int leftbound = min(position-leftsteps, 
        right-(steps-2*leftsteps-(right-position)));
    leftbound = max(0, leftbound);
    result = make_pair(leftbound, rightbound);
  } else
  {
    result = make_pair(0, max(position, steps-leftsteps));
  }
  return(result);
}

int get_max(VE& v, int position, int steps)
{
  VE prefixsum;
  make_prefixsum(v, prefixsum);
  int max = 0;
  int curr;
  PR pair;;
  FOR(i, 0, steps+1)
  {
    pair = get_range(i, steps, position, v.size());
    curr = getsum(prefixsum, pair.first, pair.second);
    PF("Curr: %i, first: %i, second: %i\n", curr, pair.first, pair.second);
    max = max < curr ? curr : max;
  }
  return max;
}

int main()
{
  int temp[] = {2, 3, 5, 6, 1, 0, 7};
  VE v(temp, temp+sizeof(temp)/sizeof(temp[0]));
  PF("The robot's max gain is: %i\n", get_max(v, 0, 7));
  return 0;
}
