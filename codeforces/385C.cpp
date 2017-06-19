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
#define MAXN 10000000
using namespace std;
int x[MAXN+5];
LL ans[MAXN+5];
bool prime[MAXN+5];
vi p;
int main()
{
    int n,k,l,r,m;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&k);
        x[k]++;
    }
    for(int i=2; i<=MAXN; i++)
    {
        if(!prime[i])
        {
            p.pb(i);
            ans[i] += 1ll*x[i];
            for(int j=i+i; j<=MAXN; j+=i)
            {
                prime[j] = true;
                ans[i]+= 1ll*x[j];
            }

        }
    }
    for(int i=2; i<=MAXN; i++)
        ans[i]+=ans[i-1];
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&l,&r);
        //printf("%I64d\n",ans[5]);
        cout << ans[min(r,MAXN)]-ans[min(l,MAXN)-1] << endl;
    }
    return 0;
}
