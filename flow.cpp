#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
typedef pair<int,int> pii;
vector<int> edge[10000];
vector<pii> E;
void make_edge(int a,int b,int w)
{
	edge[a].push_back(E.size());
	E.push_back(pii(b,w));
	edge[b].push_back(E.size());
	E.push_back(pii(a,0)); 
}
int lv[10000],le[10000],vis[10000];
int bfs(int s,int t)
{
	queue<int> q;
	q.push(s);
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	int mi=INF;
	bool flag=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(flag|=(now==t))break;	
		for(int i:edge[now])
		{
			if(!vis[E[i].first]&&E[i].second>0)
			{
				vis[E[i].first]=1;
				lv[E[i].first]=now;
				le[E[i].first]=i;
				mi=min(mi,E[i].second);
				q.push(E[i].first);
			}
		}
	}
	if(!flag)return 0;
	int now=t;
	while(now!=s)
	{
		E[le[now]].second-=mi;
		E[le[now]^1].second+=mi;
		now=lv[now];
	}
	return mi;
}
int ek(int s,int t)
{
	int flow=0;
	int tmp;
	while(tmp=bfs(s,t))flow+=tmp;
	return flow;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int cnt=0;
	while(cin>>n)
	{
		if(!n)
		{
			return 0;
		}
		int s,t,c;
		cin>>s>>t>>c;
		E.clear();
		for(int i=0;i<=n;i++)
		{
			edge[i].clear();
		}
		while(c--)
		{
			int a,b,w;
			cin>>a>>b>>w;
			make_edge(a,b,w);
			make_edge(b,a,w);
		}
		cout<<"Network "<<++cnt<<endl;
		cout<<"The bandwidth is ";
		cout<<ek(s,t)<<'.'<<endl<<endl;
	}
	return 0;
}

