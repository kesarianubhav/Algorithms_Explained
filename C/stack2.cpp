#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int minEle;

stack<int> for_min;

int _stack :: getMin()
{
   //Your code here
   return for_min.top();
}
/*returns poped element from stack*/
int _stack ::pop()
{
    int p = s.top();
    s.pop();
    for_min.pop();
    return p;
}
/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   s.push(x);
   if(s.empty()) for_min.push(x);
   else
   {
       int p = for_min.top();
       if(p<x) for_min.push(x);
       else for_min.push(p);
   }

}


int main()
{
  int t;
  cin >> t ;
  int n ;
  int a;
  for ( int i=0;i<n;i++) {cin >> a; s.push(a);
    
}
