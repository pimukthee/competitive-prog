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
int mod;
long long p(long long n,long long k){
    long long d=1;
    while(k){
        if(k&1)
            d=(d*n)%mod;
        n=(n*n)%mod;
      k>>=1;
    }
    return d;
}
int main()
{
    int j,ans=0;
    cin >> mod;
    for(int i=1; i<mod; i++)
    {
        for(j=2; j<mod; j++)
        {
            if((p(i,j-1)-1+mod)%mod==0)
                break;
        }
        if(j==mod)
            ans ++;
    }
    cout << ans;
    return 0;
}
