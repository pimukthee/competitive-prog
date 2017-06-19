#include <cstdio>
int p[20],m[20];
int main()
{
    int n,k;
    long long ans=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&k);
        if(k<=0)
            m[-k]++;
        else
            p[k]++;
        ans+=1ll*(k<0?p[-k]:m[k]);
    }
    printf("%I64d",ans-1ll*m[0]);
    return 0;
}
