#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
class Node
{
  public:
    int val;
    Node* left;
    Node* right;
    Node(int);
    Node(vector<int>&);
};

Node::Node(int v)
{
  this->val = v;
}

Node* nodehelper(vector<int>& vs, int s, int e)
{
  if(s>e)
    return NULL;
  int offset = (e-s)/2;
  Node* result = new Node(vs[s+offset]);
  result->left = nodehelper(vs, s, s+offset-1);
  result->right = nodehelper(vs, s+offset+1, e);
  return result;
}

Node::Node(vector<int>& vs)
{
  if(vs.size() == 0)
    return;
  int e = vs.size()-1;
  int s = 0;
  int offset = (e-s)/2;
  this->val = vs[s+offset];
  this->left = nodehelper(vs, s, s+offset-1);
  this->right = nodehelper(vs, s+offset+1, e);
}

void breadthfirstcheck(Node& n)
{
  Node curr = n;
  queue<Node*> q;
  q.push(curr.left);
  q.push(curr.right);
  while(!q.empty())
  {
    curr = *q.front();
    q.pop();
    cout<<curr.val<<endl;
    if(curr.left != NULL)
      q.push(curr.left);
    if(curr.right != NULL)
    q.push(curr.right);
  }
}

int main()
{
  int A[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  vector<int> v (A, A+sizeof(A)/sizeof(A[0]));
  sort(v.begin(), v.end());
  for(size_t i = 0; i < v.size(); ++i)
  {
    printf("%i ", v[i]);
  }
  printf("\n");
  Node n (v);
  breadthfirstcheck(n);
  return 0;
}
