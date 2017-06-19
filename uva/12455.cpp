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
bool dp[1005];
int main()
{
    int T,n,a,l;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&n);
        for(int i=0; i<=l; i++)
            dp[i] = false;
        dp[0] = true;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a);
            for(int j=l; j>=a; j--)
                dp[j] |= dp[j-a];
        }
        printf("%s\n",dp[l]?"YES":"NO");
    }
    return 0;
}
