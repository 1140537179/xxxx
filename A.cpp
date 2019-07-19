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
#define N 1050
int pre[N];
int mid[N];
int biaoji;
struct node
{
	int val;
	node* left;
	node* right;
	node(int val):val(val),left(NULL),right(NULL) {}
};
struct tree
{
	node* root;
};
node* build(int prel,int prer,int midl,int midr)
{
	if(prel>prer)
	return NULL;
	node* root=new node(pre[prel]);
	for(int i=midl;i<=midr;i++)
	{
		if(mid[i]==pre[prel])
		{
			int leng=i-midl;
			root->left=build(prel+1,leng+prel,midl,i-1);
			root->right=build(prel+leng+1,prer,i+1,midr);
			break;
		}
	}
	return root;
}
void last(node* root)
{
	if(root==NULL)
	return;
	last(root->left);
	last(root->right);
	if(biaoji==0)
	{
	cout<<root->val;
	biaoji=1;
    }
    else
    {
    	cout<<" "<<root->val;
	}
	
}
int main()
{
	int m;
	while(cin>>m)
	{
		biaoji=0;
		for(int i=0;i<m;i++)
		{
			cin>>pre[i];
		}
		for(int i=0;i<m;i++)
		{
			cin>>mid[i];
		}
		tree a;
	a.root=build(0,m-1,0,m-1);
	last(a.root);
	cout<<endl;
	}
	return 0;
	
}

