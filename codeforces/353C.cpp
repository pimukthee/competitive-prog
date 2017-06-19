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
int a[100005],sum[100005];
char m[100005];
int main()
{
    int n,temp=0,ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }

    scanf(" %s",m+1);
    for(int i=n; i>=1; i--)
    {
        if(m[i]=='1')
        {
            ans = max(temp+sum[i-1],ans);
            temp += a[i];

        }
    }
    printf("%d",max(ans,temp));
    return 0;
}
