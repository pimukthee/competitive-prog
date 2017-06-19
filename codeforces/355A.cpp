#include <cstdio>
int main()
{
    int k,d;
    scanf("%d%d",&k,&d);
    if(d==0 && k!=1) printf("No solution");
    else
    {
        printf("%d",d);
        while(--k)
            printf("0");
    }
    return 0;
}
