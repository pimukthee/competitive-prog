#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <pair<int,int>,int> arr[100005];
bool sto[100005];
int main()
{
    int n,m,k,u,v,d;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&u,&v,&d);
        arr[i].first.first = u;
        arr[i].first.second = v;
        arr[i].second = d;
    }
    int ans=1000000005;
    while(k--)
    {
        scanf("%d",&u);
        sto[u]=true;
    }
    for(int i=0; i<m; i++)
        if(sto[arr[i].first.first]^sto[arr[i].first.second])
            ans = min(ans,arr[i].second);
    printf("%d",ans==1000000005?-1:ans);
    return 0;
}
