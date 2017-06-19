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
vi fac;
void findfac(int k)
{
    int i;
    for(i=1; i*i<k; i++)
    {
        if(k%i==0)
        {
            fac.pb(i);
            fac.pb(k/i);
        }
    }
    if(i*i==k)
        fac.pb(i);
}
int main()
{
    int a,b,ans,n,low,high;
    scanf("%d%d%d",&a,&b,&n);
    int g = __gcd(a,b);
    findfac(g);
   // cout << g << endl;
    sort(fac.begin(),fac.end());
    while(n--)
    {
        ans = -1;
        scanf("%d%d",&low,&high);
        for(int i=fac.size()-1; i>=0&&ans==-1; i--)
            if(fac[i]>=low && fac[i] <= high)
                ans = fac[i];
        printf("%d\n",ans);
    }
    return 0;
}
