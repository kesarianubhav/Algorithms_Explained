//Developed by Anubhav Kesari
//Stack that has Insertion,Deletion,Maximum,Minimum in O(1)
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main() {
    int t ;
    cin >> t ;
    stack<int> s;
    s.push(-999999);
    stack<int> s2;
    s2.push(-999999);
    while(t--)
    {
                int a ;
                cin >> a ;
                if(a==1)
                {
                    int b ;
                    cin >> b ;
                    int temp = s2.top();
                    if(b<temp) s2.push(temp);
                    else s2.push(b);
                    s.push(b);
                }
                if(a==2)   {s.pop(); s2.pop();}
                if(a==3)   cout<<s2.top()<<"\n";
    }
}
