#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
  int t ;
  cin >> t ;
  cout << "t="<<t<<"\t";
  while ( t--)
  {
    int a[10000],b[10000];
    int n;
    cin >> n;
    cout << "n="<<n<<"\t";
    for ( int i =0;i<n;i++) cin >> a[i];
    stack<int> s;
    map<int,int> mymap;
    s.push(a[0]);


    for(int i=1;i<n;i++)
    {
      cout <<i<<"\n";
      if(s.top()<a[i])
      {
        cout<<"s.top="<<s.top()<<"\n";
        cout<<"a[i]="<<a[i]<<"\n";
        while(a[i]>s.top() && !s.empty())
        {
            mymap[s.top()]=a[i];
            s.pop();
            if(s.empty()) break;
        }
        s.push(a[i]);
      }
    }

    if(!s.empty())
    {
      while ( !s.empty() )
      {
        mymap[s.top()]=-1;
        s.pop();
      }
    }

    std::map<int,int>::iterator it ;
    for ( it = mymap.begin();it!=mymap.end();it++)
      cout <<it->first<<" = "<<it->second<<"\n";

  }
}
