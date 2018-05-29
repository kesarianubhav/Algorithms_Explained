#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin>>n;
    int price[n+1];
    for(int i=1;i<=n;i++) cin >> price[i];
    price[0]=0;
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[1]=price[1];
    for(int i=1;i<=n;i++)
    {
      int minu=-999999;
      for(int j=1;j<=i;j++)
      {
        if(price[j]+dp[j-i]>minu) minu=price[j]+dp[i-j];
      }
      dp[i]=minu;
    }

    for(int i=0;i<=n;i++) cout <<dp[i]<<"\t" ;
    cout <<"\n";
  }
}
