#include <cstdio>
int main()
{
    int n,sum=0,k;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&k);
        sum+=k;
    }
    if(sum%n==0)
        printf("%d",n);
    else
        printf("%d",n-1);
    return 0;
}
