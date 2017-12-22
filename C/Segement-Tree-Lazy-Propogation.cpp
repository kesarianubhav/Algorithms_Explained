//Created by Anubhav Kesari
//I solved the range minimum query and range updation using Segement Tree using Lazy Propogation


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
#define floop(i,a,b)  for(int i=a;i<b;i++)
#define MOD 1000000007
#define enter cout<<"\n"
using namespace std;
void print(int arr[],int n)  {   floop(i,0,n) cout<<arr[i]<<" ";  }
int fill_tree(int seg[] , int index , int cl , int cr , int arr[])
{
	if(cl==cr) 
	{
		seg[index] = arr[cl];
		return seg[index];
	}
	int mid = cl + (cr-cl)/2;
	seg[index] = min(fill_tree(seg,2*index+1,cl,mid,arr) , fill_tree(seg,2*index+2,mid+1,cr,arr));
	return seg[index];
}


// Without taking the Lazy propogation into account
int getMin(int seg[],int i , int cl ,int cr , int l , int r)
{
	if(cl>=l && cr<=r )  return seg[i];
	if( (cl>r) || ( cr<l ) ) return INT_MAX;
	int mid = cl+(cr-cl)/2;
	return min(getMin(seg,2*i+1,cl,mid,l,r), getMin(seg,2*i+2,mid+1,cr,l,r));	
} 

//With taking lazy propogation into account
int rangeMinLazy(int seg[] ,int lazy[] , int i , int cl , int cr , int l , int r)
{
	if(lazy[i]) seg[i]+=lazy[i];
	lazy[2*i+1]+=lazy[i];
	lazy[2*i+2]+=lazy[i];
	lazy[i]=0;
	
	if(cl>r || cr<l) return INT_MAX;
	if(cl>=l && cr<=r) return seg[i];
		
	int mid=cl+(cr-cl)/2;
	return min(rangeMinLazy(seg,lazy,2*i+1,cl,mid,l,r),rangeMinLazy(seg,lazy,2*i+2,mid+1,cr,l,r));

}

void rangeUpdateLazy( int seg[] ,int lazy[] , int i , int cl , int cr , int l , int r , int val )
{
	if(lazy[i]) seg[i]+=lazy[i];
	lazy[2*i+1]+=lazy[i];
	lazy[2*i+2]+=lazy[i];
	lazy[i]=0;
	
	if(cr<l || cl>r) return;
	
	if((cl>=l && cr<=r))
	{
		seg[i]+=val;
		if(cl!=cr)
		{
			lazy[2*i+1]+=val;
			lazy[2*i+2]+=val;
		}
	return ;
	}
	int mid=cl+(cr-cl)/2;
	rangeUpdateLazy(seg,lazy,2*i+1,cl,mid,l,r,val);
	rangeUpdateLazy(seg,lazy,2*i+2,mid+1,cr,l,r,val);
	seg[i]=min(seg[2*i+1],seg[2*i+2]);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin >> n >>q;
	int a[n];
	floop(i,0,n) cin>>a[i];
	int seg[2*n-1];
	memset(seg,0,sizeof(seg));
	fill_tree(seg,0,0,n-1,a);
	int lazy[4*n];
	memset(lazy,0,sizeof(lazy));
	while(q--)
	{
		char ch;
		cin >> ch ;
		if(ch=='q')
		{
		
			int l , r ;
			cin >> l >> r ;
			cout<<rangeMinLazy(seg,lazy,0,0,n-1,l-1,r-1);
			enter;
		}
		
		if(ch=='r')
		{
			int l,r,val;
			cin >> l >>r >>val;
			rangeUpdateLazy(seg,lazy,0,0,n-1,l,r,val);
			enter;
			//print(lazy,2*n-1);
			enter;
		}
	}
}
