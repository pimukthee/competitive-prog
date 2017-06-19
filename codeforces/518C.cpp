#include <cstdio>
#include <algorithm>
int Screen[100005],ValAtIndex[100005],IndexOfVal[100005];
int main()
{
    int n,m,k,sc=1,K,a,b;
    long long ans=0;
    scanf("%d%d%d",&n,&m,&k);
    K=k;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a);
        if(i>K)
            K+=k,sc++;
        Screen[a]=sc;
        ValAtIndex[i]=a;
        IndexOfVal[a]=i;
    }
    while(m--)
    {
        scanf("%d",&b);
        int B = IndexOfVal[b];
        ans+=1ll*Screen[b];
        if(B!=1)
        {
            int &Val = ValAtIndex[B-1];
            IndexOfVal[b]--;
            std::swap(Screen[b],Screen[Val]);
            IndexOfVal[Val]++;
            ValAtIndex[B]=Val;
            Val=b;
        }
    }
    printf("%I64d",ans);
    return 0;
}
