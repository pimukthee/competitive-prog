#include <cstdio>
#include <algorithm>
using std::max;
int d[100005],h[100005];
int main()
{
    int n,m,ans;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
        scanf("%d%d",&d[i],&h[i]);
    ans=h[0]+d[0]-1;
    for(int i=1; i<m; i++)
    {
        int day = d[i]-d[i-1];
        int diff = h[i]-h[i-1];
        if(day+diff < 0 || diff > day)
        {
            printf("IMPOSSIBLE");
            return 0;
        }
        else
            ans=max(ans,h[i-1]+(day+diff)/2);
    }
    ans=max(ans,h[m-1]+n-d[m-1]);
    printf("%d",ans);
    return 0;
}
