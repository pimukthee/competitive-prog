#include <cstdio>
int main()
{
    int n,digit=1;
    long long ans=0;
    scanf("%d",&n);
    for(int i=10; i<=999999999; i ++)
    {
        int k = i,temp=0;
        while(k)
        {
            int kk = k%10;
            for(int j=1; j<n; j++)
                kk*=(k%10);
            temp += kk;
            k/=10;
        }

        if(temp == i)
            ans+=temp;
    }
    printf("%lld",ans);
    return 0;
}
