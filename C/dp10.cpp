#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while ( t--)
  {
    int n ;
    cin >> n;
    int t[n][n];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++) cin >> t[i][j];
    int dp[n][n],dp2[n][n];
    memset(dp,0,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    dp[0][0]=1;
    dp2[0][0]=t[0][0];
    for(int i=1;i<n;i++)
      if (dp[0][i-1]>0 && (t[0][i-1]==1 || t[0][i-1]==3 )) dp[0][i]=1;
      for(int i=1;i<n;i++)
      if (dp[i-1][0]>0 && (t[i-1][0]==2 || t[0][i-1]==3)) dp[i][0]=1;

      for(int i=1;i<n;i++)
      {
        for(int j=1;j<n;j++)
        {
          if(t[i][j-1]==1 ) dp[i][j]+=dp[i][j-1];
          if(t[i-1][j]==2 ) dp[i][j]+=dp[i-1][j];
          if(t[i][j-1]==3 ) dp[i][j]+=dp[i-1][j];
          if(t[i-1][j]==3 ) dp[i][j]+=dp[i][j-1];
        }
      }


      for(int i=1;i<n;i++)
        if (dp[0][i-1]>0 && (t[0][i-1]==1 || t[0][i-1]==3 )) dp2[0][i]=dp[0][i-1]+t[0][i];
        for(int i=1;i<n;i++)
        if (dp[i-1][0]>0 && (t[i-1][0]==2 || t[0][i-1]==3)) dp[i][0]+=t[i][0];


      for(int i=1;i<n;i++)
      {
        for(int j=1;j<n;j++)
        {
          if(t[i][j-1]==1 ) dp2[i][j]+=t[i][j];
          if(t[i-1][j]==2 ) dp2[i][j]+=t[i][j];
          if(t[i][j-1]==3 ) dp2[i][j]+=t[i][j];
          if(t[i-1][j]==3 ) dp2[i][j]+=t[i][j];

        }
      }

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
          cout << dp[i][j]<<"\t";
          cout <<"\n";
      }

      cout << "\n";

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
          cout << dp2[i][j]<<"\t";
          cout <<"\n";
      }
  }
}
