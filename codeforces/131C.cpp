#include <iostream>
using namespace std;
int c[35][35];
int main()
{
    c[0][0]=1;
    for(int i=1; i<=35; i++)
    {
        c[i][0]=1;
        for(int j=1; j<=i; j++)
           c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    int n,m,t;
    long long ans = 0;
    cin >> n >> m >> t;
    for(int i=4; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(i+j==t)
                ans+=1ll*c[n][i]*c[m][j];
    cout << ans;
    return 0;
}
