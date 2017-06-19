#include <cstdio>
char str[1000005];
int one[1000005]={1};
int main()
{
    int k,d=0;
    long long ans=0;
    scanf("%d %s",&k,str);
    for(int i=0;str[i] ;i++)
    {
        d+=str[i]-'0';
        if(d>=k)
            ans+=1ll*one[d-k];
        one[d]++;
    }
    printf("%I64d",ans);
    return 0;
}
