#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector <int> a;
bool chk[10005];
int main()
{
    int n,m,d,ans=0,k;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m ;j++)
        {
            scanf("%d",&k);
            a.push_back(k);
            if( !chk[k%d] && (i!=0 || j!=0))
                ans=-1;
            chk[k%d]=true;
        }
    }
    if(ans!=-1)
    {
        sort(a.begin(),a.end());
        int s = a.size();
        for(int i=0; i<s; i++)
            ans+=abs(a[s/2]-a[i])/d;
    }
    printf("%d",ans);
    return 0;
}
