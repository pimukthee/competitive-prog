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
int a[100005];
vi isCal;
LL sum,ans,dp[50];
int countBit(int k)
{
    int sum = 0;
    while(k>0)
    {
       sum+=(k&1);
       k>>=1;
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++)
        dp[countBit(a[i])]++;
    for(int i=0; i<=30; i++)
        ans += dp[i]*(dp[i]-1)/2;
    printf("%I64d",ans);
    return 0;
}
