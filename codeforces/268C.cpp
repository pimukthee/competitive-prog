#include <cstdio>
#include <algorithm>
using std::min;
int main()
{
    int n,m,r;
    scanf("%d%d",&n,&m);
    r= min(n,m)+1;
    printf("%d\n",r);
    for(int i=0; i<r; i++)
        printf("%d %d\n",r-1-i,i);
    //printf("%d 0",r-1);
    return 0;
}
