#include <iostream>
#include <cstring>
using namespace std;
float cup[15][15];
int main()
{
    int n,t,ans;
    cin >> n >> t;
    cup[1][1]=t-1;
    ans = cup[1][1]>=0?1:0;

    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cup[i][j]=-1;
            if(cup[i-1][j-1]>=0) cup[i][j]+=cup[i-1][j-1]/2;
            if(cup[i-1][j]>=0)  cup[i][j]+=cup[i-1][j]/2;
            if(cup[i][j]>=0)  ans++;
        }
    }
    cout << ans;
    return 0;
}
