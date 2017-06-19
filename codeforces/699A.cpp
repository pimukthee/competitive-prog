#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
pair <int,char> col[200005];
int n,right=-1,left=-1,ans=1000000000;
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf(" %c",&col[i].second);
    for(int i=0; i<n; i++)
        scanf("%d",&col[i].first);
    sort(col,col+n);
    for(int i=0; i<n; i++)
    {
        if(col[i].second=='R')
            right = col[i].first;
        else if(col[i].second=='L'&&right!=-1)
            ans=min(ans,(col[i].first-right)/2);
    }
    for(int i=n-1; i>=0; i--)
    {
        if(col[i].second=='L')
            left = col[i].first;
        else if(col[i].second=='L'&&left!=-1)
            ans=min(ans,(left-col[i].first)/2);
    }
    if(ans==1000000000)
        ans=-1;
    printf("%d",ans);
    return 0;
}
