#include <cstdio>
int main()
{
    int a,b,c,aa,bb,cc;
    scanf("%d%d%d",&a,&b,&c);
    aa = a+b-c;
    bb = b+c-a;
    cc = a+c-b;
    if(aa < 0 || bb < 0 || cc < 0 || aa&1 || bb&1 || cc&1)
        printf("Impossible");
    else
        printf("%d %d %d",aa/2,bb/2,cc/2);
    return 0;
}
