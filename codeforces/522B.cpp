#include <cstdio>
#include <algorithm>
using namespace std;
int w[200005],h[200005],left[200005],right[200005];
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&w[i],&h[i]);
        sum+=w[i];
        left[i]=max(left[i-1],h[i]);
    }
    for(int i=n; i>=0; i--)
        right[i]=max(right[i+1],h[i]);
    for(int i=1; i<=n; i++)
        printf("%I64d ",1ll*(sum-w[i])*max(left[i-1],right[i+1]));
    return 0;
}
