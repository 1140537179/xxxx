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
int fa[N];
int number[N];
int m,n,k;
int biaoji;
stack<int>q;
struct cnm
{
	int from,to;
}w[N];
int find(int x)
{
	if(x==fa[x])
	return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	q.push(m-biaoji);
	if(fx!=fy)
	{
		fa[fy]=fx;
		biaoji++;
	}
}
void init()
{
	for(int i=0;i<m;i++)
	fa[i]=i;
	biaoji=0;
	memset(w,0,sizeof(w));
	while(!q.empty())
	q.pop();
}
int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		init();
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&w[i].from,&w[i].to);
		}
		for(i=n-1;i>=0;i--)
		{
			merge(w[i].from,w[i].to);
		}
		while(!q.empty())
		{
			printf("%d\n",q.top());
			q.pop();
		}	
	}
	return 0;
}
