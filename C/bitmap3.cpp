//Swapping the nibbles 

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
    while (t--)
    {
        int a;
        cin >>a;
        int n1 = (a&240) >>4;
        int n2 = (a&15) << 4;
        cout<<n1+n2<<"\n";
    }
}
