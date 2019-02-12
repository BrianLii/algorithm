#include<bits/stdc++.h>
using namespace std;
int a[100];
int low(int l,int r,int k)
{
	//[l,r)
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]<k)l=mid+1;
		else r=mid;
	}
	return r;
}
int up(int l,int r,int k)
{
	//[l,r)
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]<=k)l=mid+1;
		else r=mid;
	}
	return r;
}
int main()
{
	return 0;
}

