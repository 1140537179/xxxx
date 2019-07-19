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
#define N 200050
priority_queue<int>q;
struct cnm
{
     int value;
     int prev,next;
}node[N];
int head,tot,hail;
void build()
{
	tot=2;
	head=1;
	hail=2;
	node[head].next=hail;
	node[hail].prev=head;
}
void insert(int p,int val)
{
	int q=++tot;
	node[q].value=val;
	node[node[p].next].prev=q;
	node[q].next=node[p].next;
	node[q].prev=p;
	node[p].next=q;
}
void remove(int p)
{
	node[node[p].next].prev=node[p].prev;
	node[node[p].prev].next=node[p].next;
}
void clear()
{
	memset(node,0,sizeof(node));
	head=hail=tot=0;
}
int w[N];//供输入样例 
int vis[N];//记录最大值是否已经用过或已经删去 
int zuobiao[N];//记录坐标 
int dui[N];//记录在哪一队 
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		clear();
		build();
		memset(w,0,sizeof(w));
		memset(vis,0,sizeof(vis));
		memset(zuobiao,0,sizeof(zuobiao));
		memset(dui,0,sizeof(dui));
		int max;
		int dizhi=head;//链表插入最开始的地址 
		for(int i=1;i<n+1;i++)
		{
			cin>>w[i];
			zuobiao[w[i]]=i;//记录值对应的坐标 
			q.push(w[i]);//优先队列输入 
			insert(dizhi,w[i]);//链表插入 
			dizhi=node[dizhi].next;//更新要插入数值的地址 
		}
		int ci=0;
		while(1)
	{
		max=0;
		while(!q.empty())
		{
			if(vis[q.top()]!=1)
			{
			max=q.top();
			break;
		    }
		    q.pop();
		}//找可用最大值 
		if(max==0)
		break;//没有可用的最大值时程序结束 
		int l,r,ll,rr;//l,r表示数组的下标 
		int i=0;
		for(l=zuobiao[max],r=zuobiao[max];i<=k;i++) 
		{
			if(i==0)//中心点 
			{
			ll=l+2;// 
			rr=r+2;//链表下标 
			vis[node[ll].value]=1;//标记 表示最大值已用过 
			if(ci%2==0)
			{
				if(dui[node[ll].value]==0)
				dui[node[ll].value]=1;
			}
			else
			{
				if(dui[node[ll].value]==0)
				dui[node[ll].value]=2;
			}
			remove(ll);//移除 
		    }
		    else
		  {
		    if((l-i)>=1&&node[ll].prev!=head)//判断中心点左边k个点 
		    {
		    ll=node[ll].prev;//链表左端 
			vis[node[ll].value]=1;
			if(ci%2==0)
			{
				if(dui[node[ll].value]==0)
				dui[node[ll].value]=1;
			}
			else
			{
				if(dui[node[ll].value]==0)
				dui[node[ll].value]=2;
			}
			remove(ll);
		    }
		    if((l+i)<=n&&node[rr].next!=hail)//判断中心点右边k个点 
		    {
		    rr=node[rr].next;
			vis[node[rr].value]=1;
			if(ci%2==0)
			{
				if(dui[node[rr].value]==0)
				dui[node[rr].value]=1;
			}
			else
			{
				if(dui[node[rr].value]==0)
				dui[node[rr].value]=2;
			}
			remove(rr);
	    	}
	    	
		  }
	 }
		ci++;
	}
	for(int i=1;i<n+1;i++)
	{
		cout<<dui[w[i]];
	}
	cout<<endl;
	}

	return 0;
} 

