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
int n,c[200005],d[200005];
int check(int x)
{
    for(int i=n-1; i>=0; i--)
    {
        x-=c[i];
        if(d[i]==2 && x>1899)
            return 1;
        else if(d[i]==1 && x<1900)
            return -1;
    }
    return 0;
}
int main()
{
    int l=-50000000,r=50000000 ,ans = -1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d",&c[i],&d[i]);
    while(l<=r)
    {
        int mid = (l+r)/2;
        int st = check(mid);

        if(st == 0 || st ==-1)
        {
            l = mid+1;
            if(st == 0)
                ans = mid;
        }
        else
            r = mid -1;
    }
    if(ans == -1)
        printf("Impossible");
    else if(ans == 50000000)
        printf("Infinity");
    else
        printf("%d",ans);
    return 0;
}
