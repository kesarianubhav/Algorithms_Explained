#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define FI(i,a,b) for(int i=a;i<b;i++)
#define FD(i,a,b) for(int i=a;i>=b;i--)
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    int a[m+1][n+1],dp[m+1][n+1];
    for(int i=0;i<n;i++) {for(int j=0;j<n;j++) cin>>a[i][j];}
    dp[0][0]=a[0][0];
    for(int i=1;i<n;i++) dp[0][i]=dp[0][i-1]+a[0][i];
    for(int i=1;i<n;i++) dp[i][0]=dp[i-1][0]+a[i][0];
    for(int i=1;i<m;i++)
    {
      for(int j=1;j<n;j++)
      {
        dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+a[i][j];
      }
    }

    for(int i=0;i<m;i++)
    {  for(int j=0;j<n;j++) cout <<dp[i][j]<<"\t";
      cout <<"\n";
    }
  }
}
