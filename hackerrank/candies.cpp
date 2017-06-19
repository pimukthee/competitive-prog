#include <cstdio>
#include <algorithm>
using namespace std;
int arr[5][100005];
int main()
{
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[0][i]);
    for(int i=1; i<=n; i++)
    {
        arr[1][i]=1;
        if(arr[0][i]>arr[0][i-1])
           arr[1][i]+=arr[1][i-1];
    }
    for(int i=n; i>=1; i--)
    {
        arr[2][i]=1;
        if(arr[0][i]>arr[0][i+1])
            arr[2][i]+=arr[2][i+1];
    }
    for(int i=1; i<=n; i++)
        ans+=max(1ll*arr[1][i],1ll*arr[2][i]);
    printf("%lld",ans);
    return 0;
}
