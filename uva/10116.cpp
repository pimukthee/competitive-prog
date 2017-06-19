#include <cstdio>
#include <cstring>
char grid[20][20];
int step[20][20];
void checkdir(int &row,int &col)
{
    if(grid[row][col]=='S')
        row++;
    else if(grid[row][col]=='E')
        col++;
    else if(grid[row][col]=='W')
        col--;
    else
        row--;
}
int main()
{
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)&&n+m+k>0)
	{
		for(int i=1; i<=n; i++)
			scanf("%s",grid[i]+1);
        memset(step,-1,sizeof step);
        int row=1,col=k,cur=0;
        step[row][col]=0;
        while(1)
        {
            checkdir(row,col);
            cur++;
            if(step[row][col]!=-1)
            {
                printf("%d step(s) before a loop of %d step(s)\n",step[row][col],cur-step[row][col]);
                break;
            }
            if(row==0 || row ==n+1 || col==0 || col==m+1)
            {
                printf("%d step(s) to exit\n",cur);
                break;
            }
            step[row][col]=cur;
        }
	}
	return 0;
}
