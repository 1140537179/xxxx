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
#define N 510
int rdu[N];
int line[N][N];
int m,n;
priority_queue<int,vector<int>,greater<int> > q;
void init()
{
	while(!q.empty())
	q.pop();
	memset(line,0,sizeof(line));
	memset(rdu,0,sizeof(rdu));
}
void top()
{
	int i;
	int biaoji=0;
	for(i=1;i<=m;i++)
	{
		if(rdu[i]==0)
		{
		q.push(i);
		break;
	    }
	}
	while(!q.empty())
	{
		int front=q.top();
		rdu[front]=-1;
		q.pop();
		if(biaoji==0)
		{
		cout<<front;
		biaoji=1;
	    }
	    else
	    cout<<" "<<front;
		for(i=1;i<=m;i++)
		{
			if(line[front][i]==1)
			{
			rdu[i]--;
		    }
		}
		for(i=1;i<=m;i++)
		{
			if(rdu[i]==0)
			{
			q.push(i);
			break;
		    }
		}
    }
}
int main()
{
	while(cin>>m>>n)
	{
		init();
		int i;
		for(i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			if(line[a][b]==0)
			{
			line[a][b]=1;
			rdu[b]++;
		    }
		}
		top();
		cout<<endl;
	}
}

