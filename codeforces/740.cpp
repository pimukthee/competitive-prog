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
    LL n,a,b,c;
    cin >> n >> a >> b >> c;
    if(n%4==0)
        cout << 0;
    else if(n%4==1)
        cout << min(3*a,min(a+b,c));
    else if(n%4==2)
        cout << min(2*a,min(b,2*c));
    else
        cout << min(a,min(3*c,b+c));
    return 0;
}
