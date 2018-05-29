#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int arr[n];
    for ( int i=0;i<n;i++ )cin >> arr[i];
    int dp[n];a
    dp[n-1]=0;
    memset(dp,0,sizeof(dp));
    for(int i=n-2;i>=0;i--)
    {
      int m=99999;
      for(int j=i+1;j<=i+arr[i];j++)
      {
        if(j>n-1) break;
        m=min(dp[j]+1,m);
      }
      dp[i]=m;
    }


    for(int i=0;i<n;i++) cout <<dp[i]<<"\t";
  }
  return 0;
}
