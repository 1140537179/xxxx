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
int fa[N];
int rank1[N];
int m,n,k;
int w[N];
void init()
{
	for(int i=1;i<=m;i++)
	{
	fa[i]=i;
	rank1[i]=1;
    }
}
int find(int x)
{
	if(x==fa[x])
	return x;
	return fa[x]=find(fa[x]);
}
int merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		fa[fy]=fx;
		rank1[fx]+=rank1[fy];
	}
	return rank1[fx];
}
int main()
{
	cin>>m>>n;
	{
		init();
		int i,j;
		for(i=0;i<n;i++)
		{
			int k;
			cin>>k;
			int a,b;
			for(j=0;j<k;j++)
			{
				cin>>w[j];
				merge(w[0],w[j]);
			}
		}
		for(i=1;i<=m;i++)
		{
			if(i==1)
			cout<<rank1[find(i)];
			else
		  cout<<" "<<rank1[find(i)];
	    }
	    cout<<endl;
		
	}
	return 0;
}

