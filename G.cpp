#include <iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue> 
#include<cstring>
using namespace std;
#define ll long long
int vis[25][7];
queue<string> Q[7];
void chaxun(int m)
{
	if(m%2)
	{
		for(int i=1;i<=20;i++)
		{
			if(vis[i][(m-1-8)/2+1])
			cout<<i<<"�Ż�������ʹ��"<<endl;
			else
			cout<<i<<"�Ż�����ʹ��"<<endl; 
		}
	}
	else
	{
			for(int i=1;i<=20;i++)
		  {
			if((vis[i][(m-8)/2+1]&&m!=20)||(m==20&&vis[i][6]))
			{
			cout<<i<<"�Ż�������ʹ��"<<endl;
		    }
			else
			cout<<i<<"�Ż�����ʹ��"<<endl; 
		  }
	}
}
void yuyue(int l,int r)
{
	int j,biaoji=0,jilu=l,jilu1=r;
	for(int j=1;j<=20;j++)
	{
		if(l%2)
		{
			if(vis[j][(l-1-8)/2+1]==0)
			{
			biaoji=1;
			vis[j][(l-1-8)/2+1]=1; 
			break;
		    }
		}
		else
		{
				if(vis[j][(l-8)/2+1]==0)
				{
					biaoji=1;
					vis[j][(l-8)/2+1]=1;
					break;
				}
		}
	}
	int biaoji1=0,i;
	if(biaoji==0)
	{
	  	for(i=l;i>=8;i-=2)
	  	{
	  		for(j=1;j<=20;j++)
	  		{
			 if(i==20)
			{
				if(vis[j][6]==0)
				{
					biaoji1=1;
					jilu=18;
					break;
				}
			}
			else
			{
				if(vis[j][(i-8)/2+1]==0)
				{
					biaoji1=1;
					jilu=i;
					break; 
				}
			}
		}
		if(biaoji1==1)
		break;
	   }
		biaoji1=0;
		for(i=r;i<=20;i+=2)
	  	{
	  		for(j=1;j<=20;j++)
	  		{
			 if(i==20)
			{
				if(vis[j][6]==0)
				{
					biaoji1=1;
					jilu1=18;
					break;
				}
			}
			else
			{
				if(vis[j][(i-8)/2+1]==0)
				{
					biaoji1=1;
					jilu1=i;
					break; 
				}
			}
		   }
		if(biaoji1==1)
		break;
	    }
		if(min(l-jilu,jilu1-r)==l-jilu||jilu1-r==0)
		cout<<"�����λʱ���Ϊ��"<<jilu<<"-"<<jilu+2<<endl;
		else
		cout<<"�����λʱ���Ϊ��"<<jilu1<<"-"<<jilu1+2<<endl;
		cout<<"1.�ڷǿ�ʱ���ϻ�"<<endl;
		cout<<"2.���ڷǿ�ʱ���ϻ�"<<endl;
		int m;
		cin>>m;
		if(m==1)
		{
			string s;
			cout<<"������ϵ��ʽ��"; 
			cin>>s;
			if(l%2)
			Q[(l-1-8)/2+1].push(s);
			else
			{
				Q[(l-8)/2+1].push(s);
			}
		}
	  }
}
void tuichuyuding(int m)
{
	int i,j;
	int biaoji=0;
	int d;
	if(m%2)
	d=(m-1-8)/2+1;
	else
	{
		if(m==20)
		d=6;
		else
		d=(m-8)/2+1;
	}
	   for(j=1;j<=20;j++)
	   {
	   	    if(vis[j][d]==1)
	   	    biaoji=1;
	   	    vis[j][d]=0;
	   }
	   if(biaoji==0)
	   cout<<"����û��ԤԼ"<<endl;
}
void chadengdaixinxi()
{
	int i,j;
	for(i=8;i<20;i+=2)
	{
		if(!Q[(i-8)/2+1].empty())
		{
		cout<<"ʱ�����"<<i<<"-"<<i+2<<"�ĵȴ���ϢΪ��"<<endl;
		while(!Q[(i-8)/2+1].empty())
		{
			cout<<Q[(i-8)/2+1].front()<<endl;
			Q[(i-8)/2+1].pop();
		}
	    }
	    else
	    cout<<"ʱ�����"<<i<<"-"<<i+2<<"û�еȴ���Ϣ"<<endl;
	}
}
int main()
{
   cout<<"0.�˳�"<<endl;
   cout<<"1.��ѯ"<<endl;
   cout<<"2.��λԤ��"<<endl;
   cout<<"3.�˳�Ԥ��"<<endl;
   cout<<"4.��ѯ�ȴ���Ϣ"<<endl;
   int m;
   while(1)
   {
   cout<<"����ָ�"<<endl;
   cin>>m;
   	  if(m==0)
   	  {
   	  	break;
	  }
	  if(m==1)
	  {
	  	 int n;
	  	 cout<<"��������Ҫ��ѯ��ʱ��: ";
	  	 cin>>n;
	  	 chaxun(n);
	  }
	  if(m==2)
	  {
	   	int l,r;
	   	cout<<"��������ҪԤԼ��ʱ��Σ�";
	   	cin>>l>>r;
	   	yuyue(l,r);
	  }
	  if(m==3)
	  {
	  	int n;
	  	cout<<"��������Ҫȡ��ԤԼ��ʱ�䣺";
	  	cin>>n;
	  	tuichuyuding(n);
	  }
	  if(m==4)
	  {
	  	 chadengdaixinxi();
	  }
  }
  return 0;
}
