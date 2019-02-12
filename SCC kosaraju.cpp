#include<bits/stdc++.h>
#define pb push_back
#define maxn 10000
using namespace std;
vector<int> edge[maxn],ni[maxn];//graph
vector<int> s;                  //dfs postorder
int e,v;                        //edge,vertex
int visit[maxn];                //   
int scc[maxn];					//scc[i] = i in scc[i]
void dfs(int x)
{
	for(int i:edge[x])
		if(!visit[i])
		{
			visit[i]=1;
			dfs(i);
		}
	s.pb(x);
}
void dfs2(int x,int num)
{
	scc[x]=num;
	for(int i:ni[x])
		if(!visit[i])
		{
			visit[i]=1;
			dfs2(i,num);
		}
}
int kosaraju()
{
	for(int i=0;i<v;i++)
		if(!visit[i])dfs(i);
	memset(visit,0,sizeof(visit));
	int sccnum=1;
	while(s.size())
	{
		if(!visit[s.back()])
		{
			dfs2(s.back(),sccnum++);
		}
		s.pop_back();
	}
	return sccnum-1;
} 
int main()
{
	cin>>e>>v;
	for(int i=0,a,b;i<e;i++)
	{
		cin>>a>>b;
		edge[a].pb(b);
		ni[b].pb(a);
	}
	int numofscc=kosaraju();
	vector<int> topo[maxn];
	for(int i=0;i<v;i++)
	{
		//cout<<i<<' '<<scc[i]<<endl;
		topo[scc[i]].pb(i);
	}
	for(int i=1;i<=numofscc;i++)
	{
		cout<<i<<" : ";
		for(int j:topo[i])cout<<j<<' ';
		cout<<endl;
	}
		
	
	return 0;
}
/*
//test data
//code from 
//https://blog.csdn.net/u011589125/article/details/41593649
//data from
//https://images2015.cnblogs.com/blog/834468/201702/834468-20170224115351695-1062966903.jpg
15
10
9 2
2 7
7 9
2 4
2 1
7 4
1 0
0 1
1 8
8 5
5 6
0 4
4 3
3 4
5 0
*/

