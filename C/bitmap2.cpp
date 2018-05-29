//No. of flip bits needed to convert a to b 

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int setbits(int n)
{
    int count =0;
    while(n)
    {
        count++;
        n=n&(n-1);
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a , b;
        cin >> a >>b;
        int n = a^b;
        //cout << n <<"<- n"<<'\n';
        cout<<setbits(n)<<"\n";
    }
}
