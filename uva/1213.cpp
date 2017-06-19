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
#define MAXN 2005
using namespace std;
vi pr;
int dp[20][MAXN];
bool p[MAXN];
int main()
{
    for(int i=2; i<=MAXN; i++)
    {
        if(!p[i])
        {
            pr.pb(i);
            for(int j=i+i; j<=MAXN; j+=i)
                p[j] = true;
        }
    }
    dp[0][0] = 1ll;
    for(int j: pr)
        for(int m=MAXN-5; m>=j; m-- )
            for(int i=14; i>=1; i--)
                dp[i][m] += dp[i-1][m-j];
    int n,k;
    while(scanf("%d%d",&n,&k)&&n+k>0)
    {
        printf("%d\n",dp[k][n]);
    }
    return 0;
}
