#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int create(int seg[],int arr[],int index,int cl,int cr)
{
    if(cl==cr) {seg[index]=arr[cl]; return seg[index];}
    int mid = cl+(cr-cl)/2;
    seg[index]=max(create(seg,arr,2*index+1,cl,mid) , create(seg,arr,2*index+2,mid+1,cr));
    return seg[index];
}
int maxRange(int seg[],int index,int cl,int cr,int l,int r)
{
    if(cl>r || cr<l) return INT_MIN;
    if(cl>=l && cr<=r) return seg[index];
    int mid=cl+(cr-cl)/2;
    return max(maxRange(seg,2*index+1,cl,mid,l,r) , maxRange(seg,2*index+2,mid+1,cr,l,r));
}
int main() 
{
       int n ,q ;
       cin >> n >> q;
       int arr[n];
       for(int i=0;i<n;i++) cin >> arr[i];
       int seg[4*n];
       create(seg,arr,0,0,n-1);
       while(q--)
       {
           int d;
           cin >> d;
           int ans,minu=99999999;
           for(int i=0;i<n;i++)
           {
               int p = i+d-1;
               if(p>=n) break;
               else
               {
                    ans = maxRange(seg,0,0,n-1,i,i+d-1);
                    if(ans<minu) minu=ans;
               }
           }cout<<minu<<"\n";
       }}
