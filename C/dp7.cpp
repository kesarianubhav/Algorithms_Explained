#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int n;
int f(string s,int j)
{
    if(s.length()==1) return 1;
    if(j%2==0)
    {
        string s1 = s.substr(0,(j/2)),s2=s.substr(j/2,j/2);
        if(s1.compare(s2)==0)
          return(min(f(s1,(j/2)) , f(s.substr(0,j-1),j-1)) +1 );
        else
          return (1+f(s.substr(0,j-1),j-1));
    }
    else
    return 1+f(s.substr(0,j-1),j-1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        n =s.length();
        //cout<<"sf\n";
        cout << f(s,n);
        //cout<<"sf\n";
    }
}
