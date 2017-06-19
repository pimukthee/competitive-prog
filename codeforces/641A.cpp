#include <cstdio>
int jump[100005];
bool mem[100005];
char dir[100005];
int main()
{
    int n,cur=0;
    scanf("%d %s",&n,dir);
    for(int i=0; i<n; i++)
        scanf("%d",&jump[i]);
    while(cur >=0 && cur <n && !mem[cur])
    {
        mem[cur]=true;
      //  printf("%c",dir[cur]);
        if(dir[cur]=='>')
            cur+=jump[cur];
        else
            cur-=jump[cur];
    }
    //printf("%d",cur);
    if(cur < 0 || cur >= n)
        printf("FINITE");
    else
        printf("INFINITE");
    return 0;
}
