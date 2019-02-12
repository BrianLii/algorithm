#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int gethash(string &s,int l,int r)
{
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        ans=ans*100+s[i];
        ans%=MOD;
    }
    return ans; 
}
int mii(int a,int b)
{
    int sum=1;
    for(int i=0;i<b;i++)sum=sum*a%MOD;
    return sum%MOD;
}
bool find(string &s,string &p)
{
    int ns=gethash(s,0,p.size()-1);
    int np=gethash(p,0,p.size()-1);
    int lp=p.size(),ls=s.size();
    int cache=mii(100,p.size());
    bool flag=0;
    for(int i=0;i+lp-1<ls&&!flag;i++)
    {
        if(np==ns)
        {
            return 1;
        }
        if(i+lp-1<ls&&!flag)
            ns=ns*100-s[i]*cache+s[i+lp];
        ns=(ns%MOD+MOD)%MOD;
    }
    return flag;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    string p,trash;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        getline(cin,trash);
        getline(cin,s);
        cin>>n;
        getline(cin,trash);
        while(n--)
        {
            getline(cin,p);
            cout<<(find(s,p)?'y':'n')<<endl;
        }
    }
    return 0;
}
