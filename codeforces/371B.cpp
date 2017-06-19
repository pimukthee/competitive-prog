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
int ans;
void update(int &a,int val)
{
    a/=val;
    ans ++;
}
void findfac(int &i)
{
    while(i%2==0)  update(i,2);
    while(i%3==0)  update(i,3);
    while(i%5==0)  update(i,5);
}
int main()
{
    int a,b;
    cin >> a >> b;
    int k = __gcd(a,b);
    a/=k;
    b/=k;
    findfac(a);
    findfac(b);
    if (a==1 && b==1) cout << ans ;
    else cout << -1;
    return 0;
}
