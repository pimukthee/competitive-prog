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
vi prime;
bool p[1000005];
int main()
{

    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    for(int i=2; i<=b; i++)
    {
        if(!p[i])
        {
            if(i>=a)
            prime.pb(i);
            for(int j=i+i; j<=b; j+=i)
                p[j] = true;
        }
    }
    int ans = k>prime.size()?-1:max(b-prime[prime.size()-k]+1,prime[k-1]-a+1);
    for(int i=k; i<prime.size(); i++)
        ans = max(ans,prime[i]-prime[i-k]);
    printf("%d",ans);
    return 0;
}
