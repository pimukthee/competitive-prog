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
vi dp(6005);
pi a[1005];
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%d%d",&a[i].F,&a[i].S);
        dp.assign(6005,0);
        for(int i=n-1; i>=0; i--)
        {
            for(int j = a[i].S; j>=0; j--)
                if(dp[j])
                    dp[j+a[i].F] = max(dp[j+a[i].F],dp[j]+1);
            if(dp[a[i].F]==0)
                dp[a[i].F]=1;
        }
        printf("%d\n",*max_element(dp.begin(),dp.end()));
    }
    return 0;
}
