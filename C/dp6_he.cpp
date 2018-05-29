#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n;
        int a[n];
        int p=0,m=0;
        for(int i=0;i<n;i++) cin>>a[i];
        int plus_one[n] , minus_one[n];
        for(int i=1;i<n;i++)
        {
            if(a[i]==1) {p++; plus_one[i]=plus_one[i-1]+1; minus_one[i]=minus_one[i-1];}
            if(a[i]==-1) {m++; plus_one[i]=plus_one[i-1]; minus_one[i]=minus_one[i-1]+1;}
        }

        for(int i=0;i<n;i++) cout <<plus_one[i]<<"\t"; cout <<"\n";
        for(int i=0;i<n;i++) cout <<minus_one[i]<<"\t"; cout <<"\n";

        cout <<p<<" and "<<m<<"\n";

        int minu=99999999;
        for(int i=0;i<n;i++)
        {
            int c1 = i-0+1,c2=n-c1;
            int ac1 = plus_one[i];
            int ac2=m-minus_one[i];
            int op = abs(c1-ac1) + ( abs(c2-ac2)));
            cout<<"c1="<<c1<<"c2="<<c2<<"op="<<op<<"\n";
            if(op<minu) minu=op;
        }

        cout << minu<<"\n";
    }
}
