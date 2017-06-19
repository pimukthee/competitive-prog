#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pi pair<int,int>
using namespace std;
long long a[100005],n,k;
int bsearch(int i)
{
    int l=1,r=i,mid,ans=i;
    while(l<=r)
    {
        mid=(l+r)/2;
        //printf("%I64d %d\n",(a[i]-a[i-1])*(1ll*i-1ll*mid+1ll) - (a[i]-a[mid-1]),k);
        if((a[i]-a[i-1])*(1ll*i-1ll*mid+1ll) - (a[i]-a[mid-1]) <= k)
        {
           // printf("%d ",mid);
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return i-ans+1;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%I64d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++)
        a[i]+=a[i-1];
    pi ans=mp(0,0);
   // printf("\n%d ",bsearch(4));
    for(int i=1; i<=n; i++)
    {
        int temp = bsearch(i);
        //if(i==4) printf("%d\n",temp);
        if(temp>ans.F)
        {
            ans.F = temp;
            ans.S = a[i]-a[i-1];
        }
    }
    printf("%d %d",ans.F,ans.S);
    return 0;
}
/*5 3
6 3 4 0 2*/
