#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <sstream>
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
vi a;
bool dp[300];
int main()
{
    int T;
    scanf("%d ",&T);
    while(T--)
    {
        string allint;
        getline(cin,allint);
        istringstream is(allint);
        int b,sum=0;
        while(is>>b)
        {
            a.pb(b);
            sum+=b;
        }
        for(int i=0; i<=210; i++)
            dp[i] = false;
        dp[0] = 1;
        int half = sum/2;
        for(int i: a)
        {
            for(int j=half; j>=i; j--)
                dp[j] |= dp[j-i];
        }

        if(dp[half] && half+half == sum)
            printf("YES\n");
        else
            printf("NO\n");
        a.clear();
    }

    return 0;
}
