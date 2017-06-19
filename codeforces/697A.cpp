#include <cstdio>
int main()
{
    int t,s,x;
    scanf("%d%d%d",&t,&s,&x);
    if(((x-t)%s==0 || ((x-t-1)%s==0&&(x!=t+1)))&& x>=t)
        printf("YES");
    else
        printf("NO");
    return 0;
}
