#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++) cin>>a[i];
    //map<int,int> m;
    stack<int> s;
    int count=0;
	s.push(0);
    for(int i=0;i<n;i++)
    {
        if(a[i]>s.top())
        {
            while(!s.empty() && a[i]>a[s.top()])
            {
                //m[s.top()]=i;
                count++;
                s.pop();
            }
        } s.push(i);
    }while(!s.empty()) { s.pop(); }
    
    s.push(n-1);
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>s.top())
        {
            while(!s.empty() && a[i]>a[s.top()])
            {
                //m[s.top()]=i;
                count++;
                s.pop();
            }
        } s.push(i);
    }cout<<count-1<<"\n";
}
