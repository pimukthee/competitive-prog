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
int a[100005],d[100005],dp[100005],fac[100005];
int main()
{
    for(int i=2; i<=100000; i++)
    {
        if(fac[i]==0)
        {
            for(int j=i; j<=100000; j+=i)
                fac[j] = i;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i =0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++)
    {
        for(int x=a[i]; x>1; x/=fac[x])
            dp[a[i]] = max(dp[a[i]],d[fac[x]] +1);
        for(int x=a[i]; x>1; x/=fac[x])
            d[fac[x]] = dp[a[i]];
    }
    printf("%d",max(1,*max_element(d+1,d+100001)));
    return 0;
}
