#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    char a[100],b[100];
    cin >> a>>b;
    int dp[101][101];
    memset(dp,0,sizeof(dp));
    int p = strlen(a);
    int q = strlen(b);
    if(a[p-1]==b[q-1]) dp[p-1][q-1]=1; else dp[p-1][q-1]=0;
    for( int j=q-2;j>=0;j--)
    {
      if(a[p-1]==b[j] || dp[p-1][j+1]==1) dp[p-1][j]=1;
    }

    for( int j=p-2;j>=0;j--)
    {
      if(a[j]==b[q-1] || dp[j+1][q-1]==1) dp[j][q-1]=1;
    }

    for(int i=p-2;i>=0;i--)
    {
      for(int j=q-2;j>=0;j--)
      {
        if(a[i]==b[j]) dp[i][j]=1+dp[i+1][j+1];
        else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
      }
    }

    for(int i=0;i<p-1;i++)
    {
      for(int j=0;j<q;j++) cout <<dp[i][j]<<"\t";
      cout <<"\n";
    }
  }
}
