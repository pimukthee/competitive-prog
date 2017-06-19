#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double dis[205][205];
int x[205],y[205];
void reset()
{
    for(int i=0; i<=200; i++)
        for(int j=0; j<=200; j++)
            dis[i][j]=1000000000;
}
int main()
{
    int n,c=1;
    while(scanf("%d",&n)&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%d%d",&x[i],&y[i]);
        reset();
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                dis[i][j]=dis[j][i]=sqrt(pow(1.0*(x[i]-x[j]),2.0)+pow(1.0*(y[i]-y[j]),2.0));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    dis[j][k] = min(dis[j][k],max(dis[j][i],dis[i][k]));
       // printf("%.3lf",dis[6][1]);
        //if(c!=1) printf("\n");
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",c++,dis[1][0]);
    }
    return 0;
}
