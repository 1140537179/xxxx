#include <iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector> 
#include<string.h>
#include<sstream>
using namespace std;
#define ll long long
#define N 100005
struct cnm
{
	int from,to,d;
}w[N];
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		memset(w,0,sizeof(w));
		for(int i=0;i<n;i++)
		{
			cin>>w[i].from>>w[i].to;
			w[w[i].from].d++;
			w[w[i].to].d++;
		}
		int biaoji1=0;
		int biaoji2=0;
		int biaoji3=0;
		for(int i=0;i<n;i++)
		{
			if(w[w[i].from].d==2&&w[w[i].to].d==2)
			biaoji1++;
			if(w[w[i].from].d==n||w[w[i].to].d==n)
			biaoji2=1;
			if(w[w[i].from].d==1||w[w[i].to].d==1)
			biaoji3++;
		}
		if(biaoji1==n)
		{
			cout<<"ring topology"<<endl;
			continue;
		}
		else if(biaoji1==n-2&&biaoji3==2)
		{
			cout<<"bus topology"<<endl;
			continue;
		}
		else if(biaoji2==1)
		{
		cout<<"star topology"<<endl;
		continue;
	    }
		else
		{
		cout<<"unknown topology"<<endl;
		continue;
	    }
		
		
	}
	return 0;
} 
