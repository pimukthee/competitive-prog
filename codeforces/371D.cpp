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
#define MAXN 200005
using namespace std;
int a[MAXN],ves[MAXN],head[MAXN];
int findhead(int x)
{
    if(head[x] == x) return x;
    return head[x] = findhead(head[x]);
}
int main()
{
    int n,m,com,x,p;
    for(int i=1; i<=MAXN; i++)
        head[i] = i;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&com,&x);
        if(com==2)
            printf("%d\n",ves[x]);
        else
        {
            scanf("%d",&p);
            x = findhead(x);
            //printf("x = %d\n",x);
            while(x<=n && p > 0)
            {
                int pour = min(a[x]-ves[x],p);
                ves[x] += pour;
                p -= pour;
                if(ves[x] == a[x])
                    head[x] = x+1;
                x++;
            }
            /*for(int i=1; i<=n; i++)
                printf("%d ",ves[i]);
            printf("\n");*/
        }
    }
    return 0;
}
