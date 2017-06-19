#include <cstdio>
#include <algorithm>
using namespace std;
int time[50000+5][10];
int main()
{
    int n,m,k;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<= m; j++)
        {
            scanf("%d",&k);
            time[i][j]=time[i][j-1];
            if(j==1)
                time[i][j]+=time[i-1][j]+k;
            else
                time[i][j]+=max(time[i-1][j]-time[i][j],0)+k;
            //printf("%d ",time[i][j]);
        }
        //printf("\n");
    }
    for(int i=1; i<=n; i++)
        printf("%d ",time[i][m]);
    return 0;
}

