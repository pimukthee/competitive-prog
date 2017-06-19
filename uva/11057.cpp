#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[100005];
int main()
{
    int n,m,c=0,diff,f,s;
    while(scanf("%d",&n)>0)
    {
        diff=1000000000;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        scanf("%d",&m);
        for(int i=0; i<n; i++)
        {
            if(binary_search(a+i,a+n,m-a[i])&&abs(m-2*a[i])<diff)
            {
                diff = abs(m-2*a[i]);
                f = a[i];
                s = m- a[i];
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",f,s);
    }
    return 0;
}
