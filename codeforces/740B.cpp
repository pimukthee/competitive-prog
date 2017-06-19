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
vi mood;
int a[105];
int main()
{
    int n,m,sum=0,l,r;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&l,&r);
        sum = 0;
        for(int j=l; j<=r; j++)
            sum+=a[j];
        mood.pb(sum);
    }
    sort(mood.begin(),mood.end());
    int ans = 0;
    for(int i=m-1; i>=0; i--)
    {
       //printf("%d ",mood[i]);
        ans += max(0,mood[i]);
    }
    printf("%d",ans);
    return 0;
}
