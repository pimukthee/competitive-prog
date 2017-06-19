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
LL mod = 1e9+7;
int main()
{
    int n;
    LL k,ans=1,pro=1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%I64d",&k);
        pro = (pro*k)%mod;
    }
    int i;
    for(i=1; i*i<pro; i++)
    {
        if(pro%i==0)
        {
            ans = (ans*i)%mod;
            ans = (ans*(pro/i))%mod;
        }
    }
    if(i*i==k)
        ans=(ans*i)%mod;
    printf("%I64d",ans);
    return 0;
}
