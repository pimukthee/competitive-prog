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
LL arr[2005],ans;
int main()
{
    int n,d,round = 0;
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&arr[i]);
        if(arr[i]<=arr[i-1])
        {
            round = (arr[i-1]-arr[i])/d +1;
            if(round == 0) round = 1;
            ans += 1ll*round;
            arr[i]+= 1ll*round*d;
        }
       //printf("%I64d ",arr[i]);
    }
    printf("%I64d",ans);
    return 0;
}
