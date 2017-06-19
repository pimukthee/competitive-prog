#include <cstdio>
int arr[505],m[1005],chk[505];
int main()
{
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&m[i]);
        chk[m[i]]=i;
        for(int j=i-1; j>=1 && m[j]!=m[i]; j--)
        {
            if(chk[m[j]]!=i)
                ans+=arr[m[j]];
            chk[m[j]]=i;
        }
    }
    printf("%d",ans);
    return 0;
}
