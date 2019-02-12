#include<bits/stdc++.h>
using namespace std;
int nx,ny;
vector<int>edge[1000];
int mx[1000],my[1000];//who matcched with [i]
int vis[1000];
bool dfs(int x)
{
	for(int i:edge[x])
	{
		if(vis[i])continue;
		if(mx[i]==-1||dfs(mx[i]))
		{
			my[i]=x;mx[x]=i;
			return 1; 
		}
	}
	return 0;
}
int matching()
{
	memset(mx,-1,sizeof(mx));
	memset(my,-1,sizeof(my));
	int n;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))cnt++;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}

