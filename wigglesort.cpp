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

void wigglesort(VE& v, VE& result)
{
  int middle = (v.size()-1)/2;
  int even = 0;
  for(int i = 0; i <= middle; ++i)
  {
    cout<<v[i]<<" f"<<endl;
    result[even] = v[i];
    even += 2;
  }
  int odd = 1;
  for(size_t i = middle+1; i < v.size(); ++i)
  {
    result[odd] = v[i];
    odd += 2;
  }
}

int main()
{
  int A[] = {1, 7, 3, 6, 3, 9, 2, 11, 7};
  VE v (A, A+sizeof(A)/sizeof(A[0]));
  //int B[] = {1, 7, 3, 6};
  //VE v (B, B+sizeof(B)/sizeof(B[0]));
  sort(v.begin(), v.end());
  VE result (v.size(), 0);
  wigglesort(v, result);
  LOOPS(i, result.size())
  {
    cout<<result[i]<<endl;
  }
  return 0;
}
