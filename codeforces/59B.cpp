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
int main()
{
    int n,modd=1000000000,k,ans =0;
    cin >> n;
    while(n--)
    {
        cin >> k;
        ans+=k;
        if(k&1)
            modd = min(modd,k);
    }
    if(!(ans&1))
        ans-=modd;
    if(!(ans&1))
        ans = 0;
    cout << ans;
    return 0;
}
