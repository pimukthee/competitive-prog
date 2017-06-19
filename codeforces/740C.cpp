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
int main()
{
    int n,m,l,r,ans=1000000000;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&l,&r);
        ans = min(ans,r-l+1);
    }
    printf("%d\n",ans);
    for(int i=0; i<n; i++)
        printf("%d ",i%ans);
    return 0;
}
