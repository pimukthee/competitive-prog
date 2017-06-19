#include <cstdio>
#include <algorithm>
using namespace std;
int day[3005];
int main()
{
    int n,v,ans=0,a,b;
    scanf("%d%d",&n,&v);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&a,&b);
        day[a]+=b;
    }
    for(int i=1; i<=3005; i++)
    {
        int k = min(day[i],v);
        ans+=k;
		day[i]-=k;
		day[i+1]+=min(day[i],v);
    }
    printf("%d",ans);
    return 0;
}
