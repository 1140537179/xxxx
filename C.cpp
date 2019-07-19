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
#define ll long long
#define N 2005
struct cnm
{
	int next;
}p[N];
int main()
{
	ll n,m;
	while(cin>>n>>m)
	{
		ll biaoji;
		ll o=sqrt(2*m);
		if(o*(o+1)==2*m)
		biaoji=o;
		if(o*(o+1)>2*m)
		biaoji=o;
		if(o*(o+1)<2*m)
		biaoji=o+1;
		if(m<=3)
		{
			if(2*m>n)
	         cout<<0<<" "<<n-m-1<<endl;
	         else if(m==0)
	         cout<<n<<" "<<n<<endl;
	     else
		 cout<<n-2*m<<" "<<n-m-1<<endl;
		}
		else
		{
	     if(2*m>n)
	     cout<<0<<" "<<n-biaoji-1<<endl;
	     else
		 cout<<n-2*m<<" "<<n-biaoji-1<<endl;
	    }
	}
	return 0;
} 
