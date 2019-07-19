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
vector<int>G[N];
int fa[N];
int vis[N];
int m,n,k;
int maxx=0,start,end1,length;
void init()
{
	memset(fa,0,sizeof(fa));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
	G[i].clear();
	
}
void cha(int point)
{
	int j;
	int biaoji1=0;
	for(int i=0;i<G[point].size();i++)
	{
		j=G[point][i];
		if(vis[j]!=0)
		{
			if(vis[point]-vis[j]+1>k)
			{
			maxx=vis[point]-vis[j]+1;
			start=j;
			end1=point;
		    }
		}
		else
		{
		vis[j]=vis[point]+1;
	    fa[j]=point;
		cha(j);
	    }
	}
}
int main()
{
	while(cin>>m>>n>>k)
	{
		init();
		int p,q;
		for(int i=1;i<=n;i++)
		{
			cin>>p>>q;
			G[p].push_back(q);
			G[q].push_back(p);
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i]!=1)
			{
				vis[i]=1;
				cha(1);
			}
		}
		cout<<maxx<<endl;
		int o=end1;
		int biaoji=0;
		while(o!=start)
		{
			if(!biaoji)
			{
			cout<<o;
			biaoji=1;
		    }
		    else
		    {
			o=fa[o];
			cout<<" "<<o;
		    }   
		}
		cout<<endl;
	}
	return 0;
}

