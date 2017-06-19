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
LL lcm(LL a, LL b)
{
    return (a*b)/__gcd(a,b);
}
int main()
{
    LL n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;
    cout << n/a*p+n/b*q-n/lcm(a,b)*min(p,q);
    return 0;
}
