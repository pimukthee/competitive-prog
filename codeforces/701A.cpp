#include <cstdio>
#include <queue>
using namespace std;
queue <int> q[105];
int a[105];
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        q[a[i]].push(i);
        sum+=a[i];
    }
    sum/=n/2;
    for(int i=1; i<=n; i++)
    {
        if(!q[a[i]].empty())
        {
            printf("%d ",q[a[i]].front());
            q[a[i]].pop();
            printf("%d\n",q[sum-a[i]].front());
            q[sum-a[i]].pop();
        }
    }
    return 0;
}
