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
    int l=n;
    int DP[n+1];
    DP[0]=1;
    DP[1]=1;
    DP[2]=1;
    for(int i=2;i<=n;i++)
    {
      int maxo=-99999;
      for(int j=1;j<=i-1;j++)
        {
          int a = j*DP[i-j];
          int b = j*(i-j);
          int c = max ( a,b );
          if(c>maxo ) maxo = c;
        }


      DP[i]=maxo;
    }

    cout << DP[l]<<"\n";
  }
}
