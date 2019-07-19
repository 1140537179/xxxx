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
#define N 500005
vector<int>G[N];
int color[N];
int m,n,start;
void init()
{
	for(int i=0;i<=m;i++)
	{
		G[i].clear();
		color[i]=-1;
	}
}
int ranse()
{
	
	queue<int>q;
	q.push(start);
	color[start]=2;
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		for(int i=0;i<G[a].size();i++)
		{
			if(color[G[a][i]]==color[a])
			{
				return 1;
			}
			else
			{
				if(color[G[a][i]]==-1)
				{
					color[G[a][i]]=-color[a];
					q.push(G[a][i]);
				}
			}
		}
	}
	return 0;
}
int main()
{
	int T,cnt;
	while(~scanf("%d",&T)) 
{
	cnt=1;
	while(T--)
	{
	    scanf("%d%d%d",&m,&n,&start);
		init();
		for(int i=0;i<n;i++)
		{
			int s,t;
			scanf("%d%d",&s,&t);
			G[s].push_back(t);
			G[t].push_back(s);
		}
		cout<<"Case "<<cnt<<": ";
	    cnt++;
		if(ranse()==0)
		{
			cout<<"NO"<<endl;
	    }
	    else
	    cout<<"YES"<<endl;
    }
}
	return 0;
} 

