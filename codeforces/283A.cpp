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
double arr[100005],s=1,add[100005];
int main()
{
    int n,a,x,t;
    LL k,prevSub = 0,sum=0,sub = 0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        if(t == 1)
        {
            scanf("%d%d",&a,&x);
            add[a]+=x;
        }
        else if(t==2)
        {
            scanf("%I64d",&k);
            arr[s+1] = k + arr[s];
            s++;
        }
        else
        {
            arr[s] = 0;
            if(add[s] != 0)
                prevSub = add[s];
            sub += prevSub;
            s--;
            sum -= sub;
        }
        printf("%.6lf",1.0*arr[s]);
    }
    return 0;
}
