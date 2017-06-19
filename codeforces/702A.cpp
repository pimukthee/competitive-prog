#include <cstdio>
#include <algorithm>
int main ()
{
    int n,ans=1,cnt=0,a=0,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&b);
        if(b>a)
        {
            cnt++;
            ans=std::max(ans,cnt);
        }
        else
            cnt=1;
        a=b;
    }
    printf("%d",ans);
    return 0;
}
