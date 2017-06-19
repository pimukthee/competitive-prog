#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T,s,n,ans1,ans2,k,me;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        s=ans2=0;
        me = ans1 = -1000000;
        while(n--)
        {
            scanf("%d",&k);
            if(k>0)
                ans2+=k;
            me = max(me,k);
            s = max(s+k,k);
            ans1 = max(ans1,s);
        }
        printf("%d %d\n",ans1,me<0?me:ans2);
    }
    return 0;
}
