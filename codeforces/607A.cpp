#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005];
int main()
{
    int n,m,b;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    while(m--)
    {
        scanf("%d",&b);
        int ans = upper_bound(a,a+n,b)-a;
        printf("%d ",ans);
    }
    return 0;
}
