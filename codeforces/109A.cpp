#include <cstdio>
int main()
{
    int n,k,four=1,seven=-1,m=1000000000;
    scanf("%d",&n);
    for(int i=0; i<=n/4; i++)
    {
        k = n-4*i;
        if(k%7==0 && k/7+i <= m)
        {
            four=i;
            seven=k/7;
            m=four+seven;
        }
    }
    if(four==-1 || seven == -1)
        printf("-1");
    else
    {
        while(four--) printf("4");
        while(seven--) printf("7");
    }
    return 0;
}
