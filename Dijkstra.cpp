#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
typedef pair<int,int> pii;
vector<pii> edge[maxn];//{to,weight] 
int dis[maxn];
int vis[maxn];
priority_queue<pii,vector<pii>,less<pii> > pq;
int n=maxn-5;
int dijkstra(int s,int t)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	pq.push(pii(s,0));
	for(int i=0;i<n;i++)
	{
		int pre=-1;
		while(!pq.empty()&&vis[pre=pq.top().first])pq.pop();
		if(pre==-1)break;
		vis[pre]=1;
		for(auto to:edge[pre])
		{
			int v=to.first,w=to.second;
			if(!vis[v]&&dis[v]>dis[pre]+w)
			{
				dis[v]=dis[pre]+w;
				pq.push(pii(v,dis[v]));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}

