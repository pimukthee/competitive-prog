#include <cstdio>
char str[1000000+10];
int main()
{
    int n,sum;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        scanf(" %s",str);
        for(int i=0; str[i]; i++)
            sum+=str[i]-'0';
        if(sum%9==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
