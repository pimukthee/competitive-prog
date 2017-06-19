#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
pair <int,int> arr[100005];
int main()
{
    int n,r;
    long long avg,ans=0,mark=0;
    scanf("%d%d%I64d",&n,&r,&avg);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&arr[i].second,&arr[i].first);
        mark+=1ll*arr[i].second;
    }
    avg*=n;
    avg-=mark;
    sort(arr,arr+n);
    for(int i=0; i<n &&avg>0; i++)
    {
       // printf("%d %d\n",arr[i].second,arr[i].first);
        ans+=min(1ll*(r-arr[i].second),avg)*arr[i].first;
        avg-=min(1ll*(r-arr[i].second),avg);
    }
    printf("%I64d",ans);
    return 0;
}
