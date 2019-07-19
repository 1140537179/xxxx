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
int w[N];//���������� 
int vis[N];//��¼���ֵ�Ƿ��Ѿ��ù����Ѿ�ɾȥ 
int zuobiao[N];//��¼���� 
int dui[N];//��¼����һ�� 
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
		int dizhi=head;//��������ʼ�ĵ�ַ 
		for(int i=1;i<n+1;i++)
		{
			cin>>w[i];
			zuobiao[w[i]]=i;//��¼ֵ��Ӧ������ 
			q.push(w[i]);//���ȶ������� 
			insert(dizhi,w[i]);//������� 
			dizhi=node[dizhi].next;//����Ҫ������ֵ�ĵ�ַ 
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
		}//�ҿ������ֵ 
		if(max==0)
		break;//û�п��õ����ֵʱ������� 
		int l,r,ll,rr;//l,r��ʾ������±� 
		int i=0;
		for(l=zuobiao[max],r=zuobiao[max];i<=k;i++) 
		{
			if(i==0)//���ĵ� 
			{
			ll=l+2;// 
			rr=r+2;//�����±� 
			vis[node[ll].value]=1;//��� ��ʾ���ֵ���ù� 
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
			remove(ll);//�Ƴ� 
		    }
		    else
		  {
		    if((l-i)>=1&&node[ll].prev!=head)//�ж����ĵ����k���� 
		    {
		    ll=node[ll].prev;//������� 
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
		    if((l+i)<=n&&node[rr].next!=hail)//�ж����ĵ��ұ�k���� 
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

