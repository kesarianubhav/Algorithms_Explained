#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std ;

stack<int> s;
struct node
{
    int data;
    struct node  * next ;
};
typedef struct node Node ;

struct node * start =NULL ;

void insert(int x)
{
  struct node * temp2 =start ;
  struct node * temp = (struct node *)(malloc(sizeof(struct node)));
  temp->next=NULL;
  temp->data = x;

  if(start==NULL)
    start=temp;

  else
  {while(temp2->next!=NULL) temp2=temp2->next;
  temp2->next=temp; }
}


void printer(struct node *start)
{
  struct node * a =start;
  while(a!=NULL)
  {
    cout <<a->data<<"\n";
    a=a->next;
  }
}

int main()
{
  //struct node * start =NULL;
  insert(4);
  insert(5);
  insert(6);
  insert(7);
  cout<<(start->data);
  //printer(start);
}
