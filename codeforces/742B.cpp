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
LL cnt[1000005];
int main()
{
    int n,x,k;
    LL ans = 0;
    scanf("%d%d",&n,&x);
    while(n--)
    {
        scanf("%d",&k);
        ans+=cnt[x^k];
        cnt[k]++;
    }
    printf("%I64d",ans);
    return 0;
}
