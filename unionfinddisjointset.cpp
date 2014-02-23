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
#include <cmath>
#include <ctime>
#include <climits>
#include <iomanip>

#define LOOP(i, s, e) for(int i = (int)s; i < (int)e; ++i)
#define ITVI(c, it) \
  for(VI::iterator it = (c).begin(); it != (c).end(); ++it)
#define ITVVI(c, it) \
  for(VVI::iterator it = (c).begin(); it != (c).end(); ++it)
#define ITMSI(c, it) \
  for(MSI::iterator it = (c).begin(); it != (c).end(); ++it)
#define PB push_back
#define PF printf
#define all(c) (c).begin(), (c).end()
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
#define INF INT_MAX

using namespace std;
 
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<VI> VVI;
typedef set<int> SI;
typedef map<string, int> MSI;
typedef map<int, int> MII;

class QuickSet
{
  private:
    VI pset;
    int count;
    VI sizes;
  public:
    void init_set(int);
    int find_set(int);
    void union_set(int, int);
    bool is_same_set(int, int);
    int num_sets();
    int size_set(int);
};

void QuickSet:: init_set(int size)
{
  count = size;
  sizes.resize(size, 1);
  pset.resize(size);
  LOOP(i, 0, size)
  {
    pset[i] = i;
  }
}

int QuickSet::find_set(int i)
{
  //If the same as the index, return the index, otherwise set the
  //entry to the recursive call and return
  if(pset[i] == i)
  {
    return i;
  }else
  {
    pset[i] = find_set(pset[i]);
    sizes[i] = sizes[pset[i]];
  }
  return pset[i];
}

void QuickSet::union_set(int a, int b)
{
  if(find_set(a) == find_set(b))
    return;

  int roota = find_set(a);
  int rootb = find_set(b);
  sizes[rootb] += sizes[roota];
  pset[roota] = rootb;
  --count;
}

bool QuickSet::is_same_set(int a, int b)
{
  return find_set(a) == find_set(b);
}

int QuickSet::num_sets()
{
  return count;
}

int QuickSet::size_set(int i)
{
  return sizes[find_set(i)];
}

int main()
{
  //int temp[] = {0, 1, 2, 3};
  //VI v1(temp, temp+sizeof(temp)/sizeof(temp[0]));
  //int temp2[] = {4, 5, 6, 7, 8, 9, 10};
  //VI v2(temp2, temp2+sizeof(temp2)/sizeof(temp2[0]));

  //QuickSet qs;
  //qs.init_set(v1.size()+v2.size());
  ////int a, b;
  //LOOP(i, 0, v1.size()-1)
  //{
  //  qs.union_set(v1[i], v1[i+1]);
  //  PF("Union %i and %i\n", v1[i], v1[i+1]);
  //  PF("Size of set %i: %i\n", i, qs.size_set(i));
  //}
  //LOOP(i, 0, v2.size()-1)
  //{
  //  qs.union_set(v2[i], v2[i+1]);
  //}
  //cout<<boolalpha<<qs.is_same_set(1, 2)<<endl;
  //PF("Size of set %i: %i\n", 1, qs.size_set(1));
  //cout<<boolalpha<<qs.is_same_set(4, 2)<<endl;
  //PF("Counts: %i\n", qs.num_sets());
  //PF("Size of set %i: %i\n", 2, qs.size_set(2));
  //cout<<boolalpha<<qs.is_same_set(6, 2)<<endl;
  ////PF("Size of set %i: %i\n", 1, qs.size_set(1));
  //cout<<boolalpha<<qs.is_same_set(9, 2)<<endl;
  //cout<<boolalpha<<qs.is_same_set(1, 2)<<endl;
  //cout<<boolalpha<<qs.is_same_set(1, 10)<<endl;
  //qs.union_set(1, 4);
  //PF("Size of set %i: %i\n", 1, qs.size_set(1));
  //PF("Size of set %i: %i\n", 2, qs.size_set(2));
  //PF("Size of set %i: %i\n", 3, qs.size_set(3));
  //PF("Size of set %i: %i\n", 4, qs.size_set(4));
  return 0;
}
