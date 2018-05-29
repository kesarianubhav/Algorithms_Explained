#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while ( t--)
    {
        int n,l,r;
        cin >> n>>l>>r;
        int p = 0;
        for(int i=l;i<=r;i++)
        p+=pow(2,i-1);

        int ans = __builtin_popcount( p&n ) ;
        //cout <<p<<"\n"<<ans<<"\n";
        cout <<(r-l+1)-(ans)<<"\n";
        
    }
}
