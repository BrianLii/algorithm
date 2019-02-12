#include<bits/stdc++.h>
#define maxn 100000
using namespace std;
///kousaraju
vector<int> edge[maxn],ni[maxn];
vector<int> topo;
int scc[maxn];
int vis[maxn];
int n;
void dfs(int x)
{
	vis[x]=1;
	for(int i:edge[x])
		if(!vis[i])
			dfs(i);
	topo.push_back(x);
}
void dfs2(int x,int num)
{
	scc[x]=num;
	vis[x]=1;
	for(int i:ni[x])
		if(!vis[i])
			dfs2(i,num);
} 
int kousaraju()
{
	for(int i=0;i<=n;i++)
		if(!vis[i])
			dfs(i);
	auto now=topo.end();
	int sccnum=0;
	while(--now!=topo.begin())
	{
		dfs2((*now),++sccnum);
	}
	return sccnum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}

