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
vi prime,ans;
bool p[100005];
int a[100005];
int main()
{
    for(int i=2; i<=100000; i++)
    {
        if(!p[i])
        {
            prime.pb(i);
            for(int j=i+i; j<=100000; j+=i)
                p[j] = true;
        }
    }
    int n,k=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    ans.pb(a[0]);
    for(int i=1; i<n; i++)
    {
        if(__gcd(a[i],a[i-1])!=1)
        {
            for(int j: prime)
            {
                if(__gcd(j,a[i])==1 && __gcd(j,a[i-1])==1)
                {
                    ans.pb(j);
                    k++;
                    break;
                }
            }
        }
        ans.pb(a[i]);
    }
    printf("%d\n",k);
    for(int i: ans)
        printf("%d ",i);
    return 0;
}
