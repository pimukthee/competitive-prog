#include <cstdio>
#include <algorithm>
struct card
{
    int a,b;
    bool operator <(const card &aa) const
    {
        if(aa.b!=b) return b > aa.b;
        return a > aa.a;
    }
}arr[1005];
int main()
{
    int n,en=1,ans=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d",&arr[i].a,&arr[i].b);
    std::sort(arr,arr+n);
    for(int i=0; i<n && en; i++)
    {
        ans+=arr[i].a;
        en+=arr[i].b-1;
    }
    printf("%d",ans);
    return 0;
}
