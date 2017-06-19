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
int d[3005];
int main()
{
    for(int i=2; i<=3000; i++)
    {
        if(d[i]==0)
        {
            for(int j=i+i; j<=3000; j+=i)
                d[j]++;
        }
    }
    int n,ans=0;
    cin >> n;
    for(int i=1; i<=n; i++)
        ans+=(d[i]==2);
    cout << ans;
    return 0;
}
