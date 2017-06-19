#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100005];
int main()
{
    int n,k,ans;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    ans=arr[n-1];
    for(int i=0; i<n-k; i++)
        ans=max(ans,arr[2*n-2*k-i-1]+arr[i]);
    printf("%d",ans);
    return 0;
}
