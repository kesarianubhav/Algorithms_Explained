#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define FI(i,a,b) for(int i=a;i<b;i++)
#define FD(i,a,b) for(int i=a;i>=b;i--)
int main ()
{
int t ;
cin >> t ;
while ( t--)
  {
    int n ;
    cin >> n ;
    int a[n+1][n+1],dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    FI(i,0,n)
      FI(j,0,n) cin>>a[i][j];

    FI(i,0,n)
      FI(j,0,n) if(a[i][j]==1) dp[i][j]=1;
    FI(i,1,n)
    {
      FI(j,1,n)
      {
        if( a[i][j] ==1 && a[i-1][j]>=1 && a[i][j-1]>=1 && a[i-1][j-1]>=1) dp[i][j]=dp[i-1][j-1]+1;
      }
    }

    FI(i,0,n)
    {FI(j,0,n) cout << dp[i][j]<<"\t";
    cout <<"\n";
    }
  }
}
