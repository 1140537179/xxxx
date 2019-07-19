#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector> 
#include<string.h>
#include<sstream>
#include<cmath>
using namespace std;
#define N 105
int fa[N];
int m,n;
struct cnm
{
	int from,to,quan;
}w[N];
bool cmp(cnm a,cnm b)
{
	return a.quan<b.quan;
}
int find(int x)
{
	if(x==fa[x])
	return x;
	return fa[x]=find(fa[x]);
}
void init()
{
	for(int i=1;i<=n;i++)
	fa[i]=i;
	memset(w,0,sizeof(w));
}
int panding()
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
	if(fa[i]==i)
	sum++;
    }
    if(sum==1)
    return 1;
    else
    return 0;
	 
}
int main()
{
	while(cin>>m>>n&&m!=0)
	{
		int i;
		init();
	    for(i=0;i<m;i++)
	    {
	    	cin>>w[i].from>>w[i].to>>w[i].quan;
		}
		sort(w,w+m,cmp);
		int sum=0;
		for(i=0;i<m;i++)
		{
			if(find(w[i].from)!=find(w[i].to))
			{
				fa[find(w[i].from)]=find(w[i].to);
				sum+=w[i].quan;
			}
		}
		if(panding()==0)
		cout<<"?"<<endl;
		else
		cout<<sum<<endl;
	}
	return 0;
}

