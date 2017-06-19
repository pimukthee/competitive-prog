#include <cstdio>
#include <cmath>
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int sum = i*i+j*j;
            int k  = sqrt(i*i+j*j);
            if(k*k==sum && sum <=n*n)
                ans++;
            else if(k>n)
                break;
        }
    }
    printf("%d",ans);
    return 0;
}
