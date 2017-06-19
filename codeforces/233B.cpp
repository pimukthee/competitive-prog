#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define sqr(x) x*x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int,int>
using namespace std;
LL n;
int s(LL x)
{
    int sum = 0;
    while(x>0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
LL check(LL x,int SX)
{
    int sx = s(x);
    LL ans = sqr(x)+1ll*SX*x-n;
    //cout << x*x+sx*x-n <<endl;
    if(ans == 0)
    {
        //cout << ans << endl;
        if(sx == SX)
            return 0;
        return 1;
    }
    return ans;
}
int main()
{
    LL ans=-1;
    cin >> n;
    for(int i=1; i<=90; i++)
    {
        LL l = 1,r=1e9;
        while(l<=r)
        {
            LL x = (l+r)/2;
            //cout << x << endl;
            LL eq = check(x,i);
            if(eq>=0)
            {
                if(eq==0) ans = x;
                r = x-1;
            }
            else
                l = x+1;
        }
    }
    cout << ans;
    return 0;
}
