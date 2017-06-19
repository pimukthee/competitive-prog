#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
vector <int> dp(10000);
pair <int,int> arr[6000];
int main()
{
    int n=0,ans=0;
    while(scanf("%d%d",&arr[n].second,&arr[n].first)>0)
        n++;
   // printf("=>%d\n",n);
    sort(arr,arr+n);
  //  for(int i=0; i<n;i ++)
   //     printf("%d %d\n",arr[i].second,arr[i].first);
    dp.assign(n,1000000000);
    dp[0]=0;
    for(int i=0; i<n; i++)
    {
        for(int j=ans; j>=0; j--)
        {
            if(arr[i].first>=arr[i].second+dp[j] && arr[i].second+dp[j]<dp[j+1])
            {
                dp[j+1] = dp[j]+arr[i].second;
                ans= max(ans,j+1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
