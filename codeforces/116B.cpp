#include <cstdio>
char arr[20][20];
int cnt[20][20],row,col;
void inc(int i,int j)
{
    if(arr[i][j]=='P')
        cnt[i][j]++;
}
void findmin(int i,int j)
{
    int minwolf;
    if(arr[i-1][j]=='P')
    {
        row=i-1;
        col=j;
        minwolf = cnt[i-1][j];
    }
    if(arr[i+1][j]=='P'&&cnt[i+1][j]<minwolf)
    {
        row=i+1;
        col=j;
        minwolf = cnt[i+1][j];
    }
    if(arr[i][j-1]=='P'&&cnt[i][j-1]<minwolf)
    {
        row=i;
        col=j-1;
        minwolf = cnt[i][j-1];
    }
    if(arr[i][j+1]=='P'&&cnt[i][j+1]<minwolf)
    {
        row=i;
        col=j+1;
    }
}
int main()
{
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf(" %c",&arr[i][j]);
            if(arr[i][j]=='W')
            {
                inc(i-1,j);
                inc(i+1,j);
                inc(i,j-1);
                inc(i,j+1);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j]=='W')
            {
                row=col=-1;
                findmin(i,j);
                if(row+col!=-2)
                {
                    ans++;
                    cnt[row][col]=0;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
