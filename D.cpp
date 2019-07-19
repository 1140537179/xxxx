#include <iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector> 
#include<string.h>
#include<sstream>
#include<cmath>
using namespace std;
#define N 100005
int a[N],b[N];
vector<int>G[N];
vector<int>cun;
int m;
void init()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=m;i++)
	G[i].clear();
	cun.clear();
	
}
void bfs(int zi,int fu,int ji,int ou)
{
	if(ji)
	a[zi]^=1;
	if(a[zi]!=b[zi])
	{
		a[zi]^=1;
		ji^=1;
		cun.push_back(zi);
	}
	int j;
	for(int i=0;i<G[zi].size();i++)
	{
		j=G[zi][i];
		if(j==fu)
		continue;
		else
		bfs(j,zi,ou,ji);
	}
}
int main()
{
	while(cin>>m)
	{
		init();
		int p,q;
		for(int i=1;i<m;i++)
		{
			cin>>p>>q;
			G[p].push_back(q);
			G[q].push_back(p);
		}
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
		}
		bfs(1,-1,0,0);
		cout<<cun.size()<<endl;
		for(int i=0;i<cun.size();i++)
		{
			cout<<cun[i]<<endl;
		}
	}
	return 0;
}

