#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[105];
int main()
{
    int n;
    double ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    std::sort(arr+1,arr+n+1);
    for(int i=n; i>0; i-=2)
        ans+=4.0*atan(1.0)*(1.0*arr[i]*arr[i]-1.0*arr[i-1]*arr[i-1]);
    printf("%.9lf",ans);
    return 0;
}
