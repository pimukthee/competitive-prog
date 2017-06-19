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
int f[100005];
int main()
{
    f[1] = 1;
    for(int i=2; ; i++)
    {
        f[i] = f[i-1] + f[i-2];
        if(f[i]>1000000000)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
