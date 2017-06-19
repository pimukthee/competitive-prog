#include <cstdio>
#include <utility>
using namespace std;
pair <int,int> head[1000005];
int ans[200005];
int main()
{
    int n,i,a,b,cur;
    scanf("%d",&n);
    for(i=0; i<=1000000; i++)
        head[i].second=head[i].first=i;
    for(i = 0;i <n; i++)
    {
        scanf("%d%d",&a,&b);
        head[b].first=a;
        head[a].second = b;
    }
    cur = 0;
    for(i=1;;i++)
        if(head[i].first==i&&head[i].second!=i)
            break;
    while(cur < n)
    {
        ans[cur]=i;
        if(i==head[i].second)
            break;
        i = head[i].second;
        cur+=2;
    }
    cur=1;
    i=head[0].second;
    while(cur < n)
    {
        ans[cur]=i;
        i=head[i].second;
        cur+=2;
    }
    ans[cur]=i;
    for(int i=0; i<n; i++)
        printf("%d ",ans[i]);
    return 0;
}
