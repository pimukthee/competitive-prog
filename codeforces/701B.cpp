#include <cstdio>
bool col[100005],row[100005];
int main()
{
    int n,m,r,c,hor=0,ver=0;
    scanf("%d%d",&n,&m);
    long long ans = 1ll*n*n;
    while(m--)
    {
        scanf("%d%d",&r,&c);
        if(!col[c])
        {
            ans-=n-hor;
            ver++;
        }
        if(!row[r])
        {
            ans-=n-ver;
            hor++;
        }
        col[c]=row[r]=true;
        printf("%I64d\n",ans);
    }
    return 0;
}
