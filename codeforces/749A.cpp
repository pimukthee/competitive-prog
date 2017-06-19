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
bool isPrime(int n)
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return false;
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",n>>1);
    if(n&1)
    {
        printf("3 ");
        n-=3;
    }
    while(n>0)
    {
        printf("2 ");
        n-=2;
    }
    return 0;
}
