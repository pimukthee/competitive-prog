#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
map <int,int> pos;
int main()
{
    int T,d,n,ans,left;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=left=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&d);
            if(pos[d]!=0)
                left = max(left,pos[d]);
            ans = max(ans,i-left);
            pos[d]=i;
        }
        printf("%d\n",ans);
        pos.clear();
    }
    return 0;
}
