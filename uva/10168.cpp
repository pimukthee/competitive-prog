#include <cstdio>
bool prime[10000010];
int main()
{
    for(int i=2; i<=10000000; i++)
    {
        if(!prime[i])
            for(int j=i+i; j<=10000000; j+=i)
                prime[j]=true;
    }
    int n;
    while(scanf("%d",&n)>0)
    {
        if(n<8)
            printf("Impossible.\n");
        else
        {

            if(n&1)
                printf("2 3 ");
            else
                printf("2 2 ");
            n-=4+(n&1);
            for(int i=2; i<=n; i++)
            {
                if(!prime[i]&&!prime[n-i])
                {
                    printf("%d %d\n",i,n-i);
                    break;
                }
            }
        }
    }
    return 0;
}
