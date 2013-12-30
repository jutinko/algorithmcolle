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

struct tree 
{
  int x;
  tree* l;
  tree* r;
};

int solution_help(tree* T, int l, int r)
{
  PF("L: %i, R: %i\n", l, r);
  int lmax = l;
  if(T->l != NULL)
  {
    lmax = solution_help(T->l, l+1, 0);
  }
  int rmax = r;
  if(T->r != NULL)
  {
    rmax = solution_help(T->r, 0, r+1);
  }
  PF("Returning\n");
  return max(lmax, rmax);
}

int solution(tree* T)
{
  return solution_help(T, 0, 0);
}

int main()
{
  tree t;
  t.x = 1;
  tree left;
  left.l = NULL;
  left.r = NULL;
  tree right;
  right.l = NULL;
  right.r = NULL;
  //t.l = &left;
  t.l = NULL;
  t.r = &right;
  PF("Result: %i\n", solution(&t));
  return 0;
}
