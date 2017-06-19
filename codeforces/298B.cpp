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
    char c;
    int t,sx,sy,ex,ey,s=0,n=0,e=0,w=0;
    scanf("%d%d%d%d%d",&t,&sx,&sy,&ex,&ey);
    if(ex>sx)  e = ex-sx;
    else w = sx-ex;
    if(ey>sy) n = ey-sy;
    else s = sy - ey;
    for(int i=1; i<=t; i++)
    {
        scanf(" %c",&c);
        if(c=='S' && s > 0)
            s--;
        else if(c=='N' && n > 0)
            n--;
        else if(c=='E' && e > 0)
            e--;
        else if(c=='W' && w > 0)
            w--;
        if(s+n+e+w == 0)
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
