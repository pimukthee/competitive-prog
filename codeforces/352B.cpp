#include <cstdio>
#include <vector>
using namespace std;
vector <int> d[100005];
vector <pair<int,int> > ans;
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        d[a].push_back(i);
    }
    for(int i=1; i<=100000; i++)
    {
        int s = d[i].size();
        if(s == 1)
            ans.push_back(make_pair(i,0));
        else if(!d[i].empty())
        {
            int diff = d[i][1]-d[i][0];
            for(int j=2; j<s; j++)
                if(diff != d[i][j]-d[i][j-1])
                    diff=-1;
            if(diff!=-1)
                ans.push_back(make_pair(i,diff));
        }
    }
    int s = ans.size();
    printf("%d\n",s);
    for(int i=0; i<s; i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
