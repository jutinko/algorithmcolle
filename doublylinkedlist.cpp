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

class doublelinkednode
{
  private:
    int value;
    doublelinkednode* next;
    doublelinkednode* prev;

  public:
    doublelinkednode(int);
    void set_value(int);
    void set_next(doublelinkednode*);
    void set_prev(doublelinkednode*);
    int get_value();
    doublelinkednode* get_next();
    doublelinkednode* get_prev();
};
typedef doublelinkednode node;

node::doublelinkednode(int n)
{
  set_value(n);
}

void node::set_value(int n)
{
  this->value = n;
}

void node::set_next(node* newnext)
{
  this->next = newnext;
}

void node::set_prev(node* newprev)
{
  this->prev = newprev;
}

int node::get_value()
{
  return this->value;
}

node* node::get_next()
{
  return this->next;
}

node* node::get_prev()
{
  return this->prev;
}

class doublylinkedlist
{
  private:
    size_t size;
    //Dummy's next HEAD, dummy's prev TAIL
    node* dummy;

  public:
    doublylinkedlist();
    //When empty, call this no matter push_back or push_front
    void init_node(node*);
    void push_back(int);
    void push_front(int);
    void remove_front();
    void remove_back();
    void print();
};
typedef doublylinkedlist dlist;

dlist::doublylinkedlist()
{
  this->size = 0;
  node* dummy = new node(-1);
  dummy->set_next(dummy);
  dummy->set_prev(dummy);
  this->dummy = dummy;
}

void dlist::init_node(node* firstnode)
{
  this->dummy->set_next(firstnode);
  this->dummy->set_prev(firstnode);
  firstnode->set_next(this->dummy);
  firstnode->set_prev(this->dummy);
}

void dlist::push_back(int n)
{
  node* newnode = new node(n);
  //First element
  if(this->size == 0)
  {
    this->init_node(newnode); 
  } else
  {
    node* tail = this->dummy->get_prev();
    tail->set_next(newnode);
    newnode->set_prev(tail);
    this->dummy->set_prev(newnode);
    newnode->set_next(this->dummy);
  }
  ++this->size;
}

void dlist::push_front(int n)
{
  node* newnode = new node(n);
  //First element
  if(this->size == 0)
  {
    this->init_node(newnode); 
  } else
  {
    node* head = this->dummy->get_next();
    head->set_prev(newnode);
    newnode->set_next(head);
    this->dummy->set_next(newnode);
    newnode->set_prev(this->dummy);
  }
  ++this->size;
}

void dlist::remove_back()
{
  if(this->size == 0)
  {
    return;
  } else
  {
    node* tail = this->dummy->get_prev();
    tail->get_prev()->set_next(this->dummy);
    this->dummy->set_prev(tail->get_prev());
    delete tail;
    --this->size;
  }
}

void dlist::remove_front()
{
  if(this->size == 0)
  {
    return;
  } else
  {
    node* head = this->dummy->get_next();
    head->get_next()->set_prev(this->dummy);
    this->dummy->set_next(head->get_next());
    delete head;
    --this->size;
  }
}

void dlist::print()
{
  node* curr = this->dummy;
  LOOPS(i, this->size)
  {
    curr = curr->get_next();
    PF("Elem %zu is %i\n", i, curr->get_value());
  }
}

int main()
{
  dlist dl;
  dl.remove_back();
  dl.push_front(2);
  dl.push_back(5);
  dl.push_back(3);
  dl.push_back(4);
  dl.push_front(7);
  dl.remove_back();
  dl.remove_front();
  dl.print();
  return 0;
}
