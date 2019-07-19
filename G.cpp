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
			cout<<i<<"号机已有人使用"<<endl;
			else
			cout<<i<<"号机无人使用"<<endl; 
		}
	}
	else
	{
			for(int i=1;i<=20;i++)
		  {
			if((vis[i][(m-8)/2+1]&&m!=20)||(m==20&&vis[i][6]))
			{
			cout<<i<<"号机已有人使用"<<endl;
		    }
			else
			cout<<i<<"号机无人使用"<<endl; 
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
		cout<<"最近空位时间段为："<<jilu<<"-"<<jilu+2<<endl;
		else
		cout<<"最近空位时间段为："<<jilu1<<"-"<<jilu1+2<<endl;
		cout<<"1.在非空时间上机"<<endl;
		cout<<"2.不在非空时间上机"<<endl;
		int m;
		cin>>m;
		if(m==1)
		{
			string s;
			cout<<"输入联系方式："; 
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
	   cout<<"您还没有预约"<<endl;
}
void chadengdaixinxi()
{
	int i,j;
	for(i=8;i<20;i+=2)
	{
		if(!Q[(i-8)/2+1].empty())
		{
		cout<<"时间段在"<<i<<"-"<<i+2<<"的等待信息为："<<endl;
		while(!Q[(i-8)/2+1].empty())
		{
			cout<<Q[(i-8)/2+1].front()<<endl;
			Q[(i-8)/2+1].pop();
		}
	    }
	    else
	    cout<<"时间段在"<<i<<"-"<<i+2<<"没有等待信息"<<endl;
	}
}
int main()
{
   cout<<"0.退出"<<endl;
   cout<<"1.查询"<<endl;
   cout<<"2.机位预订"<<endl;
   cout<<"3.退出预定"<<endl;
   cout<<"4.查询等待信息"<<endl;
   int m;
   while(1)
   {
   cout<<"输入指令："<<endl;
   cin>>m;
   	  if(m==0)
   	  {
   	  	break;
	  }
	  if(m==1)
	  {
	  	 int n;
	  	 cout<<"请输入你要查询的时间: ";
	  	 cin>>n;
	  	 chaxun(n);
	  }
	  if(m==2)
	  {
	   	int l,r;
	   	cout<<"请输入你要预约的时间段：";
	   	cin>>l>>r;
	   	yuyue(l,r);
	  }
	  if(m==3)
	  {
	  	int n;
	  	cout<<"请输入你要取消预约的时间：";
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
