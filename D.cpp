#include <iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector> 
#include<list>
#include<string.h>
#include<sstream>
#include<cmath>
#include<numeric>
using namespace std;
struct cnm
{
    int zhi,time;
	bool operator<(const cnm &a) const
	{
		return time>a.time;
	}
	cnm(const int& x,const int& y):zhi(x),time(y){} 
};
int main()
{
	int m,cnt=1;
	while(cin>>m&&m!=0)
{
	string s;
	char a;
	int shijian=0;
	list<cnm>p,q;
	cout<<"Case #"<<cnt<<":"<<endl;
	cnt++;
	while(m--)
	{
		cin>>s>>a;
		if(s=="push")
		{
			int b;
			cin>>b;
			if(a=='A')
			{
			p.push_front(cnm(b,shijian++));	
			}
			else
			q.push_front(cnm(b,shijian++));
		}				
		if(s=="pop")
		{
			if(a=='A')
			{
				cout<<p.front().zhi<<endl;
				p.pop_front();
			}
			else
			{
			cout<<q.front().zhi<<endl;
			q.pop_front();
		    }
		}
		if(s=="merge")
		{
			char t;
			cin>>t;
			if(a=='A')
			{
				p.merge(q);
				q.clear();
			}
			else
			{
				q.merge(p);
				p.clear();
			}
		}
	}
}
return 0;
}
   
