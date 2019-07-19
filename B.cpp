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
#define N 2005
struct cnm
{
	int next;
}p[N];
int main()
{
	int n;
	while(cin>>n)
	{
		int d;
		for(int i=1;i<=n;i++)
		{
			cin>>d;
			p[i].next=d;
		}
		    int maxx=1;
			for(int i=1;i<=n;i++)
		   {
			    if(p[i].next!=-1)
			    {
			    	int biaoji=1;
			    	int o=i;
			    	while(p[o].next!=-1)
			    	{
			    		o=p[o].next;
			    		biaoji++;
					}
					maxx=max(biaoji,maxx);
				}
	       }
	       cout<<maxx<<endl;
		
	}
	return 0;
} 

