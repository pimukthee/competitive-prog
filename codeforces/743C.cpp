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
    int n;
    cin >> n;
    if(n==1) cout << "-1";
    else
    cout << n << " " << n+1 << " " << n*(n+1);
    return 0;
}
