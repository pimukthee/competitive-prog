#include <iostream>
#include <string>
using namespace std;
int dp[1005][1005];
int main()
{
    string a,b;
    while(getline(cin,a))
    {
        getline(cin,b);
        int sa = a.length(),sb = b.length();
        for(int i=1; i<=sa; i++)
        {
            for(int j=1; j<=sb; j++)
            {
                dp[i][j]=0;
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[sa][sb] <<endl;
    }
    return 0;
}
