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
vi prime;
bool p[1005];
int check(int n)
{
    for(int i=1; i<prime.size(); i++)
    {
        if(prime[i]+prime[i-1]==n){
            printf("%d = %d + %d + 1\n",n+1,prime[i],prime[i-1]);
            return 1;
        }
    }
    return 0;
}
int main()
{
    int a,b;
    for(int i=2; i<=1000; i++)
    {
        if(!p[i])
        {
            prime.pb(i);
            for(int j=i+i; j<=1000; j+=i)
                p[j]=true;
        }
    }
    int ans =0;
    cin >> a >> b;
    for(int i:prime)
    {
        if(i<=a)
            ans+=check(i-1);
    }
    cout << ((ans>=b)?"YES":"NO");
    return 0;
}
