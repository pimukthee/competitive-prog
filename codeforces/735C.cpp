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
#define MAXN 1e18
using namespace std;
LL f[150];
int main()
{
    LL n,ans=0;
    cin >> n;
    f[0] = 1;
    f[1] = 2;
    for(int i=2; ; i++)
    {
        f[i]=f[i-1]+f[i-2];
        if(n < f[i])
        {
            cout << i-1;
            return 0;
        }
    }

    return 0;
}
