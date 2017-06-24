#include <iostream>
using namespace std;
long long dp[500]={1};
int main()
{
    int n,k,c;
    cin >> n >> c;
    for(int i=0; i<c; i++)
    {
        cin >> k;
        for(int j=k; j<=n; j++)
            dp[j]+=dp[j-k];
    }
    cout << dp[n];
    return 0;
}
