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
int d[1000005];
int main()
{
    int a,b,c;
    long long ans = 0;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1; i<=1000000; i++)
        for(int j=i; j<=1000000; j+=i)
            d[j]++;
    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            for(int k=1; k<=c; k++)
                ans = (ans+d[i*j*k])%1073741824;
    printf("%I64d",ans);
    return 0;
}
