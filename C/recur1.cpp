#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
char str[1000];

void fn2(int l,int r)
{
    if(l>=r) return;
    for(int i=r;i>=l+1;i--)
    {
        if(str[i]<str[i-1])
        {
            swap(str[i],str[i-1]);
            cout<<str<<"f\n";
            fn2(i,r);
        }
    }
}


void fn(int l,int r)
{
    if(l>=r) return;
    for(int i=r;i>=l+1;i--)
    {
        if(str[i]>str[i-1])
        {
            //cout <<str[i]<<"<-df\n";
            swap(str[i],str[i-1]);
            cout<<str<<"\n";
            fn2(0,strlen(str)-1);
        }

    }
}

int main()
{
    int t;
    cin >> t;
    while ( t-- )
    {
        cin >> str;
        fn(0,strlen(str)-1);
        cout <<str;
    }
}
