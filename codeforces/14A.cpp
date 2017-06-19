#include <cstdio>
#include <algorithm>
using namespace std;
char table[100][100];
int main()
{
    int n,m,top=-1,bot,left=100,right=-1;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf(" %c",&table[i][j]);
            if(table[i][j]=='*')
            {
                if(top==-1)
                    top = bot = i;
                else
                    bot = i;
                left = min(left,j);
                right = max(right,j);
            }
        }
    }
    for(int i = top; i<=bot; i++)
    {
        for(int j=left; j<=right; j++)
            printf("%c",table[i][j]);
        printf("\n");
    }
    return 0;
}
