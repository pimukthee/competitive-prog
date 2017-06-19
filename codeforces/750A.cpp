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
    int n,k,t = 0,ans=0;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        if(t+5*i+k<=240)
        {
            t += 5*i;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
