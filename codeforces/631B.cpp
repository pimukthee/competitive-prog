#include <cstdio>
#include <utility>
using namespace std;
pair <int,int> row[5005],col[5005];
int main()
{
    int n,m,k,com,rc,a;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=k; i++)
    {
        scanf("%d%d%d",&com,&rc,&a);
        if(com==1)
        {
            row[rc].first=i;
            row[rc].second=a;
        }
        else
        {
            col[rc].first=i;
            col[rc].second=a;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int r = row[i].first;
            int c = col[j].first;
            if(r==0&&c==0)
                printf("0 ");
            else if(r>c)
                printf("%d ",row[i].second);
            else
                printf("%d ",col[j].second);
        }
        printf("\n");
    }
    return 0;
}
