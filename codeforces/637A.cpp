#include <cstdio>
int ans[1000010];
int main()
{
    int n,a,winner,m=-1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        ans[a]++;
        if(ans[a]>m)
        {
            m = ans[a];
            winner = a;
        }
    }
    printf("%d",winner);
    return 0;
}
