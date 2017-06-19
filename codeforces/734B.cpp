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
    int k2,k3,k5,k6,a,b;
    LL sum=0;
    cin >> k2 >> k3 >> k5 >> k6;
    a= min(k2,min(k5,k6));
    sum += 256ll*a;
    k2-=a;
    sum += 32ll*min(k2,k3);
    cout << sum;
    return 0;
}
