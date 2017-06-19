#include <cstdio>
#include <algorithm>
int main()
{
    int ans[]={1,2},n,a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        printf("%d\n",ans[a&1]);
        if(ans[a&1]==1)
        {
            ans[0]=2;
            ans[1]=1;
        }
        else
        {
            ans[0]=1;
            ans[1]=2;
        }
    }
    return 0;
}
