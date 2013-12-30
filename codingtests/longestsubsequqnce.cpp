#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
struct comp
{
  bool operator() (const pair<int, int>& a, const pair<int, int>& b)
  {
    return a.first < b.first;
  }
};

set<pair<int, int>, comp>::iterator true_lower(set<pair<int, int>, comp>& s, int v)
{
  if((s.empty() || (*s.begin()).first >= v))
  {
    return s.end();
  }
  return --s.lower_bound(make_pair(v, 0));
}

int longest_subseq(vector<int>& V)
{
  set<pair<int, int>, comp> lastelemlength;
  int curr;
  for(size_t i = 0; i < V.size(); ++i)
  {
    curr = V[i];
    pair<int, int> lwrbnd = *true_lower(lastelemlength, curr);
    set<pair<int, int>, comp>::iterator itlwrbnd = true_lower(lastelemlength, curr);
    if(lwrbnd != *lastelemlength.end())
    { 
      if(lastelemlength.size() >= (size_t)lwrbnd.second+1)
      {
        lastelemlength.erase(++itlwrbnd);
      }
      ++lwrbnd.second;
      lwrbnd.first = curr;
      lastelemlength.insert(lwrbnd);
    } else
    {
      if(lastelemlength.size() >= 1)
      {
        lastelemlength.erase(lastelemlength.begin());
      }
      lastelemlength.insert(make_pair(curr, 1));
    }
  }

  int result = 0;
  for(set<pair<int, int>, comp>::iterator it = lastelemlength.begin(); 
      it != lastelemlength.end(); ++it)
  {
    if(result < it->second)
      result = it->second;
  }
  return result;
}

int main()
{
  int A[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  vector<int> vA (A, A+sizeof(A)/sizeof(A[0]));
  cout<<"Length of longest sub: "<<longest_subseq(vA)<<endl;
  return 0;
}
