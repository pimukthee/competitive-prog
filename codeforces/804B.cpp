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
    string n;
    long long mod = 1e9+7;
    long long ans = 0, k = 1;

    cin >> n;
    for(auto i : n)
    {
        if(i == 'a') k = (k << 1) % mod;
        else ans = (ans + k + mod - 1) % mod;
    }
    cout << (ans + mod) % mod;

    return 0;
}
