#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%.0lf",ceil((1.0*n+1.0)/(k*1.0))*1.0*k);
    return 0;
}
