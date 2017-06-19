#include <cstdio>
#include <algorithm>
using namespace std;
int g[500*500+5];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n*n; i++)
        scanf("%d",&g[i]);
    sort(g,g+n*n);
    for(int i=n*n-1; i>=n*n-n-1; i--)
        printf("%d ",g[i]);
    return 0;
}
