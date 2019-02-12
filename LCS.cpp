#include<bits/stdc++.h>
#define maxn 100000
int a[maxn],b[maxn];
using namespace std;
int LCS(int al,int bl)
{
	if(al<0||bl<0)return 0;
	if(a[al]==b[bl])return LCS(al-1,bl-1)+1;
	else
	{
		return max(LCS(al,bl-1),LCS(al-1,bl));
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}

