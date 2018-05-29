#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int adj[100][100];

stack<int> s;
bool vertices[100];
int main()
{
  int v;
  cin >> v;
  int arr[v][v];
  memset(adj,0,sizeof(arr));
  for(int i=0;i<v;i++) vertices[i]=false;
  int op;
  for(int i=0;i<v;i++)
  {
    for(int j=i+1;j<v;j++)
    {
      if(i!=j){
      cout<<"for "<<i<<"and "<<j<<"\t";
      cin >> op;
      if(op==1) { adj[i][j]=1; }
    }}
  }

  int start;
  cin >> start;
  s.push(start);
  vertices[start]=true;
  while(!s.empty())
  {
    int p = s.top();
    s.pop();
    cout<<p<<"->\t";
    for(int i=0;i<v;i++)
    {
      if(adj[p][i]==1 && vertices[i]!=true) {s.push(i); vertices[i]=true;}
    }
  }

}
