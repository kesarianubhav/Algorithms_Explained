#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define FI(i,a,b) for(int i=a;i<b;i++)
#define FD(i,a,b) for(int i=a;i>=b;i--)
int a[1000002],b[1000002];
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        FI(i,0,n) cin>>a[i];
        stack<int> s;
        s.push(n-1);
        b[0]=-1;
    for(long long i=n-1;i>=0;i--)
    {
        if(a[i]>a[s.top()])
        {
            while(!s.empty() && a[i]>a[s.top()])
            {
                b[s.top()]=i;
                s.pop();
            }
        }s.push(i);
    }while(!s.empty()) { b[s.top()] = -1; s.pop(); }
        
        FI(i,0,n) 
        {
            if(b[i]==-1) cout<<i+1<<" ";
            else
            cout<<(i-b[i])<<" ";
        }
     
     cout<<"\n";   
    }
}
