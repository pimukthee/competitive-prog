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
    int n,k;
    LL ans=0,sum=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        if(k) sum++;
        else ans+=sum;
    }
    printf("%I64d",ans);
    return 0;
}
