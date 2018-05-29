#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
  int n_2=2 ,n_3=3,n_5=5;
  int n ;
  cin >> n;
  int ugly[n+1];
  ugly[0]=1;
  for(int i=1;i<=n;i++)
  {
    int next=min(n_2,min(n_3,n_5));
    ugly[i]=next;
    if(next==n_2) n_2+=2;
    if(next==n_3) n_3+=3;
    if(next==n_5) n_5+=5;
  }

  cout << ugly[n-1]<<"\n";
}
