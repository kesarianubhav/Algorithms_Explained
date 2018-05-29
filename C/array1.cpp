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
        int n,q;
        cin >>n>>q;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[(i+q+1)%n];
        //for(int i=0;i<n;i++) a[(i+q)%n]=a[i];
        for(int i=0;i<n;i++) cout<<a[i];

    }
}
