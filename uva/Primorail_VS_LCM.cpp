#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define sqr(x) x*x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int,int>
using namespace std;
vector < pair<LL,LL> > p;
const LL MAXN= 1e7+5;
const LL mod = 1e9+7;
const LL MAX = 1e14+5;
bool prime[MAXN];
vector <LL> ans;

int main()
{
    p.pb(mp(1,1));
    for(LL i=2; i<=MAXN; i++)
    {
        if(!prime[i])
        {
            for(double j=(double)i*i; j<=MAX; j*=i)
                p.pb(mp(j,i));
            for(LL j=i+i; j<=MAXN; j+=i)
                prime[j]=true;
        }
    }
    sort(p.begin(),p.end());
   // for(int i=1; i<=10; i++)
   //     cout << p[i].first << " ";
    ans.pb(1);
    for(int i=1; i<p.size(); i++)
        ans.pb((ans.back()*p[i].second)%mod);
    int T;
    scanf("%d",&T);
    LL n;
    for(int c =1; c<=T; c++)
    {
        scanf("%lld",&n);
        int l=0,r = p.size()-1;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(p[mid].first > n)
                r = mid-1;
            else
                l = mid;
        }
        printf("Case %d: %lld\n",c,ans[l]);
    }
    return 0;
}

