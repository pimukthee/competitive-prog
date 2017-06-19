#include <cstdio>
#include <list>
using namespace std;
list <int> ans;
int cnt[5005];
int main()
{
    int n,k;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        cnt[k]++;
    }
    for(int i=5000; i>=1; i--)
    {
        if(ans.empty() && cnt[i]>0)
            ans.push_back(i);
        else if(cnt[i]>=1)
        {
            ans.push_back(i);
            if(cnt[i]>=2)
                ans.push_front(i);
        }
    }
    printf("%d\n",ans.size());
    for(list <int> ::iterator it=ans.begin(); it!=ans.end(); it++)
        printf("%d ",*it);
    return 0;
}
