#include<bits/stdc++.h>
#define maxn 100000
#define INF 1000000000
int a[maxn],dp[maxn],n;
using namespace std;
int LIS_n2_slow()
{
	int ma=1;
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]<a[i]&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
		ma=max(ma,dp[i]);
	}
	return ma;
}
int LIS_n2_faster()
{
	for(int i=0;i<n;i++)dp[i]=INF;
	int last=0;
	dp[0]=a[0];//ps. dp[0]-> lenth = 1 
	for(int i=1;i<n;i++)
	{
		if(a[i]>dp[last])dp[last++]=a[i];
		else 
		{
			for(int j=last;j>=0;j--)
			{
				if(dp[j]<a[i])
				{
					dp[j+1]=a[i];
				}
				break;
			}
		}
	}
}
int LIS_logN()
{
	for(int i=0;i<n;i++)dp[i]=INF;
	int last=0;
	dp[0]=a[0];//ps. dp[0]-> lenth = 1 
	for(int i=1;i<n;i++)
	{
		if(a[i]>dp[last])dp[++last]=a[i];
		else 
		{
			dp[lower_bound(dp,dp+last+1,a[i])-dp]=a[i];
		}
	}
	return last+1;
}
int main()
{
	int i=0;
	while(cin>>a[i++]);
	n=i;
	cout<<LIS_logN();
	return 0;
}






