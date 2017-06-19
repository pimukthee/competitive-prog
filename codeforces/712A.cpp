#include <cstdio>
int main()
{
    int n,a,b;
    scanf("%d%d",&n,&a);
    for(int i=1; i<n; i++)
    {
        scanf("%d",&b);
        printf("%d ",b+a);
        a=b;
    }
    printf("%d",b);
    return 0;
}
