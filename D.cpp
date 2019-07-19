#include <iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<vector> 
#include<string.h>
#include<sstream>
#include<cmath>
using namespace std;
#define N 2000005
int n,m;
int fa[N];
int cun[N];
struct cnm
{
	int x,y,z;
};
vector<cnm>p;
vector<int>q;
int find(int x)
{
	if(x==fa[x])
	return x;
	return fa[x]=find(fa[x]);
}
int merge(int x,int y)
{
	fa[find(x)]=find(y);
}
int query(int x)
{
	return lower_bound(cun+1,cun+1+m,x)-cun;//找x对应为q中的哪个整数 
}
void init()
{
	for(int i=1;i<=2*n;i++)
	{
	fa[i]=i;
    }
	q.clear();
	p.clear();
}
bool cmp(cnm a,cnm b)
{
	return a.z>b.z;
}
void lisanhua()
{
	for(int i=0;i<2*n;i++)
	{
		if(i==0||q[i]!=q[i-1])
		{
		cun[m]=q[i];
		m++;
	    }
	}
}
int main()
{
	int T;
	while(cin>>T)
	{
		while(T--)
		{
			m=1;
			cin>>n;
			init();
			int x,y,z;
			for(int i=0;i<n;i++)
			{
				cin>>x>>y>>z;
				p.push_back({x,y,z});
				q.push_back(x);
				q.push_back(y);
			}
			sort(q.begin(),q.end());
			lisanhua();
			sort(p.begin(),p.end(),cmp);
			int biaoji=0;
			for(int i=0;i<n;i++)
			{
				if(p[i].z==1)
				{
					merge(query(p[i].x),query(p[i].y));
				}
				else
				{
					if(find(query(p[i].x))==find(query(p[i].y)))
					{
						biaoji=1;
						break;
					}
				}
			}
			if(biaoji==1)
			cout<<"NO"<<endl;
			else
			cout<<"YES"<<endl;
		}
	}
	return 0;
}

