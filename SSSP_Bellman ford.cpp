#include<bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef pair<int,int> pii;
vector<pii> edge[maxn];//edge[from]{ to,val }
int d[maxn];
bool inque[maxn];
void SPFA(int s)
{
	queue<int> que;
	que.push(s);
	inque[s]=1;
	while(!que.empty())
	{
		int p=que.front();
		que.pop();
		inque[p]=0;
		for(auto i:edge[p])
		{
			if(d[i.first]>d[p]+i.second)
			{
				d[i.first]=d[p]+i.second;
				if(!inque[i.first])
				{
					que.push(i.first);
					inque[i.first]=1;
				}
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

