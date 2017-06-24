#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int s = -10000,p=-10000,k;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&k);
            s = max(s+k,k);
            p = max(s,p);
        }
        if(p<=0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",p);
    }
    return 0;
}
