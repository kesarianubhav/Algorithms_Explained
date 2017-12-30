#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
#define FI(i,a,b) for(int i=a;i<b;i++)
#define output(x) printf("x")
#define pb push_back
using namespace std;
int graph[1000][1000];
bool check[1000006];
bool visited[100006];

vector<int> output;
void dfs( int n , vector<int> v[] , int start  )
{
	visited[start] = true ;
	stack<int> s ;
	s.push(start);
	while(!s.empty())
	{
		int p = s.top();
		s.pop();
		output.pb(p);
		for(std::vector<int>::iterator it = v[p].begin();it!=v[p].end();++it)
			if(visited[(*it)]==false) 
			{
				visited[*it]=true;
				s.push(*it);
			}
	}
}

void graph_printer(int v , vector<int> ve[])
{
	FI(i,0,v)
	{
		std::vector<int> :: iterator it ;
		for( it = ve[i].begin();it!=ve[i].end();++it)
			cout<<(*it)<<"\t";
		cout<<"\n";
	}
}

int main()
{
	int v;
	cin >> v;
	vector<int> adjacency[v];
	int a;
	FI(i,0,v)
	{
		FI(j,0,v)
		{ 
		if(i==j) continue;
		cout<<"b/w "<<i<<"and"<<j<<"\n"; 
		cin >>a; 
		if(a==1) 
				adjacency[i].pb(j); 
		}
	}	
	graph_printer(v,adjacency);
	dfs(v,adjacency,0);
	std::vector<int> :: iterator it ;
	cout<<"\n";
	for( it = output.begin();it!=output.end();++it)
		cout<<(*it)<<"\t";
	
}

 
