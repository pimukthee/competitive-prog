#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int ans[20][20];
int main()
{
    int T,n,a;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                ans[i][j]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                scanf("%d",&a);
                ans[i][j]=max(ans[i-1][j],ans[i-1][j-1])+a;
            }
        }
        printf("%d\n",*max_element(ans[n],ans[n]+n+1));
    }
    return 0;
}
