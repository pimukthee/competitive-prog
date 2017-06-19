#include <cstdio>
bool index[3005];
int main()
{
    int n,a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        index[a]=true;
    }
    for( a=1;index[a] ;a++);
    printf("%d",a);
    return 0;
}
