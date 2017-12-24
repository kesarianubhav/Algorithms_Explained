#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
#define FI(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    int n;
    cin >>n;
    int a[n],b[n],c[n];
    FI(i,0,n) cin>>a[i];
    stack<int> s;
    s.push(a[0]);
    FI(i,0,n)
    {
        if(a[i]>s.top())
        {
            while(a[i]>a[s.top()])
            {
                b[s.top()]=i;
                s.pop();
                if(s.empty()) break;
            }
        } s.push(i);
    }while(!s.empty()) { b[s.top()] = -1; s.pop(); }
    
    s.push(a[n-1]);
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>a[s.top()])
        {
            while(a[i]>a[s.top()])
            {
                c[s.top()]=i;
                s.pop();
                if(s.empty()) break;
            }
        }s.push(i);
    }while(!s.empty()) { c[s.top()] = -1; s.pop(); }

    FI(i,0,n) 
    {
        if(c[i]==-1 && b[i]==-1) cout<<"-2 ";
        if((c[i]==-1 && b[i]!=-1) || (c[i]!=-1 && b[i]==-1)) cout<<c[i]+b[i]+1<<" ";
        if(c[i]!=-1 && b[i]!=-1) cout<<c[i]+b[i]+2<<" ";
    }}
