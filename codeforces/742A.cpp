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
    if(n==0) cout << 1;
    else if(n%4==1) cout << 8;
    else if(n%4==2) cout << 4;
    else if(n%4==3) cout << 2;
    else if(n%4==0) cout << 6;
    return 0;
}
