#include <cstdio>
#include <queue>
using namespace std;
struct node
{
        int dist,ro,co;
}temp;
node make(int dis,int row,int col)
{
    node t;
    t.dist = dis;
    t.ro = row;
    t.co = col;
    return t;
}
queue <node> bfs;
int mine[1005][1005],visited[1005][1005],round=1;
bool check(int i,int j)
{
    if(mine[i][j]==round)
        return false;
    return true;
}
int main()
{
    int r,c,row,col,bomb,n,ans,sr,sc,dr,dc;
    while(scanf("%d%d",&r,&c)&&r+c!=0)
    {
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&row,&bomb);
            while(bomb--)
            {
                scanf("%d",&col);
                mine[row][col]++;
            }
        }
        scanf("%d%d%d%d",&sr,&sc,&dr,&dc);
        bfs.push(make(0,sr,sc));
        while(!bfs.empty())
        {
            temp=bfs.front();
            bfs.pop();
            int rr = temp.ro,cc = temp.co,dis = temp.dist;
            if(visited[rr][cc]!=round)
            {
                visited[rr][cc]++;
                if(rr == dr && cc == dc)
                {
                    printf("%d\n",dis);
                    break;
                }
                else
                {
                    if(rr>0 &&check(rr-1,cc))
                        bfs.push(make(dis+1,rr-1,cc));
                    if(rr<r-1&& check(rr+1,cc))
                        bfs.push(make(dis+1,rr+1,cc));
                    if(cc>0&& check(rr,cc-1))
                        bfs.push(make(dis+1,rr,cc-1));
                    if(cc<c-1 &&check(rr,cc+1))
                        bfs.push(make(dis+1,rr,cc+1));
                }
            }
        }
        while(!bfs.empty())bfs.pop();
        round++;
    }
    return 0;
}
