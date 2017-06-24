#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int T,w,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&w,&n);
        vector <int> arr(n+1);
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        sort(arr.begin(),arr.end());
        vector <vector<int> > dp(n+10,vector<int>());
        for(int i=0; i<=n; i++)
            dp[i].assign(w+5,0);
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(j>=arr[i])
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        if(w==0) printf("%d\n",-arr[n]);
        else if(n==0) printf("%d\n",w);
        else  printf("%d\n",w-dp[n-1][w-1]-arr[n]);
    }
    return 0;
}
