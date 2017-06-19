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
int scoref,scores,n,m;
LL a[200005],b[200005];
int cal(LL d)
{
    scoref = scores = 0;
    for(int i=0; i<n; i++)
    {
        scoref += 2;
        if(a[i]>d)
            scoref++;
    }
    for(int i=0; i<m; i++)
    {
        scores += 2;
        if(b[i]>d)
            scores++;
    }
}
int main()
{
    int f,s,ans=-1000000000;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=0; i<m; i++)
        scanf("%d",&b[i]);
    LL l = 0,r=3000000000;
    while(l<=r)
    {
        LL mid = (l+r)/2;
        cal(0);
        printf("%d:%d\n",scoref,scores);
        if(scoref-scores >= ans)
        {
            ans = scoref - scores;
            f = scoref;
            s = scores;
            l = mid+1;
        }
        else
            r = mid - 1;
    }
    printf("%d:%d",f,s);
    return 0;
}
