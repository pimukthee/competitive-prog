#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,fs=10000000005,fe=1000000005,mf=1000000005,me=-1,ans,s,e;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&s,&e);
        if(s<fs)
        {
            fs=s;
            fe=e;
            ans=i;
        }
        else if(s==fs)
        {
            if(fe < e)
            {
                fe = e;
                ans=i;
            }
        }
        mf=min(mf,s);
        me=max(e,me);
    }
    if(fs<=mf && fe>= me)
        printf("%d",ans);
    else
        printf("-1");
    return 0;
}
